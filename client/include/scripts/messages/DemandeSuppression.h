#ifndef H_BTTP_CLIENT_SCRIPTS_MESSAGE_DEMANDE_SUPPRESSION
#define H_BTTP_CLIENT_SCRIPTS_MESSAGE_DEMANDE_SUPPRESSION

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
                    DemandeSuppression(const Script& script)
                        : Protocole::Messages::Demande(
                            BTTP_DEMANDE_SCRIPT_SUPPRESSION,
                            { {
                                BTTP_DEMANDE_SCRIPT_SUPPRESSION_ID,
                                std::to_string(script.id())
                            } }
                        )
                    {}
                };
            }
        }
    }
}

#endif