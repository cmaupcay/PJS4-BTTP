#include "../../../include/message/controle/Message.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            namespace Controle
            {
                template <class T>
                TMessage<T>::TMessage(
                        T type, 
                        const IMessage& message, const Identite::ClePublique destinataire,
                        const Identite* sigantaire, const std::string mdp
                    )
                    : TMessage<T>(type)
                {
                    this->_contenu = charger_contenu(message, destinataire, sigantaire, mdp);
                }

                template <class T>
                const std::string TMessage<T>::charger_contenu(
                    const IMessage& message, const Identite::ClePublique destinataire,
                    const Identite* sigantaire, const std::string mdp
                )
                { return sigantaire->chiffrer(message.construire(), destinataire, mdp); }

                template <class T>
                const std::string TMessage<T>::construire() const
                { return this->type_c() + this->entete() + this->_contenu; }
            }
        }
    }
}