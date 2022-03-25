#ifndef H_BTTP_CLIENT_SCRIPTS_MESSAGE_REPONSE_AJOUT
#define H_BTTP_CLIENT_SCRIPTS_MESSAGE_REPONSE_AJOUT

#include "DemandeAjout.h"

namespace BTTP
{
    namespace Client
    {
        namespace Scripts
        {
            namespace Messages
            {
                class ReponseAjout : public Protocole::Messages::Reponse
                {
                public:
                    ReponseAjout(const uint64_t id_script)
                        : Protocole::Messages::Reponse(
                            BTTP_DEMANDE_SCRIPT_AJOUT,
                            std::to_string(id_script)
                        )
                    {}

                    ReponseAjout(const std::string paquet)
                        : Protocole::Messages::Reponse(paquet)
                    {}

                    inline const uint64_t id_script() const { return std::atol(this->data().c_str()); }
                };
            }
        }
    }
}

#endif