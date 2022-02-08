#ifndef H_BTTP_CLIENT_FICHIERS_INEXISTANT
#define H_BTTP_CLIENT_FICHIERS_INEXISTANT

#include "../../Racine.h"

#define H_BTTP_CLIENT_FICHIERS_INEXISTANT_CODE -1100

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Fichiers
            {
                class Inexistant : public Erreur
                {
                private:
                    const std::string& _fichier;
                public:
                    Inexistant(const std::string& fichier, const std::string type = "fichier")
                        : Erreur("Client/Fichiers/Inexistant", "Le " + type + " '" + fichier + "' n'existe pas.", H_BTTP_CLIENT_FICHIERS_INEXISTANT_CODE),
                        _fichier{ fichier }
                    {}

                    inline const std::string& fichier() const { return this->_fichier; }
                };
            }
        }
    }
}
#endif