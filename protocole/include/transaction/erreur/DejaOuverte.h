#ifndef H_BTTP_TRANSACTION_DEJA_OUVERTE
#define H_BTTP_TRANSACTION_DEJA_OUVERTE

#include "../../erreur/Erreur.h"

#define BTTP_TRANSACTION_DEJA_OUVERTE_CODE -301

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Transaction
            {
                /**
                 * @brief Erreur survenant lorsqu'une transaction ouverte a tenté d'être ouverte à nouveau.
                 */
                class DejaOuverte : public Erreur
                {
                public:
                    DejaOuverte()
                        : Erreur("Transaction/DejaOuverte", "La transaction a déjà été ouverte.", BTTP_TRANSACTION_DEJA_OUVERTE_CODE)
                    {}
                };
            }
        }
    }
}
#endif