#ifndef H_BTTP_CLIENT_CLI_COMMANDE
#define H_BTTP_CLIENT_CLI_COMMANDE

#include "../Console.h"
#include "../Contexte.h"

#include "erreur/AucunServeur.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                // TODO fonctions de sous séquence (ex: ajout, suppression, liste) -> fonctions statiques publiques comme authentification.
                class Commande
                {
                private:
                    const std::string _nom;

                protected:
                    Commande(const std::string nom) : _nom{ nom } {}

                    static const Client::Serveurs::Serveur definir_serveur(asio::io_context& contexte);
                    static void authentification(Client::Serveurs::Serveur& serveur, const std::string mdp);

                public:
                    virtual void executer(const int argc, const char** argv, asio::io_context& contexte) const = 0;
                    virtual const std::string aide() const = 0;

                    inline const std::string& nom() const { return this->_nom; }
                };
            }
        }
    }
}

#endif