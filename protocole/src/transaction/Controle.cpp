#include "../../include/transaction/Controle.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            void Controle::ouverture(const std::string& mdp)
            {
                if (!this->_connexion_distant.ouvert()) this->_connexion_distant.ouvrir();
                if (this->relayer_a_distant(false)) // On relait le message d'ouverture au terminal distant
                    if (this->relayer_a_client(true)) return; // On relait la réponse au terminal client
                // throw Erreur::Transaction::OuvertureImpossible(); // TODO Classe d'erreur
            }

            void Controle::fermeture(const std::string& mdp)
            {
                // On relait les potentiels derniers messages reçus
                this->relayer_a_distant(false);
                this->relayer_a_client(false);
                this->_connexion_distant.fermer();
            }
        
            Controle::Controle(
                const Identite& identite, const std::string& message_ouverture,
                const Cle::Publique& client, IConnexion& connexion_client, const Cle::Publique& distant, IConnexion& connexion_distant
            )
                : _Transaction(Mode::CONTROLE, connexion_client, identite), _client{ client }, _distant{ distant }, _connexion_distant{ connexion_distant },
                _message_a_relayer_a_distant{ message_ouverture }, _message_a_relayer_a_client{ "" }
            {}

            const std::string Controle::lire_entete(const std::string& message, const Cle::Publique& signataire, const std::string& mdp) const
            { 
                if (message == BTTP_TRANSACTION_MESSAGE_NUL) return message;
                return this->identite().dechiffrer(message, signataire, mdp);
            }

            const bool Controle::relayer(IConnexion& connexion, std::string& message)
            { 
                if (message != BTTP_TRANSACTION_MESSAGE_NUL)
                {
                    connexion.envoyer(retirer_entete(message));
                    message = BTTP_TRANSACTION_MESSAGE_NUL;
                    return true;
                }
                return false;
            }
            const bool Controle::relayer_a_client(const bool lire)
            {
                if (lire) this->_message_a_relayer_a_distant = this->connexion().recevoir();
                return relayer(this->_connexion_distant, this->_message_a_relayer_a_distant);
            }
            const bool Controle::relayer_a_distant(const bool lire)
            {
                if (lire) this->_message_a_relayer_a_client = this->_connexion_distant.recevoir();
                return relayer(this->connexion(), this->_message_a_relayer_a_client);
            }
        }
    }
}