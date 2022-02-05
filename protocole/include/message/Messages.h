#ifndef H_BTTP_MESSAGES
#define H_BTTP_MESSAGES

#include "ClePublique.h"
#include "Execution.h"

#include "erreur/type/Inconnu.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            // TOTEST
            // TOCOMMENT
            Message* resoudre(const std::string paquet);
        }
    }
}

#endif