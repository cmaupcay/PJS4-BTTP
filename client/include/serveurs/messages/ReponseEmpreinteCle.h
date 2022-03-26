#ifndef H_BTTP_CLIENT_SERVEUR_MESSAGE_REPONSE_EMPREINTE_CLE
#define H_BTTP_CLIENT_SERVEUR_MESSAGE_REPONSE_EMPREINTE_CLE

#include "DemandeEmpreinteCle.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                class ReponseEmpreinteCle : public Protocole::Messages::Reponse
                {
                public:
                    ReponseEmpreinteCle(const Protocole::Cle::Publique& cle)
                        : Protocole::Messages::Reponse(
                            BTTP_DEMANDE_EMPREINTE_CLE,
                            cle.fingerprint()
                        )
                    {}

                    ReponseEmpreinteCle(const std::string paquet)
                        : Protocole::Messages::Reponse(paquet)
                    {}
                };
            }
        }
    }
}

#endif