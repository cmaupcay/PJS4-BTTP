#ifndef H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_CLE_PUBLIQUE
#define H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_CLE_PUBLIQUE

#include "../../Racine.h"

/** Champs de demande correspondant à une clé publique. */
#define BTTP_DEMANDE_CLE_PUBLIQUE "id.pub"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                class DemandeClePublique : public Protocole::Messages::Demande
                {
                public:
                    DemandeClePublique()
                        : Protocole::Messages::Demande(BTTP_DEMANDE_CLE_PUBLIQUE, {})
                    {}
                };
            }
        }
    }
}

#endif