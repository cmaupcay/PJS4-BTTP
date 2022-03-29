#ifndef H_BTTP_CLIENT_SCRIPT_MESSAGE_DEMANDE_DISTANT
#define H_BTTP_CLIENT_SCRIPT_MESSAGE_DEMANDE_DISTANT

#include "../../Racine.h"

/** Champs de demande correspondant au démarrage du mode distant. */
#define BTTP_DEMANDE_DISTANT "distant"

namespace BTTP
{
    namespace Client
    {
        namespace Transactions
        {
            namespace Messages
            {
                class DemandeDistant : public Protocole::Messages::Demande
                {
                public:
                    DemandeDistant()
                        : Protocole::Messages::Demande(
                            BTTP_DEMANDE_DISTANT
                        )
                    {}
                };
            }
        }
    }
}

#endif