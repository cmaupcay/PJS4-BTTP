#ifndef H_BTTP_CLIENT_TRANSACTIONS_TIMESTAMP
#define H_BTTP_CLIENT_TRANSACTIONS_TIMESTAMP

#define BTTP_CLIENT_TRANSACTIONS_TIMESTAMP_CODE -3000

#include "../../Racine.h"

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Transactions
            {
                class Timestamp : public Erreur
                {
                private:
                    const std::string _message;

                public:
                    Timestamp(const std::string message)
                        : Erreur("Client/Transactions/Timestamp", "Impossible de récupérer le timestamp.", BTTP_CLIENT_TRANSACTIONS_TIMESTAMP_CODE),
                        _message{ message }
                    {}

                    inline const std::string& message() const { return this->_message; }
                };
            }
        }
    }
}
#endif