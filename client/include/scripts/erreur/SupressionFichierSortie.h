#ifndef H_BTTP_CLIENT_SCRIPT_SUPRESSION_FICHIER_SORTIE
#define H_BTTP_CLIENT_SCRIPT_SUPRESSION_FICHIER_SORTIE

#include "../Script.h"

#define BTTP_CLIENT_SCRIPT_SUPRESSION_FICHIER_SORTIE_CODE -2003

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Scripts
            {
                class SupressionFichierSortie : public Erreur
                {
                private:
                    const std::string& _fichier;
                public:
                    SupressionFichierSortie(const std::string& fichier)
                        : Erreur("Client/Scripts/SupressionFichierSortie", "Le fichier temporaire de sortie " + fichier + "n'existe pas.", BTTP_CLIENT_SCRIPT_SUPRESSION_FICHIER_SORTIE_CODE),
                        _fichier{ fichier }
                    {}

                    inline const std::string& fichier() const { return this->_fichier; }
                };
            }
        }
    }
}
#endif