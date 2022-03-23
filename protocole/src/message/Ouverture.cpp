#include "../../include/message/Ouverture.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            Ouverture::Ouverture(const Cle::Publique cle)
                : BTTP::Protocole::Messages::Message(Type::OUVERTURE),
                _cible{ cle.fingerprint() }
            {}

            Ouverture::Ouverture()
                : BTTP::Protocole::Messages::Message(Type::OUVERTURE),
                _cible{ "" }
            {}

            Ouverture::Ouverture(const std::string paquet)
                : BTTP::Protocole::Messages::Message(Type::OUVERTURE, paquet), 
                _cible{ "" }
            {}
        }
    }
}