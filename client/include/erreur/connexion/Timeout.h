#ifndef H_BTTP_CLIENT_CONNEXION_TIMEOUT
#define H_BTTP_CLIENT_CONNEXION_TIMEOUT

#include "../../Racine.h"

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
                    const std::string _adresse;
                    const uint16_t _port;

                public:
                    Timeout(const std::string adresse, const uint16_t port)
                        : Erreur("Client/Connexion/Timeout", "Delai de demande de reception depassee. (" + adresse + ")", H_BTTP_CLIENT_CONNEXION_TIMEOUT_CODE),
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