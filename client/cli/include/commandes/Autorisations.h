#ifndef H_BTTP_CLIENT_CLI_COMMANDE_AUTORISATIONS
#define H_BTTP_CLIENT_CLI_COMMANDE_AUTORISATIONS

#include "erreur/Syntaxe.h"
#include "erreur/autorisations/Inexistante.h"
#include "erreur/autorisations/DejaExistante.h"

#define BTTP_COMMANDE_AUTORISATIONS "auth"
#define BTTP_COMMANDE_AUTORISATIONS_AJOUT "+"
#define BTTP_COMMANDE_AUTORISATIONS_SUPPRESSION "-"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                class Autorisations : public Commande
                {
                private:
                    void liste(const std::string mdp) const;
                    void ajout(const std::string mdp, const std::string fichier_cible) const;
                    void suppression(const std::string mdp, const std::string empreinte) const;

                public:
                    Autorisations() : Commande(BTTP_COMMANDE_AUTORISATIONS) {}

                    void executer(const int argc, const char** argv, asio::io_context& contexte) const override;
                    const std::string aide() const override;
                };
            }
        }
    }
}

#endif