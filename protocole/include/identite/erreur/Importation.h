#ifndef H_BTTP_IDENTITE_IMPORTATION
#define H_BTTP_IDENTITE_IMPORTATION

#include "../../Erreur.h"

#ifndef BTTP_IDENTITE_IMPORTATION_CODE
    #define BTTP_IDENTITE_IMPORTATION_CODE -212
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            class Identite_Importation : public Erreur
            {
            public:
                Identite_Importation(const std::string& fichier)
                    : Erreur(
                        "Identite/Importation", "L'importation de la clé privée depuis le fichier '" + fichier + "' a échoué.",
                        BTTP_IDENTITE_IMPORTATION_CODE
                    ) {}
            };
        }
    }
}
#endif