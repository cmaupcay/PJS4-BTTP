#ifndef H_BTTP_CLIENT_CLI_COMMANDE_DISTANT
#define H_BTTP_CLIENT_CLI_COMMANDE_DISTANT

#include "erreur/Syntaxe.h"
#include "erreur/execution/AucunServeur.h"

#define BTTP_COMMANDE_DISTANT "distant"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                class Distant : public Commande
                {
                private:
                    const Client::Serveurs::Serveur& definir_serveur() const;

                public:
                    Distant() : Commande(BTTP_COMMANDE_DISTANT) {}

                    void executer(const int argc, const char** argv) const override;
                    const std::string aide() const override;
                };
            }
        }
    }
}

#endif