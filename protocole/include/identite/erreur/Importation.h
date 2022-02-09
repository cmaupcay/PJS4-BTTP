#ifndef H_BTTP_IDENTITE_IMPORTATION
#define H_BTTP_IDENTITE_IMPORTATION

#include "../../erreur/Erreur.h"

#define BTTP_IDENTITE_IMPORTATION_CODE -212

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Identite
            {
                /**
                 * @brief Erreur d'importation d'une clé privée.
                 */
                class Importation : public Erreur
                {
                public:
                    /**
                     * @param details Details de l'erreur.
                     */
                    Importation(const std::string details)
                        : Erreur(
                            "Identite/Importation", "L'importation de la clé privée a échoué.\n\tDetails : '" + details,
                            BTTP_IDENTITE_IMPORTATION_CODE
                        ) {}
                };
            }
        }
    }
}
#endif