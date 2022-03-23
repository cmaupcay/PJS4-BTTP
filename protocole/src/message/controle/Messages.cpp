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
                        case Type::OUVERTURE:
                            return new Ouverture(paquet);
                        case Type::RELAIS:
                            return new Relais(paquet);
                        case Type::EXECUTION:
                            return new Execution(paquet);
                        default:
                            throw Erreur::Messages::Type::Inconnu(paquet);
                        }
                    return nullptr;
                }

                Message* generer(const IMessage* message, const Cle::Publique destinataire, const Identite* signataire, const std::string mdp)
                {
                    switch (message->type_c())
                    {
                    case static_cast<char>(Messages::Type::OUVERTURE):
                        return new Ouverture(message, destinataire, signataire, mdp);
                    case static_cast<char>(Messages::Type::EXECUTION):
                        return new Execution(message, destinataire, signataire, mdp);
                    default:
                        return new Relais(message, destinataire, signataire, mdp);
                    }
                    return nullptr;
                }
            }
        }
    }
}