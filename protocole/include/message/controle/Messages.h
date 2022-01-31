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
                Message* resoudre(const std::string paquet);
            }
        }
    }
}

#endif