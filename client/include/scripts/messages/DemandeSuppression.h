#ifndef H_BTTP_CLIENT_SCRIPT_MESSAGE_DEMANDE_SUPPRESSION
#define H_BTTP_CLIENT_SCRIPT_MESSAGE_DEMANDE_SUPPRESSION

#include "../Script.h"

/** Champs de demande correspondant à la suppression de script. */
#define BTTP_DEMANDE_SCRIPT_SUPPRESSION "src.suppr"
/** Nom de l'argument indiquant l'identifiant du script à supprimer'. */
#define BTTP_DEMANDE_SCRIPT_SUPPRESSION_ID "id"

namespace BTTP
{
    namespace Client
    {
        namespace Scripts
        {
            namespace Messages
            {
                class DemandeSuppression : public Protocole::Messages::Demande
                {
                public:
                    DemandeSuppression(const Scripts::Script& script)
                        : Protocole::Messages::Demande(
                            BTTP_DEMANDE_SCRIPT_SUPPRESSION,
                            { {
                                BTTP_DEMANDE_SCRIPT_SUPPRESSION_ID,
                                std::to_string(script.id())
                            } }
                        )
                    {}

                    inline const uint32_t id_script() const { return std::atoi(this->args()[0].valeur.c_str()); }
                };
            }
        }
    }
}

#endif