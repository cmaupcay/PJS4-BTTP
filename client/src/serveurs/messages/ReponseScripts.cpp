#include "../../../include/serveurs/messages/ReponseScripts.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                ReponseScripts::ReponseScripts(const std::vector<Script> scripts)
                    : Protocole::Messages::Reponse(BTTP_DEMANDE_SCRIPTS, "")
                {
                    for (const Script& script : scripts)
                        this->ajouter_data(script.serialiser() + "\n");
                }

                const std::vector<Serveurs::Script> ReponseScripts::scripts() const
                {
                    std::vector<Serveurs::Script> scripts;
                    const std::vector<std::string> liste = Protocole::Messages::decouper(this->data(), "\n");
                    for (const std::string& element : liste)
                        scripts.push_back(Serveurs::Script(element));
                    return scripts;
                }
            }
        }
    }
}