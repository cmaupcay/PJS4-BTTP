#ifndef H_BTTP_TRANSACTION_ENTETE_INVALIDE
#define H_BTTP_TRANSACTION_ENTETE_INVALIDE

#include "../../messages/Message.h"

#define BTTP_TRANSACTION_ENTETE_INVALIDE_CODE -305
#define BTTP_TRANSACTION_ENTETE_INVALIDE_MSG "L'entête du message est invalide."

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Transactions
            {
                /**
                 * @brief Erreur survenant lorsque la vérification d'une entête a échoué.
                 */
                class EnteteInvalide : public Erreur
                {
                private:
                    /**
                     * @brief Message associé à l'erreur.
                     */
                    const std::string& _entete;

                public:
                    EnteteInvalide(const std::string& entete)
                        : Erreur("Transaction/EnteteInvalide", BTTP_TRANSACTION_ENTETE_INVALIDE_MSG, BTTP_TRANSACTION_ENTETE_INVALIDE_CODE),
                        _entete{ entete }
                    {}

                    /**
                     * @brief Retourne l'entête associée à l'erreur.
                     * @return const Protocole::Messages::IMessage& Entête associée.
                     */
                    inline const std::string& entete() const { return this->_entete; }
                };
            }
        }
    }
}
#endif