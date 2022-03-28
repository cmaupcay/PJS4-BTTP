#ifndef H_BTTP_CLIENT_CONNEXION_FERMEE
#define H_BTTP_CLIENT_CONNEXION_FERMEE

#include "../../Racine.h"

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
                    const std::string _adresse;
                    const uint16_t _port;

                public:
                    Fermee(const std::string adresse, const uint16_t port)
                        : Erreur("Client/Connexion/Fermee", "La connexion au serveur est fermee. (" + adresse + ")", H_BTTP_CLIENT_CONNEXION_FERMEE_CODE),
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