#ifndef H_BTTP_IDENTITE_DECHIFFREMENT
#define H_BTTP_IDENTITE_DECHIFFREMENT

#include "../../Erreur.h"

#ifndef BTTP_IDENTITE_DECHIFFREMENT_CODE
    #define BTTP_IDENTITE_DECHIFFREMENT_CODE -202
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Identite
            {
                class Dechiffrement : public Erreur
                {
                public:
                    Dechiffrement(const std::string details)
                        : Erreur(
                            "Identite/Dechiffrement", "Le déchiffrement du message à donné un résultat invalide.\n\tDétails : " + details,
                            BTTP_IDENTITE_DECHIFFREMENT_CODE
                        ) {}
                };
            }
        }
    }
}
#endif