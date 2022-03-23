#include "../../include/transaction/Controle.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            void Controle::ouverture(const std::string& mdp)
            {
                if (!this->_connexion_distant->ouverte()) this->_connexion_distant->ouvrir();
                // On relait le message d'ouverture au terminal distant.
                if (this->relayer_a_distant(mdp))
                // Et on transmet sa réponse au client.
                    if (this->relayer_a_client(mdp)) return;
                // Si un des relais échoue, on lève une erreur.
                throw new Erreur::Transaction::Ouverture(nullptr);
            }

            void Controle::fermeture(const std::string& mdp)
            {
                // On relait les potentiels derniers messages reçus
                this->relayer_a_distant(mdp);
                this->relayer_a_client(mdp);
            }
        
            Controle::Controle(
                const Identite* identite, const std::string& message_ouverture,
                const Cle::Publique& client, IConnexion* connexion_client, 
                const Cle::Publique& distant, IConnexion* connexion_distant
            )
                : _Transaction(connexion_client, identite), _client{ client }, 
                _distant{ distant }, _connexion_distant{ connexion_distant },
                _message_a_relayer_a_distant{ message_ouverture }, _message_a_relayer_a_client{ "" }
            {}

            const bool Controle::prochain_message(std::string& var, IConnexion* connexion)
            {
                var = connexion->recevoir();
                return var != BTTP_TRANSACTION_MESSAGE_NUL;
            }

            const std::string Controle::lire_entete(const std::string& message, const Cle::Publique& signataire, const std::string& mdp) const
            { 
                if (message == BTTP_TRANSACTION_MESSAGE_NUL) return message;
                return this->identite().dechiffrer(extraire_entete(message), signataire, mdp);
            }

            const bool Controle::relayer(const Cle::Publique& destinataire, IConnexion* connexion, std::string& message, const std::string mdp)
            { 
                if (message != BTTP_TRANSACTION_MESSAGE_NUL)
                {
                    const std::string entete = this->identite().chiffrer(this->generer_entete(), destinataire, mdp);
                    const std::string nouveau_message = entete + BTTP_MESSAGE_CONTROLE_SEP + retirer_entete(message);
                    connexion->envoyer(nouveau_message);
                    message = BTTP_TRANSACTION_MESSAGE_NUL;
                    return true;
                }
                return false;
            }
        }
    }
}