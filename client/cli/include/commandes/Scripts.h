#ifndef H_BTTP_CLIENT_CLI_COMMANDE_SCRIPTS
#define H_BTTP_CLIENT_CLI_COMMANDE_SCRIPTS

#include "erreur/Syntaxe.h"
#include "erreur/scripts/ServeurInexistant.h"
#include "erreur/scripts/Inexistant.h"

#define BTTP_COMMANDE_SCRIPTS "src"
#define BTTP_COMMANDE_SCRIPTS_AJOUT "+"
#define BTTP_COMMANDE_SCRIPTS_SUPPRESSION "-"
#define BTTP_COMMANDE_SCRIPTS_EXPORT "--export"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                class Scripts : public Commande
                {
                private:
                    void liste() const;
                    void liste(const std::string serveur) const;
                    void liste(const Client::Serveurs::Serveur& serveur) const;
                    void ajout(const std::string script) const;
                    const Client::Scripts::Script charger(const Client::Serveurs::Serveur& serveur, const std::string script) const;
                    void suppression(const std::string script) const;
                    void exportation(const std::string script) const;

                public:
                    Scripts() : Commande(BTTP_COMMANDE_SCRIPTS) {}

                    void executer(const int argc, const char** argv) const override;
                    const std::string aide() const override;
                };
            }
        }
    }
}

#endif