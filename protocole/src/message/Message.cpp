#include "../../include/message/Message.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            template <class T>
            const std::string TMessage<T>::construire() const
            {
                return (static_cast<char>(this->_type) + this->contenu());
            }
        }
    }
}