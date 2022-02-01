#include "../../include/message/Messages.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            Message* resoudre(const std::string paquet)
            {
                Message* msg = nullptr;
                
                if (paquet.length() > 0)
                    switch (static_cast<Type>(paquet[0]))
                    {
                    
                    default:
                        break;
                    }

                if (msg != nullptr) msg->deconstruire(paquet);
                else throw Erreur::Messages_Type_Inconnu(paquet);
                return msg;
            }
        }
    }
}