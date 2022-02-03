#ifndef H_BTTP_CLIENT_CLI_COMMANDE_SYNTAXE
#define H_BTTP_CLIENT_CLI_COMMANDE_SYNTAXE

#include "../../Racine.h"

#ifndef H_BTTP_CLIENT_CLI_COMMANDE_SYNTAXE_CODE
    #define H_BTTP_CLIENT_CLI_COMMANDE_SYNTAXE_CODE -11100
#endif

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Erreur
            {
                class Commande_Syntaxe : public Erreur
                {
                private:
                    const std::string& _commande;
                public:
                    Commande_Syntaxe(const std::string commande)
                        : Erreur("Client/CLI/Commande/Syntaxe", "La syntaxe de la commande \"" + commande + "\" n'est pas correcte.", H_BTTP_CLIENT_CLI_COMMANDE_SYNTAXE_CODE),
                        _commande{ commande }
                    {}

                    inline const std::string& commande() const { return this->_commande; }
                };
            }
        }
    }
}
#endif