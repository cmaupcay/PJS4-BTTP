#ifndef H_BTTP_CLIENT_CLI_COMMANDE_EXECUTION_OUVERTURE_TRANSACTION
#define H_BTTP_CLIENT_CLI_COMMANDE_EXECUTION_OUVERTURE_TRANSACTION

#include "../../../Racine.h"

#define BTTP_CLIENT_CLI_COMMANDE_EXECUTION_OUVERTURE_TRANSACTION_CODE -111210

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Erreur
            {
                namespace Commandes
                {
                    namespace Execution
                    {
                        class OuvertureTransaction : public Erreur
                        {
                        private:
                            const Transactions::Client& _transaction;

                        public:
                            OuvertureTransaction(const Transactions::Client& transaction)
                                : Erreur(
                                    "Client/CLI/Commandes/Execution/OuvertureTransaction",
                                    "L'ouverture de la transaction a echoue"
                                    BTTP_CLIENT_CLI_COMMANDE_EXECUTION_OUVERTURE_TRANSACTION_CODE
                                ),
                                _transaction { transaction }
                            {}

                            inline const Transactions::Client& transaction() const { return this->_transaction; }
                        };
                    }
                }
            }
        }
    }
}
#endif