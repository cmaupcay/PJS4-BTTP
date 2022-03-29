#ifndef H_BTTP_CLIENT_CLI_COMMANDE_EXECUTION_AUCUN_APPAREIL
#define H_BTTP_CLIENT_CLI_COMMANDE_EXECUTION_AUCUN_APPAREIL

#include "../../../Racine.h"

#define BTTP_CLIENT_CLI_COMMANDE_EXECUTION_AUCUN_APPAREIL_CODE -111201

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
                    namespace Execution
                    {
                        class AucunAppareil : public Erreur
                        {

                        public:
                            AucunAppareil()
                                : Erreur(
                                    "Client/CLI/Commandes/Execution/AucunAppareil",
                                    "Aucun appareil disponible.",
                                    BTTP_CLIENT_CLI_COMMANDE_EXECUTION_AUCUN_APPAREIL_CODE
                                )
                            {}
                        };
                    }
                }
            }
        }
    }
}
#endif