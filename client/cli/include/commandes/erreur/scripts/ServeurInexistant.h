#ifndef H_BTTP_CLIENT_CLI_COMMANDE_SCRIPTS_SERVEUR_INEXISTANT
#define H_BTTP_CLIENT_CLI_COMMANDE_SCRIPTS_SERVEUR_INEXISTANT

#include "../../../Racine.h"

#define BTTP_CLIENT_CLI_COMMANDE_SCRIPTS_SERVEUR_INEXISTANT_CODE -111300

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Erreur
            {
                namespace Commandes
                {
                    namespace Scripts
                    {
                        class ServeurInexistant : public Erreur
                        {
                        private:
                            const std::string& _serveur;

                        public:
                            ServeurInexistant(const std::string& serveur)
                                : Erreur(
                                    "Client/CLI/Commandes/Scripts/ServeurInexistant",
                                    "Le serveur \"" + serveur + "\" n'existe pas.",
                                    BTTP_CLIENT_CLI_COMMANDE_SCRIPTS_SERVEUR_INEXISTANT_CODE
                                ),
                                _serveur { serveur }
                            {}

                            inline const std::string& serveur() const { return this->_serveur; }
                        };
                    }
                }
            }
        }
    }
}
#endif