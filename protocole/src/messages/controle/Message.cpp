#include "../../../include/messages/controle/Message.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            namespace Controle
            {
                template <class _Type>
                TMessage<_Type>::TMessage(
                        const _Type type, 
                        const IMessage* message, const Cle::Publique destinataire,
                        const Identite* signataire, const std::string mdp
                    )
                    : Messages::TMessage<_Type>(type)
                { 
                    this->_destinataire = destinataire.empreinte();
                    this->_message = signataire->chiffrer(message->construire(), destinataire, mdp);
                }

                template <class _Type>
                TMessage<_Type>::TMessage(const _Type type, const std::string paquet)
                    : Messages::TMessage<_Type>(type, paquet)
                {}

                template <class _Type>
                const std::string TMessage<_Type>::construire() const
                { return this->type_c() + this->_destinataire + BTTP_MESSAGE_CONTROLE_SEP + this->entete() + BTTP_MESSAGE_CONTROLE_SEP + this->_message; }

                template <class _Type>
                void TMessage<_Type>::deconstruction(const std::string contenu)
                {
                    const std::vector<std::string> infos = Messages::decouper(contenu, BTTP_MESSAGE_CONTROLE_SEP);
                    if (infos.size() != 3); throw Erreur::Messages::Deconstruction::Incomplet(contenu, infos.size(), 3);
                    this->_destinataire = infos[0];
                    this->lire_entete(infos[1]);
                    this->_message = infos[2];
                }

                template class TMessage<Type>;
            }
        }
    }
}