#ifndef H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_AUTH
#define H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_AUTH

#include "../../Racine.h"

/** Champs de demande correspondant à une authentification. */
#define BTTP_DEMANDE_AUTH "auth"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                class DemandeAuthentification : public Protocole::Messages::Demande
                {
                public:
                    DemandeAuthentification()
                        : Protocole::Messages::Demande(BTTP_DEMANDE_AUTH, {})
                    {}
                };
            }
        }
    }
}

#endif