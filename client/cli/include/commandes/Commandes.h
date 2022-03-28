#ifndef H_BTTP_CLIENT_CLI_COMMANDES
#define H_BTTP_CLIENT_CLI_COMMANDES

#include "Serveurs.h"
#include "Identites.h"
#include "Autorisations.h"

#include "erreur/Inconnue.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                const std::vector<Commande*> commandes();
                const int resoudre(const int argc, const char** argv);
                const std::string aide();
            }
        }
    }
}

#endif