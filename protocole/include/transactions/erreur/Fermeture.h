#ifndef H_BTTP_TRANSACTION_FERMETURE
#define H_BTTP_TRANSACTION_FERMETURE

#include "../../messages/Message.h"

#define BTTP_TRANSACTION_FERMETURE_CODE -304
#define BTTP_TRANSACTION_FERMETURE_MSG "La fermeture de la transaction a entrainé une erreur."

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Transactions
            {
                /**
                 * @brief Erreur survenant lorsque la fermeture d'une transaction a mené à une erreur.
                 */
                class Fermeture : public Erreur
                {
                private:
                    /**
                     * @brief Message associé à l'erreur de fermeture de la transaction.
                     */
                    const Protocole::Messages::IMessage* _message;

                public:
                    Fermeture(const Protocole::Messages::IMessage* message)
                        : Erreur("Transaction/Fermeture", BTTP_TRANSACTION_FERMETURE_MSG, BTTP_TRANSACTION_FERMETURE_CODE),
                        _message{ message }
                    {}

                    /**
                     * @brief Retourne le message associé à l'erreur de fermeture.
                     * @return const Protocole::Messages::IMessage& Message associé.
                     */
                    inline const Protocole::Messages::IMessage* message() const { return this->_message; }
                };
            }
        }
    }
}
#endif