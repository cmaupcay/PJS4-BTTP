#ifndef H_BTTP_CLIENT_FICHIERS_OUVERTURE
#define H_BTTP_CLIENT_FICHIERS_OUVERTURE

#include "../../Racine.h"

#define BTTP_CLIENT_FICHIERS_OUVERTURE_CODE -1101

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Fichiers
            {
                class Ouverture : public Erreur
                {
                private:
                    const std::string& _fichier;
                public:
                    Ouverture(const std::string& fichier, const std::string type = "fichier")
                        : Erreur("Client/Fichiers/Ouverture", "Impossible d'ouvrir le " + type + " \"" + fichier + "\".", BTTP_CLIENT_FICHIERS_OUVERTURE_CODE),
                        _fichier{ fichier }
                    {}

                    inline const std::string& fichier() const { return this->_fichier; }
                };
            }
        }
    }
}
#endif