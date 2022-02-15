#include "../../include/transaction/Client.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            const std::string Client::preparer(const Messages::IMessage& message, const std::string& mdp) const
            {
                // Génération du message de contrôle adapté au message passé en paramètre
                const std::string message_controle = (Messages::Controle::generer(message, this->_distant, this->identite(), mdp))->construire();
                // Chiffrement de l'entete du message
                return this->identite().chiffrer(extraire_entete(message_controle), this->_controleur, mdp)
                       + BTTP_MESSAGE_CONTROLE_SEP + retirer_entete(message_controle);
            }

            inline const Messages::IMessage* Client::resoudre(const std::string& message, const std::string& mdp)
            {
                // Déchiffrement du message reçu (le message de contrôle a été supprimé par le contrôleur)
                const std::string message_dechiffre = this->identite().dechiffrer(message, this->_distant, mdp);
                // Résolution de la classe du message
                return Messages::resoudre(message_dechiffre);
            }

            void Client::ouverture(const std::string& mdp)
            {
                // const Messages::Ouverture message{ this->_distant }; // TODO Il manque la classe de message Ouverture :(
                // this->envoyer(message, mdp);
                const Messages::IMessage* reponse = this->recevoir(mdp);
                if (reponse->type_c() != static_cast<char>(Messages::Type::OUVERTURE)) 
                    throw Erreur::Transaction::Refusee(reponse);
            }

            void Client::fermeture(const std::string& mdp)
            {
                // const Messages::Fermeture message; // TODO Il manque la classe de message Fermeture :(
                // this->envoyer(message, mdp);
            }
        
            Client::Client(const Mode mode, const Identite& identite, const Cle::Publique& distant, const Cle::Publique& controleur, IConnexion& connexion_controleur)
                : _Transaction(mode, connexion_controleur, identite), _distant{ distant }, _controleur{ controleur }
            {}

            Client::Client(const Identite& identite, const Cle::Publique& distant, const Cle::Publique& controleur, IConnexion& connexion_controleur)
                : _Transaction(Mode::CLIENT, connexion_controleur, identite), _distant{ distant }, _controleur{ controleur }
            {}
        }
    }
}