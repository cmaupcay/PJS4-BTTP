#ifndef H_BTTP_CLIENT_CONNEXION_DEJA_OUVERTE
#define H_BTTP_CLIENT_CONNEXION_DEJA_OUVERTE

#include "../../Racine.h"

#define H_BTTP_CLIENT_CONNEXION_DEJA_OUVERTE_CODE -1202

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Connexion
            {
                class DejaOuverte : public Erreur
                {
                private:
                    const std::string _adresse;
                    const uint16_t _port;

                public:
                    DejaOuverte(const std::string adresse, const uint16_t port)
                        : Erreur("Client/Connexion/DejaOuverte", "La connexion au serveur est deja ouverte. (" + adresse + ")", H_BTTP_CLIENT_CONNEXION_DEJA_OUVERTE_CODE),
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