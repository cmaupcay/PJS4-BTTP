#include "Message.h"

namespace BTTP
{
    namespace Protocole
    {
        class MessageControle
        {
        private:
            const unsigned short _id_terminal;

        public:
            MessageControle(const int id_terminal);

            inline const std::string construire(Message* message) const
            { return message->construire(); }
        }
    }
}