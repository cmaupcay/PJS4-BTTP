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
                namespace Commandes
                {
                    class Inconnue : public Erreur
                    {
                    private:
                        const std::string& _mot;
                    public:
                        Inconnue(const std::string& mot)
                            : Erreur(
                                "Client/CLI/Commandes/Inconnue",
                                "La commande \"" + mot + "\" est inconnue.",
                                BTTP_CLIENT_CLI_COMMANDE_INCONNUE_CODE
                            ),
                            _mot{ mot }
                        {}

                        inline const std::string& mot() const { return this->_mot; }
                    };
                }
            }
        }
    }
}
#endif