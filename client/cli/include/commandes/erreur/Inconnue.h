#ifndef H_BTTP_CLIENT_CLI_COMMANDE_INCONNUE
#define H_BTTP_CLIENT_CLI_COMMANDE_INCONNUE

#include "../../Racine.h"

#define BTTP_CLIENT_CLI_COMMANDE_INCONNUE_CODE -11101

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Erreur
            {
                class Commande_Inconnue : public Erreur
                {
                private:
                    const std::string& _mot;
                public:
                    Commande_Inconnue(const std::string& mot)
                        : Erreur("Client/CLI/Commande/Inconnue", "La commande \"" + mot + "\" est inconnue.", BTTP_CLIENT_CLI_COMMANDE_INCONNUE_CODE),
                        _mot{ mot }
                    {}

                    inline const std::string& mot() const { return this->_mot; }
                };
            }
        }
    }
}
#endif