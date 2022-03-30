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
                    const int liste(asio::io_context& contexte) const;
                    void ajout(asio::io_context& contexte, const std::string cible) const;
                    void suppression(asio::io_context& contexte, const std::string cible) const;

                public:
                    Serveurs() : Commande(BTTP_COMMANDE_SERVEURS) {}

                    void executer(const int argc, const char** argv, asio::io_context& contexte) const override;
                    const std::string aide() const override;
                };
            }
        }
    }
}

#endif