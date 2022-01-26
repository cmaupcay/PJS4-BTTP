#ifndef H_BTTP_MESSAGE_EXECUTION
#define H_BTTP_MESSAGE_EXECUTION

#include "Message.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            class Execution : public Message
            {
            private:
                uint16_t _id_script;
            };
        }
    }
}

#endif