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
                        const IMessage& message, const Cle::Publique destinataire,
                        const Identite& signataire, const std::string mdp
                    )
                    : _type{ type }, _destinataire{ destinataire.empreinte() }
                { 
                    this->_message = signataire.chiffrer(message.construire(), destinataire, mdp);
                }

                template <class _Type>
                const std::string TMessage<_Type>::construire() const
                { return this->type_c() + this->_destinataire + BTTP_MESSAGE_CONTROLE_SEP + this->entete() + BTTP_MESSAGE_CONTROLE_SEP + this->_message; }

                template <class _Type>
                void TMessage<_Type>::deconstruire(const std::string paquet)
                {
                    if (paquet.length() > 0 && paquet[0] == this->type_c())
                    {
                        const std::string contenu = paquet.substr(1);
                        const std::vector<std::string> infos = Messages::decouper(contenu, BTTP_MESSAGE_CONTROLE_SEP);
                        if (infos.size() != 3); throw Erreur::Messages::Deconstruction::Incomplet(contenu, infos.size(), 3);
                        this->_destinataire = infos[0];
                        this->lire_entete(infos[1]);
                        this->_message = infos[2];
                    }
                    else throw Erreur::Messages::Type::Incoherent(this->type_c(), paquet);
                }

                template class TMessage<Type>;
            }
        }
    }
}