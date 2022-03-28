#ifndef H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_APPAREILS
#define H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_APPAREILS

#include "../../Racine.h"

/** Champs de demande correspondant aux appareils. */
#define BTTP_DEMANDE_APPAREILS "apps"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                class DemandeAppareils : public Protocole::Messages::Demande
                {
                public:
                    DemandeAppareils()
                        : Protocole::Messages::Demande(BTTP_DEMANDE_APPAREILS, {})
                    {}
                };
            }
        }
    }
}

#endif