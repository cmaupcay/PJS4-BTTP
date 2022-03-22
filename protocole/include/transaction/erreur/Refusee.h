#ifndef H_BTTP_TRANSACTION_REFUSEE
#define H_BTTP_TRANSACTION_REFUSEE

#include "Ouverture.h"
#include "../../message/Message.h"

#define BTTP_TRANSACTION_REFUSEE_CODE -304

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Transaction
            {
                /**
                 * @brief Erreur survenant lorsqu'une transaction a été refusée par le terminal distant.
                 */
                class Refusee : public Ouverture
                {
                private:
                    /**
                     * @brief Message de refus de la transaction.
                     */
                    const Protocole::Messages::IMessage* _message;
                public:
                    Refusee(const Protocole::Messages::IMessage* message)
                        : Ouverture(
                            true, "Refusee", "L'ouverture de la transaction a été refusée par le terminal distant.",
                            BTTP_TRANSACTION_REFUSEE_CODE
                        ),
                        _message{ message }
                    {}

                    /**
                     * @brief Retourne le message spécifiant le refus de l'ouverture de la transaction.
                     * @return const Protocole::Messages::IMessage& Message de refus.
                     */
                    inline const Protocole::Messages::IMessage* message() const { return this->_message; }
                };
            }
        }
    }
}
#endif