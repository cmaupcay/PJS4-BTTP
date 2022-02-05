#ifndef H_BTTP_MESSAGES_CONTROLE
#define H_BTTP_MESSAGES_CONTROLE

#include "Message.h"

#include "../erreur/type/Inconnu.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            namespace Controle
            {
                // TOTEST
                // TOCOMMENT
                Message* resoudre(const std::string paquet);
            }
        }
    }
}

#endif