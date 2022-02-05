#include "../../include/message/Messages.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            Message* resoudre(const std::string paquet)
            {
                if (paquet.length() > 0)
                    switch (static_cast<Type>(paquet[0]))
                    {
                    case Type::CLE_PUBLIQUE:
                        return new ClePublique(paquet);
                    case Type::EXECUTION:
                        return new Execution(paquet);
                    // TODO Classes des types de message
                    default:
                        throw Erreur::Messages::Type::Inconnu(paquet);
                    }
                return nullptr;
            }
        }
    }
}