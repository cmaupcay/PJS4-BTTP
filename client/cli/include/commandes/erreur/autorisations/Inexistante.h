#ifndef H_BTTP_CLIENT_CLI_COMMANDE_AUTORISATIONS_INEXISTANTE
#define H_BTTP_CLIENT_CLI_COMMANDE_AUTORISATIONS_INEXISTANTE

#include "../../../Racine.h"

#define BTTP_CLIENT_CLI_COMMANDE_AUTORISATIONS_INEXISTANTE_CODE -111111

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
                        class Inexistante : public Erreur
                        {
                        private:
                            const std::string& _empreinte;
                        public:
                            Inexistante(const std::string& empreinte)
                                : Erreur(
                                    "Client/CLI/Commandes/Autorisations/Inexistante",
                                    "L'empreinte \"" + empreinte + "\" est inexistante.",
                                    BTTP_CLIENT_CLI_COMMANDE_AUTORISATIONS_INEXISTANTE_CODE
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