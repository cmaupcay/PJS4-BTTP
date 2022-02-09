#ifndef H_BTTP_IDENTITE_EXPORTATION
#define H_BTTP_IDENTITE_EXPORTATION

#include "../../erreur/Erreur.h"

#define BTTP_IDENTITE_EXPORTATION_CODE -211

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Identite
            {
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