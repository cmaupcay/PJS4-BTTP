#ifndef H_BTTP_CLIENT_CLI_COMMANDE
#define H_BTTP_CLIENT_CLI_COMMANDE

#include "../Console.h"

#include "erreur/Syntaxe.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                class Commande
                {
                private:
                    const std::string _nom;
                protected:
                    Commande(const std::string nom) : _nom{ nom } {}

                public:
                    virtual const int executer(const int argc, const char** argv);
                    virtual const std::string aide() const;

                    inline const std::string& nom() const { return this->_nom; }
                };
            }
        }
    }
}

#endif