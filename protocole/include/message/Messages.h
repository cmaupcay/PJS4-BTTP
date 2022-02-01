#ifndef H_BTTP_MESSAGES
#define H_BTTP_MESSAGES

#include "Execution.h"
#include "ClePublique.h"

#include "erreur/type/Inconnu.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            Message* resoudre(const std::string paquet);
        }
    }
}

#endif