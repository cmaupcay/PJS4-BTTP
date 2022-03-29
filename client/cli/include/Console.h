#ifndef H_BTTP_CLIENT_CLI_CONSOLE
#define H_BTTP_CLIENT_CLI_CONSOLE

#include "Racine.h"
#include "erreur/ConfirmationMDP.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Console
            {
                void afficher(const std::string message, const bool retour = true);
                
                inline void saut() { std::cout << std::endl << std::flush; }

                const std::string demander(const std::string message);

                const std::string creer_mdp();
            };
        }
    }
}

#endif