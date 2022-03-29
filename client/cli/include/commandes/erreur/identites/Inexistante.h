#ifndef H_BTTP_CLIENT_CLI_COMMANDE_IDENTITES_INEXISTANTE
#define H_BTTP_CLIENT_CLI_COMMANDE_IDENTITES_INEXISTANTE

#include "../../../Racine.h"

#define BTTP_CLIENT_CLI_COMMANDE_IDENTITES_INEXISTANTE_CODE -111101

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
                    namespace Identites
                    {
                        class Inexistante : public Erreur
                        {
                        private:
                            const std::string& _nom;

                        public:
                            Inexistante(const std::string& nom)
                                : Erreur(
                                    "Client/CLI/Commandes/Identites/Inexistante",
                                    "L'identité locale \"" + nom + "\" n'existe pas.",
                                    BTTP_CLIENT_CLI_COMMANDE_IDENTITES_INEXISTANTE_CODE
                                ),
                                _nom{ nom }
                            {}

                            inline const std::string& nom() const { return this->_nom; }
                        };
                    }
                }
            }
        }
    }
}
#endif