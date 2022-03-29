#ifndef H_BTTP_CLIENT_CLI_COMMANDE_AUTORISATIONS_DEJA_EXISTANTE
#define H_BTTP_CLIENT_CLI_COMMANDE_AUTORISATIONS_DEJA_EXISTANTE

#include "../../../Racine.h"

#define BTTP_CLIENT_CLI_COMMANDE_AUTORISATIONS_DEJA_EXISTANTE_CODE -111110

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
                    namespace Autorisations
                    {
                        class DejaExistante : public Erreur
                        {
                        private:
                            const std::string& _empreinte;

                        public:
                            DejaExistante(const std::string& empreinte)
                                : Erreur(
                                    "Client/CLI/Commandes/Autorisations/DejaExistante",
                                    "L'empreinte locale \"" + empreinte + "\" existe déjà.",
                                    BTTP_CLIENT_CLI_COMMANDE_AUTORISATIONS_DEJA_EXISTANTE_CODE
                                ),
                                _empreinte{ empreinte }
                            {}

                            inline const std::string& empreinte() const { return this->_empreinte; }
                        };
                    }
                }
            }
        }
    }
}
#endif