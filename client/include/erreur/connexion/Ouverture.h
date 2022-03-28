#ifndef H_BTTP_CLIENT_CONNEXION_OUVERTURE
#define H_BTTP_CLIENT_CONNEXION_OUVERTURE

#include "../../Racine.h"

#define H_BTTP_CLIENT_CONNEXION_OUVERTURE_CODE -1204

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Connexion
            {
                class Ouverture : public Erreur
                {
                private:
                    const std::string _adresse;
                    const uint16_t _port;

                public:
                    Ouverture(const std::string adresse, const uint16_t port)
                        : Erreur("Client/Connexion/Ouverture", "La connexion au serveur a echoue. (" + adresse + ")", H_BTTP_CLIENT_CONNEXION_OUVERTURE_CODE),
                        _adresse{ adresse }, _port{ port }
                    {}

                    inline const std::string& adresse() const { return this->_adresse; }
                    inline const uint16_t& port() const { return this->_port; }
                };
            }
        }
    }
}
#endif