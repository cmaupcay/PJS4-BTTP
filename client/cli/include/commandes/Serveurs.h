#ifndef H_BTTP_CLIENT_CLI_COMMANDE_SERVEURS
#define H_BTTP_CLIENT_CLI_COMMANDE_SERVEURS

#include "erreur/Syntaxe.h"

#define BTTP_COMMANDE_SERVEURS "srv"
#define BTTP_COMMANDE_SERVEURS_AJOUT "+"
#define BTTP_COMMANDE_SERVEURS_SUPPRESSION "-"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                class Serveurs : public Commande
                {
                private:
                    const int liste() const;
                    const int ajout(const std::string cible) const;
                    const int suppression(const std::string cible) const;

                public:
                    Serveurs() : Commande(BTTP_COMMANDE_SERVEURS) {}

                    const int executer(const int argc, const char** argv) const override;
                    const std::string aide() const override;
                };
            }
        }
    }
}

#endif