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
                // TOCOMMENT
                /**
                 * @brief Erreur d'exportation d'une clé privée.
                 */
                class Exportation : public Erreur
                {
                public:
                    /**
                     * @param details Details de l'erreur.
                     */
                    Exportation(const std::string details)
                        : Erreur(
                            "Identite/Exportation", "L'exportation de la clé privée a échoué.\n\tDetails : " + details,
                            BTTP_IDENTITE_EXPORTATION_CODE
                        ) {}
                };
            }
        }
    }
}
#endif