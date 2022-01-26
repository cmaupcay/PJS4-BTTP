#ifndef H_BTTP_IDENTITE_IMPORTATION
#define H_BTTP_IDENTITE_IMPORTATION

#include "../../Erreur.h"

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
                    : Erreur("Identite/Importation", "L'importation de la clé privée depuis le fichier '" + fichier + "' a échoué.") {}
            };
        }
    }
}
#endif