#ifndef H_BTTP_CLIENT_CONNEXION_TIMEOUT
#define H_BTTP_CLIENT_CONNEXION_TIMEOUT

#include "../../Racine.h"
#include "../../serveurs/Serveur.h"

#define H_BTTP_CLIENT_CONNEXION_TIMEOUT_CODE -1201

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Connexion
            {
                class Timeout : public Erreur
                {
                private:
                    const Serveur& _serveur;
                public:
                    Timeout(const Serveur& serveur)
                        : Erreur("Client/Connexion/Timeout", "Delai de demande de reception depassee. (" + serveur.informations() + ")", H_BTTP_CLIENT_CONNEXION_TIMEOUT_CODE),
                        _serveur{ serveur }
                    {}

                    inline const Serveur& serveur() const { return this->_serveur; }
                };
            }
        }
    }
}
#endif