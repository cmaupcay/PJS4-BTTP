#ifndef H_BTTP_CLIENT_SERVEUR_MESSAGE_REPONSE_SCRIPTS
#define H_BTTP_CLIENT_SERVEUR_MESSAGE_REPONSE_SCRIPTS

#include "DemandeScripts.h"
#include "../Script.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                class ReponseScripts : public Protocole::Messages::Reponse
                {
                public:
                    ReponseScripts(const std::vector<Script> scripts);

                    ReponseScripts(const std::string paquet)
                        : Protocole::Messages::Reponse(paquet)
                    {}

                    const std::vector<Serveurs::Script> scripts() const;
                };
            }
        }
    }
}

#endif