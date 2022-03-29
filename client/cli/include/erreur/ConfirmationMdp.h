#ifndef H_BTTP_CLIENT_CLI_CONFIRMATION_MDP
#define H_BTTP_CLIENT_CLI_CONFIRMATION_MDP

#define BTTP_CLIENT_CLI_CONFIRMATION_MDP_CODE -11001

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Erreur
            {
                class ConfirmationMdp : public Erreur
                {
                public:
                    ConfirmationMdp()
                        : Erreur(
                            "Client/CLI/ConfirmationMdp",
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