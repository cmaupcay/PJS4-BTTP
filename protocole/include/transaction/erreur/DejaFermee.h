#ifndef H_BTTP_TRANSACTION_DEJA_FERMEE
#define H_BTTP_TRANSACTION_DEJA_FERMEE

#include "../../erreur/Erreur.h"

#define BTTP_TRANSACTION_DEJA_FERMEE_CODE -302

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Transaction
            {
                /**
                 * @brief Erreur survenant lorsqu'une transaction fermée a tenté d'être fermée.
                 */
                class DejaFermee : public Erreur
                {
                public:
                    DejaFermee()
                        : Erreur("Transaction/DejaFermee", "La transaction a déjà été fermée.", BTTP_TRANSACTION_DEJA_FERMEE_CODE)
                    {}
                };
            }
        }
    }
}
#endif