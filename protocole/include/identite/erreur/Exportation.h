#ifndef H_BTTP_IDENTITE_EXPORTATION
#define H_BTTP_IDENTITE_EXPORTATION

#include "../../Erreur.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            class Identite_Exportation : public Erreur
            {
            public:
                Identite_Exportation(const std::string& fichier)
                    : Erreur("Identite/Exportation", "L'exportation de la clé privée dans le fichier '" + fichier + "' a échoué.") {}
            };
        }
    }
}
#endif