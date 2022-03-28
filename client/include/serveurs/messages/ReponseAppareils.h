#ifndef H_BTTP_CLIENT_SERVEUR_MESSAGE_REPONSE_APPAREILS
#define H_BTTP_CLIENT_SERVEUR_MESSAGE_REPONSE_APPAREILS

#include "DemandeAppareils.h"
#include "../Appareil.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                class ReponseAppareils : public Protocole::Messages::Reponse
                {
                public:
                    ReponseAppareils(const std::vector<Appareil> appareils);

                    ReponseAppareils(const std::string paquet)
                        : Protocole::Messages::Reponse(paquet)
                    {}

                    const std::vector<Appareil> appareils() const;
                };
            }
        }
    }
}

#endif