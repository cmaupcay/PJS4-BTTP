#ifndef H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_UTILISATEUR
#define H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_UTILISATEUR

#include "../../Racine.h"

/** Champs de demande correspondant à un nom d'utilisateur. */
#define BTTP_DEMANDE_UTILISATEUR "id.u"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                class DemandeUtilisateur : public Protocole::Messages::Demande
                {
                public:
                    DemandeUtilisateur()
                        : Protocole::Messages::Demande(BTTP_DEMANDE_UTILISATEUR)
                    {}
                };
            }
        }
    }
}

#endif