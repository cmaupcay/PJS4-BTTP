#ifndef H_BTTP_CLIENT_SERVEURS_DEJA_PRESENT
#define H_BTTP_CLIENT_SERVEURS_DEJA_PRESENT

#include "../Serveur.h"

#define BTTP_CLIENT_SERVEURS_DEJA_PRESENT_CODE -1400

namespace BTTP
{
    namespace Client
    {
        namespace Erreur
        {
            namespace Serveurs
            {
                class DejaPresent : public Erreur
                {
                private:
                    const Client::Serveurs::Serveur& _serveur;
                public:
                    DejaPresent(const Client::Serveurs::Serveur& serveur)
                        : Erreur("Client/Serveurs/DejaPresent", "Impossible d'ajouter " + serveur.nom() + " car il est deja present.", BTTP_CLIENT_SERVEURS_DEJA_PRESENT_CODE),
                        _serveur{ serveur }
                    {}

                    inline const Client::Serveurs::Serveur& serveur() const { return this->_serveur; }
                };
            }
        }
    }
}
#endif