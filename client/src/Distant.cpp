#include "../include/Distant.h"

namespace BTTP
{
    namespace Client
    {
        void Distant::annonce(const std::string mdp)
        {
            const Client::Transactions::Messages::DemandeDistant demande;
            this->_serveur.connexion().envoyer(
                this->_identite.chiffrer(demande.construire(), this->_serveur.cle(), mdp)
            );
            const std::string reponse = this->_identite.dechiffrer(
                this->_serveur.connexion().recevoir(), this->_serveur.cle(), mdp
            );
            const char type = reponse[0];
            if (type == static_cast<char>(Protocole::Messages::Type::ERREUR))
            {
                const Protocole::Messages::Erreur erreur{ reponse };
                throw BTTP::Erreur(erreur.nom(), erreur.message(), erreur.code());
            }
            else if (type != static_cast<char>(Protocole::Messages::Type::PRET))
                throw Protocole::Erreur::Messages::Type::Incoherent(type, reponse);
        }
        
        void Distant::processus(const std::string mdp)
        {
            this->_status = "Annoncement du mode distant au serveur...";
            this->annonce(mdp);
            std::string paquet, entete, contenu;
            while (this->_serveur.connexion().ouverte())
            {
                try
                {
                    this->_status = "En attente de l'ouverture d'une transaction...";
                    paquet = this->_serveur.connexion().recevoir();
                    this->_status = "Déchiffrement du message...";
                    entete = this->_identite.dechiffrer(
                        Protocole::Transactions::extraire_entete(paquet), this->_serveur.cle(), mdp
                    );
                    if (entete[0] == static_cast<char>(Protocole::Messages::Controle::Type::OUVERTURE)
                    &&  Transactions::verifier_entete_controle(entete))
                    {
                        this->_status = "Ouverture de la transaction...";
                        contenu = Protocole::Transactions::retirer_entete(paquet);
                        Transactions::Distant transaction{
                            this->_identite, contenu, this->_serveur, this->_cles_autorisees
                        };
                        transaction.ouvrir(mdp);
                        this->_status = "Lancement de la transaction...";
                        transaction.processus(mdp, this->_status);
                    }
                }
                catch (BTTP::Erreur& erreur)
                {
                    this->_status = "Une erreur est survenue.";
                    const Protocole::Messages::Erreur message_erreur{ erreur };
                    paquet = this->_identite.chiffrer(  
                        message_erreur.construire(), this->_serveur.cle(), mdp
                    );
                    this->_serveur.connexion().envoyer(paquet);
                }
            }
        }
    }
}