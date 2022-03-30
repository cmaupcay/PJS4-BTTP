#include "../../include/messages/Fermeture.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            Fermeture::Fermeture()
                : BTTP::Protocole::Messages::Message(Type::FERMETURE), 
                _message{ BTTP_MESSAGE_FERMETURE_MESSAGE_DEFAUT }
            {}

            Fermeture::Fermeture(const std::string paquet)
                : BTTP::Protocole::Messages::Message(Type::FERMETURE),
                _message{ BTTP_MESSAGE_FERMETURE_MESSAGE_DEFAUT }
            { this->deconstruire(paquet); }
        }
    }
}