#ifndef H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_EMPREINTE_CLE
#define H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_EMPREINTE_CLE

#include "../../Racine.h"

/** Champs de demande correspondant à l'empreinte d'une clé publique. */
#define BTTP_DEMANDE_EMPREINTE_CLE "id.emp"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                class DemandeEmpreinteCle : public Protocole::Messages::Demande
                {
                public:
                    DemandeEmpreinteCle()
                        : Protocole::Messages::Demande(BTTP_DEMANDE_EMPREINTE_CLE, {})
                    {}
                };
            }
        }
    }
}

#endif