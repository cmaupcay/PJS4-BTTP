#ifndef H_BTTP_CLIENT_CLI_COMMANDE_SYNTAXE
#define H_BTTP_CLIENT_CLI_COMMANDE_SYNTAXE

#include "../Commande.h"

#define BTTP_CLIENT_CLI_COMMANDE_SYNTAXE_CODE -11100

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
                    class Syntaxe : public Erreur
                    {
                    private:
                        const CLI::Commandes::Commande* _commande;
                    public:
                        Syntaxe(const CLI::Commandes::Commande* commande)
                            : Erreur(
                                "Client/CLI/Commandes/Syntaxe",
                                "La syntaxe de la commande \"" + commande->nom() + "\" n'est pas correcte.",
                                BTTP_CLIENT_CLI_COMMANDE_SYNTAXE_CODE
                            ),
                            _commande{ commande }
                        {}

                        inline const CLI::Commandes::Commande* commande() const { return this->_commande; }
                    };
                }
            }
        }
    }
}
#endif