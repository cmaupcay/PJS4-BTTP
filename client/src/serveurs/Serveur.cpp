#include "../../include/serveurs/Serveur.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            Serveur::Serveur(const std::string nom, const std::string serialisation)
                : _nom{ nom }, _cle{ nullptr }, _connexion{ nullptr }, _auth{ false }
            {
                const size_t fin_premiere_ligne = serialisation.find_first_of('\n');
                const size_t fin_deuxieme_ligne = serialisation.find_first_of('\n', fin_premiere_ligne + 1);
                // Adresse sur la première ligne.
                this->_adresse = serialisation.substr(0, fin_premiere_ligne);
                // Port sur la deuxième ligne.
                this->_port = (uint16_t)std::atoi(serialisation.substr(fin_premiere_ligne + 1, fin_deuxieme_ligne - (fin_premiere_ligne + 1)).c_str());
                // Reste du fichier = clé publique.
                this->_cle = new Protocole::Cle::Publique(serialisation.substr(fin_deuxieme_ligne + 1));
                this->_connexion = new Connexion(this->_adresse, this->_port);
            }

            const std::string Serveur::serialiser() const
            {
                std::string infos = this->_adresse;
                infos += "\n" + std::to_string(this->_port);
                infos += "\n" + this->_cle->write(BTTP_IDENTITE_ARMOR ? OpenPGP::PGP::Armored::YES : OpenPGP::PGP::Armored::NO);
                return infos;
            }

            const bool Serveur::authentification(
                const Protocole::Identite& identite, const std::string mdp,
                const std::string utilisateur, const std::string mdp_utilisateur
            )
            {
                // Si la clé du serveur est inconnue ou que l'appareil est déjà authentifié, on arrête là.
                if (this->_cle == nullptr || this->_auth) return false;
                // Réception de la demande du nom d'utilisateur.
                Protocole::Messages::Demande demande{
                    identite.dechiffrer(this->_connexion->recevoir(), *this->_cle ,mdp)
                };
                if (demande.champs() == BTTP_DEMANDE_UTILISATEUR)
                {
                    // Envoi de la réponse contenant l'empreinte de la clé.
                    const Messages::ReponseUtilisateur reponse{ utilisateur };
                    this->_connexion->envoyer(
                        identite.chiffrer(reponse.construire(), *this->_cle, mdp)
                    );
                    std::string confirmation = identite.dechiffrer(
                        this->_connexion->recevoir(), *this->_cle, mdp
                    );
                    if (confirmation[0] == static_cast<char>(Protocole::Messages::Type::PRET))
                    {
                        // Réception de la demande de mot de passe.
                        demande.deconstruire(
                            identite.dechiffrer(this->_connexion->recevoir(), *this->_cle ,mdp)
                        );
                        if (demande.champs() == BTTP_DEMANDE_MOT_DE_PASSE 
                        && Messages::DemandeMotDePasse::extraire_utilisateur(&demande) == utilisateur)
                        {
                            // Envoi de la réponse contenant le mot de passe de l'utilisateur.
                            const Messages::ReponseMotDePasse reponse_mdp{ mdp_utilisateur };
                            this->_connexion->envoyer(
                                identite.chiffrer(reponse_mdp.construire(), *this->_cle, mdp)
                            );
                            // Réception de la confirmation.
                            confirmation = identite.dechiffrer(
                                this->_connexion->recevoir(), *this->_cle, mdp
                            );
                            if (confirmation[0] == static_cast<char>(Protocole::Messages::Type::PRET))
                            {
                                this->_auth = true;
                                return true;
                            }
                        }
                    }
                }
                return false;
            }

            const bool Serveur::authentification(const Protocole::Identite& identite, const std::string mdp)
            {
                // Si la clé du serveur est inconnue ou que l'appareil est déjà authentifié, on arrête là.
                if (this->_cle == nullptr || this->_auth) return false;
                // Réception de la demande de l'empreinte de la clé publique locale.
                const Protocole::Messages::Demande demande{
                    identite.dechiffrer(this->_connexion->recevoir(), *this->_cle ,mdp)
                };
                if (demande.champs() == BTTP_DEMANDE_EMPREINTE_CLE)
                {
                    // Envoi de la réponse contenant l'empreinte de la clé.
                    const Messages::ReponseEmpreinteCle reponse{ identite.cle_publique() };
                    this->_connexion->envoyer(
                        identite.chiffrer(reponse.construire(), *this->_cle, mdp)
                    );
                    // Réception de la confirmation.
                    const std::string confirmation = identite.dechiffrer(
                        this->_connexion->recevoir(), *this->_cle, mdp
                    );
                    if (confirmation[0] == static_cast<char>(Protocole::Messages::Type::PRET))
                    {
                        this->_auth = true;
                        return true;
                    }
                }
                return false;
            }
        }
    }
}