#ifndef H_BTTP_CLIENT_SCRIPTS_AJOUT
#define H_BTTP_CLIENT_SCRIPTS_AJOUT

#include "../Script.h"

#define BTTP_CLIENT_SCRIPTS_AJOUT_CODE -2001

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Scripts
            {
                class Ajout : public Erreur
                {
                private:
                    const std::string _nom;
                    const Serveurs::Serveur& _serveur;

                public:
                    Ajout(const std::string nom, const Serveurs::Serveur& serveur)
                        : Erreur("Client/Scripts/Ajout", "Impossible d'ajouter le script '" + nom + "' (serveur : '" + serveur.nom() + "').", BTTP_CLIENT_SCRIPTS_AJOUT_CODE),
                        _nom{ nom }, _serveur{ serveur }
                    {}

                    inline const std::string& nom() const { return this->_nom; }
                    inline const Serveurs::Serveur& serveur() const { return this->_serveur; }
                };
            }
        }
    }
}
#endif