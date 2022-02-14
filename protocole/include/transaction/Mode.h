#ifndef H_BTTP_TRANSACTION_MODE
#define H_BTTP_TRANSACTION_MODE

#include "../Racine.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            // TOCOMMENT
            enum class Mode
            {
                CLIENT = 'w',       /** Envoie des scripts à exécuter */
                DISTANT = 'x',      /** Execute des scripts et envoie des résultats */
                CONTROLE = 'r'      /** Opère en tant que contrôleur de la transaction */
            };
        }
    }
}

#endif