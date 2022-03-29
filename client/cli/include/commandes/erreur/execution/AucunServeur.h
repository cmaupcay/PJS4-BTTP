#ifndef H_BTTP_CLIENT_CLI_COMMANDE_EXECUTION_AUCUN_SERVEUR
#define H_BTTP_CLIENT_CLI_COMMANDE_EXECUTION_AUCUN_SERVEUR

#include "../../../Racine.h"

#define BTTP_CLIENT_CLI_COMMANDE_EXECUTION_AUCUN_SERVEUR_CODE -111200

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
                        class AucunServeur : public Erreur
                        {

                        public:
                            AucunServeur()
                                : Erreur(
                                    "Client/CLI/Commandes/Execution/AucunServeur",
                                    "Aucun serveur disponible.",
                                    BTTP_CLIENT_CLI_COMMANDE_EXECUTION_AUCUN_SERVEUR_CODE
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