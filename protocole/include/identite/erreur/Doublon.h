#ifndef H_BTTP_IDENTITE_DOUBLON
#define H_BTTP_IDENTITE_DOUBLON

#include "../../Erreur.h"

#ifndef BTTP_IDENTITE_DOUBLON_CODE
    #define BTTP_IDENTITE_DOUBLON_CODE -213
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Identite
            {
                class Doublon : public Erreur
                {
                public:
                    Doublon(const std::string& fichier)
                        : Erreur(
                            "Identite/Doublon", "L'exportation de la clé privée dans le fichier '" + fichier + "' a échoué car un fichier similaire existe déjà.",
                            BTTP_IDENTITE_DOUBLON_CODE
                        ) {}
                };
            }
        }
    }
}
#endif