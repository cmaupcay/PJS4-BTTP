#ifndef H_BTTP_CLIENT_CLI_COMMANDE_AUTORISATIONS
#define H_BTTP_CLIENT_CLI_COMMANDE_AUTORISATIONS

#include "erreur/Syntaxe.h"

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
                    const int liste(const std::string mdp) const;
                    const int ajout(const std::string mdp, const std::string fichier_cible) const;
                    const int suppression(const std::string mdp, const std::string empreinte) const;

                public:
                    Autorisations() : Commande(BTTP_COMMANDE_AUTORISATIONS) {}

                    const int executer(const int argc, const char** argv) const override;
                    const std::string aide() const override;
                };
            }
        }
    }
}

#endif