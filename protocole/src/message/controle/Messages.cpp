#include "../../../include/message/controle/Messages.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            namespace Controle
            {
                Message* resoudre(const std::string paquet)
                {
                    if (paquet.length() > 0)
                        switch (static_cast<Type>(paquet[0]))
                        {
                            // TODO Classes des types de message
                        default:
                            throw Erreur::Messages::Type::Inconnu(paquet);
                        }
                    return nullptr;
                }
            }
        }
    }
}