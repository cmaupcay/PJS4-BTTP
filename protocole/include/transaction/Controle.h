#ifndef H_BTTP_TRANSACTION_CONTROLE
#define H_BTTP_TRANSACTION_CONTROLE

#include "Transaction.h"

#define BTTP_TRANSACTION_MESSAGE_NUL ""

#include "erreur/Ouverture.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            // TOCOMMENT
            class Controle : public _Transaction
            {
            private:
                const Cle::Publique& _client;
                const Cle::Publique& _distant;
                IConnexion& _connexion_distant;
                std::string _message_a_relayer_a_client;
                std::string _message_a_relayer_a_distant;

                /** Méthode supprimée.. */
                const std::string preparer(const Messages::IMessage& message, const std::string& mdp) const override 
                { return BTTP_TRANSACTION_MESSAGE_NUL; }
                /** Méthode supprimée.. */
                inline const Messages::IMessage* resoudre(const std::string& message, const std::string& mdp) override 
                { return nullptr; }
                /** Méthode supprimée.. */
                void envoyer(const Messages::IMessage& message, const std::string mdp) override {}
                /** Méthode supprimée.. */
                const Messages::IMessage* recevoir(const std::string mdp) override 
                { return nullptr; }

                // TOTEST
                void ouverture(const std::string& mdp) override;
                // TOTEST
                void fermeture(const std::string& mdp) override;

                // TOTEST
                const std::string lire_entete(
                    const std::string& message, const Cle::Publique& signataire,
                    const std::string& mdp
                ) const;
                // TOTEST
                static const bool relayer(IConnexion& connexion, std::string& message);

            public:
                Controle(
                    const Identite& identite, const std::string& message_ouverture,
                    const Cle::Publique& client, IConnexion& connexion_client, const Cle::Publique& distant, IConnexion& connexion_distant
                );

                inline static const std::string extraire_entete(const std::string message)
                { return message.substr(0, message.find_last_of(BTTP_MESSAGE_CONTROLE_SEP)); }
                inline static const std::string retirer_entete(const std::string message)
                { return message.substr(message.find_last_of(BTTP_MESSAGE_CONTROLE_SEP) + 1); }

                inline const std::string lire_entete_client(const std::string mdp) const
                { return lire_entete(this->_message_a_relayer_a_distant, this->_client, mdp); }
                inline const bool relayer_a_distant(const bool lire = true);

                inline const std::string lire_entete_distant(const std::string mdp) const
                { return lire_entete(this->_message_a_relayer_a_client, this->_distant, mdp); }
                inline const bool relayer_a_client(const bool lire = true);

            };
        }
    }
}

#endif