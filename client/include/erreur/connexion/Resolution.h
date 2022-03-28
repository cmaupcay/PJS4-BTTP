#ifndef H_BTTP_CLIENT_CONNEXION_RESOLUTION
#define H_BTTP_CLIENT_CONNEXION_RESOLUTION

#include "../../Racine.h"

#define H_BTTP_CLIENT_CONNEXION_RESOLUTION_CODE -1203

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Connexion
            {
                class Resolution : public Erreur
                {
                private:
                    const std::string _adresse;
                    const uint16_t _port;

                public:
                    Resolution(const std::string adresse, const uint16_t port)
                        : Erreur("Client/Connexion/Resolution", "La resolution d'hote a echoue. (" + adresse + ")", H_BTTP_CLIENT_CONNEXION_RESOLUTION_CODE),
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