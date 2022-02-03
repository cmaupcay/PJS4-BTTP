#ifndef H_BTTP_MESSAGES_CLE_PUBLIQUE_VIDE
#define H_BTTP_MESSAGES_CLE_PUBLIQUE_VIDE

#include "../../Erreur.h"

#ifndef BTTP_MESSAGES_CLE_PUBLIQUE_VIDE_CODE
    #define BTTP_MESSAGES_CLE_PUBLIQUE_VIDE_CODE -100
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            class ClePublique_Vide : public Erreur
            {
            public:
                ClePublique_Vide()
                    : Erreur("Messages/ClePublique/Vide", "Le message ne contient pas de clé publique.", BTTP_MESSAGES_CLE_PUBLIQUE_VIDE_CODE)
                {}
            };
        }
    }
}
#endif