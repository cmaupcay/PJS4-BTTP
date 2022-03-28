#ifndef H_BTTP_TRANSACTION_OUVERTURE
#define H_BTTP_TRANSACTION_OUVERTURE

#include "../../messages/Message.h"

#define BTTP_TRANSACTION_OUVERTURE_CODE -303
#define BTTP_TRANSACTION_OUVERTURE_MSG "L'ouverture de la transaction a échoué."

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Transactions
            {
                /**
                 * @brief Erreur survenant lorsque l'ouverture d'une transaction a mené à une erreur.
                 */
                class Ouverture : public Erreur
                {
                private:
                    /**
                     * @brief Message associé à l'erreur.
                     */
                    const Protocole::Messages::IMessage* _message;

                protected:
                    Ouverture(const std::string nom, const std::string details, const int code, const Protocole::Messages::IMessage* message)
                        : Erreur("Transaction/Ouverture" + nom, BTTP_TRANSACTION_OUVERTURE_MSG + details, code),
                        _message{ message }
                    {}

                public:
                    Ouverture(const Protocole::Messages::IMessage* message)
                        : Erreur("Transaction/Ouverture", BTTP_TRANSACTION_OUVERTURE_MSG, BTTP_TRANSACTION_OUVERTURE_CODE),
                        _message{ message }
                    {}

                    /**
                     * @brief Retourne le message associé à l'erreur d'ouverture.
                     * @return const Protocole::Messages::IMessage& Message associé.
                     */
                    inline const Protocole::Messages::IMessage* message() const { return this->_message; }
                };
            }
        }
    }
}
#endif