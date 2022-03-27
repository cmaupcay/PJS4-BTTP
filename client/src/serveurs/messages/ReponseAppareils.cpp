#include "../../../include/serveurs/messages/ReponseAppareils.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                ReponseAppareils::ReponseAppareils(const std::vector<Appareil> appareils)
                    : Protocole::Messages::Reponse(BTTP_DEMANDE_APPAREILS, "")
                {
                    for (const Appareil& appareil : appareils)
                        this->ajouter_data(appareil.serialiser() + "\n");
                }

                const std::vector<Appareil> ReponseAppareils::appareils() const
                {
                    std::vector<Appareil> appareils;
                    const std::vector<std::string> liste = Protocole::Messages::decouper(this->data(), "\n");
                    for (const std::string& element : liste)
                        appareils.push_back(Appareil(element));
                    return appareils;
                }
            }
        }
    }
}