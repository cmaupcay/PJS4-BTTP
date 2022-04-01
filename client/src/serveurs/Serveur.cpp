#include "../../include/serveurs/Serveur.h"


namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            Serveur::Serveur(const std::string nom, const std::string serialisation, asio::io_context& contexte)
                : _nom{ nom }, _cle{ nullptr }, _connexion{ nullptr }, _auth{ false }
            {
                const size_t taille_sep = std::string(BTTP_MESSAGE_SEP).size();
                const size_t fin_adresse = serialisation.find_first_of(BTTP_MESSAGE_SEP);
                const size_t debut_port = fin_adresse + taille_sep;
                const size_t fin_port = serialisation.find_first_of(BTTP_MESSAGE_SEP, debut_port);
                const size_t debut_cle = fin_port + taille_sep;
                // Adresse sur la première ligne.
                this->_adresse = serialisation.substr(0, fin_adresse);
                // Port sur la deuxième ligne.
                this->_port = (uint16_t)std::atoi(serialisation.substr(debut_port, fin_port - debut_port).c_str());
                // Reste du fichier = clé publique.
                this->_cle = new Protocole::Cle::Publique(serialisation.substr(debut_cle));
                this->_connexion = new Connexion(this->_adresse, this->_port, contexte);
            }

            const std::string Serveur::serialiser() const
            {
                std::string infos = this->_adresse + BTTP_MESSAGE_SEP;
                infos += std::to_string(this->_port) + BTTP_MESSAGE_SEP;
                infos += this->_cle->exporter();
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
                    identite.dechiffrer(this->_connexion->recevoir(), *this->_cle, mdp)
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
                // Envoi de la demande d'authentification.
                Client::Serveurs::Messages::DemandeAuthentification demande_auth;
                this->_connexion->envoyer(
                    identite.chiffrer(demande_auth.construire(), *this->_cle, mdp)
                );
                // Réception de la demande de l'empreinte de la clé publique locale.
                const Protocole::Messages::Demande demande {this->connexion().recevoir()};
                if (demande.champs() == BTTP_DEMANDE_EMPREINTE_CLE)
                {
                    // Envoi de la réponse contenant l'empreinte de la clé.
                    const Messages::ReponseEmpreinteCle reponse{ identite.cle_publique() };
                    this->_connexion->envoyer(identite.chiffrer(reponse.construire(), *this->_cle, mdp));
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