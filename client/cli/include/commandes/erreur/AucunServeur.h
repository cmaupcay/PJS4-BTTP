#ifndef H_BTTP_CLIENT_CLI_COMMANDE_AUCUN_SERVEUR
#define H_BTTP_CLIENT_CLI_COMMANDE_AUCUN_SERVEUR

#include "../../Racine.h"

#define BTTP_CLIENT_CLI_COMMANDE_AUCUN_SERVEUR_CODE -11102

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
                    class AucunServeur : public Erreur
                    {

                    public:
                        AucunServeur()
                            : Erreur(
                                "Client/CLI/Commandes/AucunServeur",
                                "Aucun serveur disponible.",
                                BTTP_CLIENT_CLI_COMMANDE_AUCUN_SERVEUR_CODE
                            )
                        {}
                    };
                }
            }
        }
    }
}
#endif