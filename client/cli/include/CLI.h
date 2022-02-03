#ifndef H_BTTP_CLIENT_CLI
#define H_BTTP_CLIENT_CLI

#include "commandes/Commandes.h"
#include "Console.h"

#include <stdlib.h>

#define BTTP_CLIENT_CLI_INTRO "bttp-cli v" BTTP_CLIENT_CLI_VERSION " (client: " BTTP_CLIENT_VERSION " / protocole: " BTTP_VERSION ")"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            const int executer(const int& argc, const char** argv);
        }
    }
}

#endif