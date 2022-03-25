#ifndef H_BTTP_TRANSACTION_OUVERTURE_NON_AUTORISEE
#define H_BTTP_TRANSACTION_OUVERTURE_NON_AUTORISEE

#include "Ouverture.h"

#define BTTP_TRANSACTION_OUVERTURE_NON_AUTORISEE_CODE -306
#define BTTP_TRANSACTION_OUVERTURE_NON_AUTORISEE_MSG "Vous n'êtes pas autorisé à ouvrir une transaction sur cet appareil."

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Transactions
            {
                /**
                 * @brief Erreur survenant lorsque l'ouverture d'une transaction est refusée car la clé publiqe n'est pas
                 * autorisée sur le terminal distant.
                 */
                class OuvertureNonAutorisee : public Ouverture
                {
                public:
                    OuvertureNonAutorisee(const Protocole::Messages::IMessage* message)
                        : Ouverture("NonAutorisee", BTTP_TRANSACTION_OUVERTURE_NON_AUTORISEE_MSG, BTTP_TRANSACTION_OUVERTURE_NON_AUTORISEE_CODE, message)
                    {}
                };
            }
        }
    }
}
#endif