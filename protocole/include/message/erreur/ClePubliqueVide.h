#ifndef H_BTTP_MESSAGES_CLE_PUBLIQUE_VIDE
#define H_BTTP_MESSAGES_CLE_PUBLIQUE_VIDE

#include "../../Erreur.h"

#ifndef BTTP_MESSAGES_CLE_PUBLIQUE_VIDE_CODE
    #define BTTP_MESSAGES_CLE_PUBLIQUE_VIDE_CODE -200
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Messages
            {
                namespace ClePublique
                {
                    // TOCOMMENT
                    class Vide : public Erreur
                    {
                    public:
                        Vide()
                            : Erreur("Messages/ClePublique/Vide", "Le message ne contient pas de clé publique.", BTTP_MESSAGES_CLE_PUBLIQUE_VIDE_CODE)
                        {}
                    };
                }
            }
        }
    }
}
#endif