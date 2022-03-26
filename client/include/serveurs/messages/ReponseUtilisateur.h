#ifndef H_BTTP_CLIENT_SERVEUR_MESSAGE_REPONSE_UTILISATEUR
#define H_BTTP_CLIENT_SERVEUR_MESSAGE_REPONSE_UTILISATEUR

#include "DemandeUtilisateur.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                class ReponseUtilisateur : public Protocole::Messages::Reponse
                {
                public:
                    ReponseUtilisateur(const std::string utilisateur)
                        : Protocole::Messages::Reponse(
                            BTTP_DEMANDE_UTILISATEUR,
                            utilisateur
                        )
                    {}
                };
            }
        }
    }
}

#endif