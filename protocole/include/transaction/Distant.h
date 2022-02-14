#ifndef H_BTTP_TRANSACTION_DISTANT
#define H_BTTP_TRANSACTION_DISTANT

#include "Client.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            // TOCOMMENT
            class Distant : public Client
            {
            private:
                // TOTEST
                void ouverture(const std::string& mdp) override;
            
            public:
                // TOTEST
                Distant(const Identite& identite, const Cle::Publique& client, const Cle::Publique& controleur, IConnexion& connexion_controleur);
            };
        }
    }
}

#endif