#ifndef H_BTTP_IDENTITE_EXPORTATION
#define H_BTTP_IDENTITE_EXPORTATION

#include "../../Erreur.h"

#ifndef BTTP_IDENTITE_EXPORTATION_CODE
    #define BTTP_IDENTITE_EXPORTATION_CODE -211
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Identite
            {
                class Exportation : public Erreur
                {
                public:
                    Exportation(const std::string& fichier)
                        : Erreur(
                            "Identite/Exportation", "L'exportation de la clé privée dans le fichier '" + fichier + "' a échoué.",
                            BTTP_IDENTITE_EXPORTATION_CODE
                        ) {}
                };
            }
        }
    }
}
#endif