#ifndef BTTP_CLIENT_CONNEXION
#define BTTP_CLIENT_CONNEXION

#include "Racine.h"
#include <asio.hpp>

namespace BTTP
{
    namespace Client
    {
        class Connexion : public Protocole::IConnexion
        {
            // TODO Implémentation de l'interface définie dans le protocole grâce à asio.
        }
    }
}

#endif