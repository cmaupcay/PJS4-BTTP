#ifndef H_BTTP_CLIENT_CLI_COMMANDE_IDENTITES
#define H_BTTP_CLIENT_CLI_COMMANDE_IDENTITES

#include "erreur/Syntaxe.h"
#include "erreur/identites/DejaExistante.h"
#include "erreur/identites/Inexistante.h"

#define BTTP_COMMANDE_IDENTITES "id"
#define BTTP_COMMANDE_IDENTITES_AJOUT "+"
#define BTTP_COMMANDE_IDENTITES_SUPPRESSION "-"
#define BTTP_COMMANDE_IDENTITES_EXPORT "--export"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                class Identites : public Commande
                {
                private:
                    const int liste() const;
                    const int ajout(const std::string cible) const;
                    const int suppression(const std::string cible) const;
                    const int exportation(const std::string cible) const;

                public:
                    Identites() : Commande(BTTP_COMMANDE_IDENTITES) {}

                    void executer(const int argc, const char** argv) const override;
                    const std::string aide() const override;
                };
            }
        }
    }
}

#endif