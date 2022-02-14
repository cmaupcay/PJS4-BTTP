#ifndef H_BTTP_TRANSACTION_CLIENT
#define H_BTTP_TRANSACTION_CLIENT

#include "Transaction.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            // TOCOMMENT
            class Client : public _Transaction
            {
            private:
                const Cle::Publique& _distant;
                const Cle::Publique& _controleur;

                // TOTEST
                const std::string preparer(const Messages::IMessage& message, const std::string& mdp) const override;
                // TOTEST
                const Messages::IMessage* resoudre(const std::string& message, const std::string& mdp) override;

            protected:
                // TOTEST
                Client(const Mode mode, const Identite& identite, const Cle::Publique& distant, const Cle::Publique& controleur, IConnexion& connexion_controleur);

                // TOTEST
                void ouverture(const std::string& mdp) override;
                // TOTEST
                void fermeture(const std::string& mdp) override;
            
            public:
                // TOTEST
                Client(const Identite& identite, const Cle::Publique& distant, const Cle::Publique& controleur, IConnexion& connexion_controleur);
            };
        }
    }
}

#endif