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
                            // TODO Classes des types de message de contrôle
                        default:
                            throw Erreur::Messages::Type::Inconnu(paquet);
                        }
                    return nullptr;
                }

                Message* generer(const Messages::Message& message, const Cle::Publique destinataire, const Identite* signataire, const std::string mdp)
                {
                    switch (message.type())
                    {
                    // TODO Classes des types de messages de contrôle
                    default:
                        throw Erreur::Messages::Controle::Inconnu(message);
                    }
                    return nullptr;
                }
            }
        }
    }
}