#ifndef H_BTTP_CLIENT_SERVEUR_MESSAGE_REPONSE_CLE_PUBLIQUE
#define H_BTTP_CLIENT_SERVEUR_MESSAGE_REPONSE_CLE_PUBLIQUE

#include "DemandeClePublique.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                class ReponseClePublique : public Protocole::Messages::Reponse
                {
                public:
                    ReponseClePublique(const Protocole::Cle::Publique& cle)
                        : Protocole::Messages::Reponse(
                            BTTP_DEMANDE_CLE_PUBLIQUE,
                            cle.exporter(false)
                        )
                    {}

                    ReponseClePublique(const std::string paquet)
                        : Protocole::Messages::Reponse(paquet)
                    {}

                    inline const Protocole::Cle::Publique cle() const { return Protocole::Cle::Publique(this->data()); }
                };
            }
        }
    }
}

#endif