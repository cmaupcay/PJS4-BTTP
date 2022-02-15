#include "../../include/transaction/Controle.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            void Controle::ouverture(const std::string& mdp)
            {
                if (!this->_connexion_distant.ouverte()) this->_connexion_distant.ouvrir();
                const bool client = this->relayer_a_distant(mdp, false); // On relait le message d'ouverture au terminal distant
                if (client && this->relayer_a_client(mdp, true)) return; // On relait la réponse au terminal client
                throw Erreur::Transaction::Ouverture(!client); 
            }

            void Controle::fermeture(const std::string& mdp)
            {
                // On relait les potentiels derniers messages reçus
                this->relayer_a_distant(mdp, false);
                this->relayer_a_client(mdp, false);
                this->_connexion_distant.fermer();
            }
        
            Controle::Controle(
                const Identite& identite, const std::string& message_ouverture,
                const Cle::Publique& client, IConnexion& connexion_client, const Cle::Publique& distant, IConnexion& connexion_distant
            )
                : _Transaction(Mode::CONTROLE, connexion_client, identite), _client{ client }, _distant{ distant }, _connexion_distant{ connexion_distant },
                _message_a_relayer_a_distant{ message_ouverture }, _message_a_relayer_a_client{ "" }
            {}

            const bool Controle::prochain_message_client()
            {
                this->_message_a_relayer_a_distant = this->connexion().recevoir();
                return this->_message_a_relayer_a_distant != BTTP_TRANSACTION_MESSAGE_NUL;
            }
            const bool Controle::prochain_message_distant()
            {
                this->_message_a_relayer_a_client = this->_connexion_distant.recevoir();
                return this->_message_a_relayer_a_client != BTTP_TRANSACTION_MESSAGE_NUL;
            }

            const std::string Controle::lire_entete(const std::string& message, const Cle::Publique& signataire, const std::string& mdp) const
            { 
                if (message == BTTP_TRANSACTION_MESSAGE_NUL) return message;
                return this->identite().dechiffrer(extraire_entete(message), signataire, mdp);
            }

            const bool Controle::relayer(IConnexion& connexion, const std::string entete, std::string& message)
            { 
                if (message != BTTP_TRANSACTION_MESSAGE_NUL)
                {
                    const std::string nouveau_message = entete + BTTP_MESSAGE_CONTROLE_SEP + retirer_entete(message);
                    connexion.envoyer(nouveau_message);
                    message = BTTP_TRANSACTION_MESSAGE_NUL;
                    return true;
                }
                return false;
            }
            
            const bool Controle::relayer_a_client(const std::string mdp, const bool lire)
            {
                if (lire) if (!this->prochain_message_distant()) return false;
                const std::string entete = this->identite().chiffrer(generer_entete(this->_client), this->_client, mdp);
                return relayer(this->connexion(), entete, this->_message_a_relayer_a_client);
            }
            const bool Controle::relayer_a_distant(const std::string mdp, const bool lire)
            {
                if (lire) if (!this->prochain_message_client()) return false;
                const std::string entete = this->identite().chiffrer(generer_entete(this->_distant), this->_distant, mdp);
                return relayer(this->_connexion_distant, entete, this->_message_a_relayer_a_distant);
            }
        }
    }
}