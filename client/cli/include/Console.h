#ifndef H_BTTP_CLIENT_CLI_CONSOLE
#define H_BTTP_CLIENT_CLI_CONSOLE

#include "Racine.h"

#include <iostream>

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            class Console
            {
            public:
                inline static void afficher(const std::string message, const bool retour = true)
                { std::cout << message << (retour ? "\n" : "") << std::flush; }
                static const std::string demander(const std::string message);
            };
        }
    }
}

#endif