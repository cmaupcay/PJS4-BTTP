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
                static const bool relayer(IConnexion& connexion, const std::string entete, std::string& message);

            protected:
                virtual const std::string generer_entete(const Cle::Publique& destinataire);

            public:
                // TOTEST
                Controle(
                    const Identite& identite, const std::string& message_ouverture,
                    const Cle::Publique& client, IConnexion& connexion_client, const Cle::Publique& distant, IConnexion& connexion_distant
                );

                // TOTEST
                inline const bool prochain_message_client();
                inline const std::string lire_entete_client(const std::string mdp) const
                { return lire_entete(this->_message_a_relayer_a_distant, this->_client, mdp); }
                // TOTEST
                inline const bool relayer_a_distant(const std::string mdp, const bool lire = true);

                // TOTEST
                inline const bool prochain_message_distant();
                inline const std::string lire_entete_distant(const std::string mdp) const
                { return lire_entete(this->_message_a_relayer_a_client, this->_distant, mdp); }
                // TOTEST
                inline const bool relayer_a_client(const std::string mdp, const bool lire = true);

            };
        }
    }
}

#endif