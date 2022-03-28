#ifndef H_BTTP_CLIENT_CLI_COMMANDE_IDENTITES_DEJA_EXISTANTE
#define H_BTTP_CLIENT_CLI_COMMANDE_IDENTITES_DEJA_EXISTANTE

#include "../../../Racine.h"

#define BTTP_CLIENT_CLI_COMMANDE_IDENTITES_DEJA_EXISTANTE_CODE -111100

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
                        class DejaExistante : public Erreur
                        {
                        private:
                            const std::string& _nom;

                        public:
                            DejaExistante(const std::string& nom)
                                : Erreur(
                                    "Client/CLI/Commandes/Identites/DejaExistante",
                                    "L'identité locale \"" + nom + "\" existe déjà.",
                                    BTTP_CLIENT_CLI_COMMANDE_IDENTITES_DEJA_EXISTANTE_CODE
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