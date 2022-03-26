#ifndef H_BTTP_CLIENT_SERVEUR_MESSAGE_REPONSE_MOT_DE_PASSE
#define H_BTTP_CLIENT_SERVEUR_MESSAGE_REPONSE_MOT_DE_PASSE

#include "DemandeMotDePasse.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                class ReponseMotDePasse : public Protocole::Messages::Reponse
                {
                public:
                    ReponseMotDePasse(const std::string mdp)
                        : Protocole::Messages::Reponse(
                            BTTP_DEMANDE_MOT_DE_PASSE,
                            mdp
                        )
                    {}
                };
            }
        }
    }
}

#endif