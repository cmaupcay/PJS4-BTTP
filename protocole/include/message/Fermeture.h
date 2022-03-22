#ifndef H_BTTP_MESSAGE_FERMETURE
#define H_BTTP_MESSAGE_FERMETURE

#include "Message.h"

#define BTTP_MESSAGE_FERMETURE_MESSAGE_DEFAUT "La transaction a été fermé."

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            /**
             * @brief Message indiquant la fermeture d'une transaction.
             */
            class Fermeture : public Message
            {
            private:
                /**
                 * @brief Message associé à la fermeture.
                 */
                std::string _message;

                /**
                 * @brief Retourne le contenu du message.
                 * @return const std::string Message associé.
                 */
                inline const std::string contenu() const override { return this->_message; }

                /**
                 * @brief Enregistrement du contenu d'un message similaire.
                 * @param contenu Message asocié.
                 */
                inline void deconstruction(const std::string contenu) override { this->_message = contenu; }

            protected:
                /**
                 * @brief Modification du message associé à la fermeture.
                 * @param message Message associé à la fermeture.
                 */
                inline const void modifier_message(const std::string message) { this->_message = message; }

            public:
                /**
                 * @brief Construction d'un nouveau message.
                 */
                Fermeture();
                /**
                 * @brief Construction d'un message, déconstruction d'un paquet et enregistrement du message associé.
                 * @param paquet Paquet à déconstruire.
                 */
                Fermeture(const std::string paquet);

                /**
                 * @brief Retourne le message associé à la fermeture de la transaction.
                 * @return const std::string& Message associé.
                 */
                inline const std::string& message() const { return this->_message; }
            };
        }
    }
}

#endif