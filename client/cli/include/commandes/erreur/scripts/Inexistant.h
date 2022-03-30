#ifndef H_BTTP_CLIENT_CLI_COMMANDE_SCRIPTS_INEXISTANT
#define H_BTTP_CLIENT_CLI_COMMANDE_SCRIPTS_INEXISTANT

#include "../../../Racine.h"

#define BTTP_CLIENT_CLI_COMMANDE_SCRIPTS_INEXISTANT_CODE -111301

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
                        class Inexistant : public Erreur
                        {
                        private:
                            const std::string& _script;

                        public:
                            Inexistant(const std::string& script)
                                : Erreur(
                                    "Client/CLI/Commandes/Scripts/Inexistant",
                                    "Le script \"" + script + "\" n'existe pas.",
                                    BTTP_CLIENT_CLI_COMMANDE_SCRIPTS_INEXISTANT_CODE
                                ),
                                _script { script }
                            {}

                            inline const std::string& script() const { return this->_script; }
                        };
                    }
                }
            }
        }
    }
}
#endif