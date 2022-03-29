#ifndef H_BTTP_CLIENT_CLI_CONFIRMATION_MDP
#define H_BTTP_CLIENT_CLI_CONFIRMATION_MDP

#include "../Racine.h"

#define BTTP_CLIENT_CLI_CONFIRMATION_MDP_CODE -11001

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Erreur
            {
                class ConfirmationMDP : public Erreur
                {
                public:
                    ConfirmationMDP()
                        : Erreur(
                            "Client/CLI/ConfirmationMDP",
                            "Les mots de passe ne correspondent pas.",
                            BTTP_CLIENT_CLI_CONFIRMATION_MDP_CODE
                        )
                    {}
                };
            }
        }
    }
}
#endif