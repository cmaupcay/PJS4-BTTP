#ifndef H_BTTP_SERVEUR
#define H_BTTP_SERVEUR

#include "Accepteur.h"

#define BTTP_SERVEUR_INTRO "bttp-srv v" BTTP_SERVEUR_VERSION " (client: " BTTP_CLIENT_VERSION " / protocole: " BTTP_VERSION ")"

namespace BTTP
{
    namespace Serveur
    {
        std::unique_ptr<Client::Contexte> definir_contexte(const char** argv);
        void definir_identite(std::unique_ptr<Client::Contexte>& contexte, const int& argc, const char** argv, const std::string& mdp);

        const int executer(const int& argc, const char** argv, const std::string& mdp);
    }
}

#endif