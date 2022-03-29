#ifndef H_BTTP_CLIENT_TRANSACTIONS_HORODOTAGE
#define H_BTTP_CLIENT_TRANSACTIONS_HORODOTAGE

#define BTTP_CLIENT_TRANSACTIONS_HORODOTAGE_CODE -3000

#include "../../Racine.h"

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Transactions
            {
                class Horodotage : public Erreur
                {
                private:
                    const std::string _message;

                public:
                    Horodotage(const std::string message)
                        : Erreur("Client/Transactions/Horodotage", "Impossible de récupérer l'horodotage.", BTTP_CLIENT_TRANSACTIONS_HORODOTAGE_CODE),
                        _message{ message }
                    {}

                    inline const std::string& message() const { return this->_message; }
                };
            }
        }
    }
}
#endif