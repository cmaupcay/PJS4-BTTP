#ifndef H_BTTP_CLIENT_CLI_COMMANDE_EXECUTION
#define H_BTTP_CLIENT_CLI_COMMANDE_EXECUTION

#include "erreur/Syntaxe.h"
#include "erreur/execution/AucunAppareil.h"
#include "erreur/execution/OuvertureTransaction.h"

#define BTTP_COMMANDE_EXECUTION "exe"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                class Execution : public Commande
                {
                private:
                    const Appareil& definir_appareil(const Client::Serveurs::Serveur& serveur, const std::string mdp) const;
                    const Client::Serveurs::Script* definir_script(
                        const Client::Serveurs::Serveur& serveur, const Appareil& appareil, const std::string mdp
                    ) const;

                public:
                    Execution() : Commande(BTTP_COMMANDE_EXECUTION) {}

                    void executer(const int argc, const char** argv) const override;
                    const std::string aide() const override;
                };
            }
        }
    }
}

#endif