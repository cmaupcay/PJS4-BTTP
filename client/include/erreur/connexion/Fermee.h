#ifndef H_BTTP_CLIENT_CONNEXION_FERMEE
#define H_BTTP_CLIENT_CONNEXION_FERMEE

#include "../../Racine.h"
#include "../../serveurs/Serveur.h"

#define H_BTTP_CLIENT_CONNEXION_FERMEE_CODE -1200

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Connexion
            {
                class Fermee : public Erreur
                {
                private:
                    const Serveur& _serveur;
                public:
                    Fermee(const Serveur& serveur)
                        : Erreur("Client/Connexion/Fermee", "La connexion au serveur est fermee. (" + serveur.informations() + ")", H_BTTP_CLIENT_CONNEXION_FERMEE_CODE),
                        _serveur{ serveur }
                    {}

                    inline const Serveur& serveur() const { return this->_serveur; }
                };
            }
        }
    }
}
#endif