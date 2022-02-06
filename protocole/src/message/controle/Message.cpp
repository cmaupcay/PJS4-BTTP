#include "../../../include/message/controle/Message.h"

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
                        _Type type, 
                        const std::string contenu, const Cle::Publique destinataire,
                        const Identite* signataire, const std::string mdp
                    )
                    : Messages::TMessage<_Type>(type)
                { this->initialiser(contenu, destinataire, signataire, mdp); }
                
                template <class _Type>
                TMessage<_Type>::TMessage(
                        _Type type, 
                        const IMessage* message, const Cle::Publique destinataire,
                        const Identite* signataire, const std::string mdp
                    )
                    : Messages::TMessage<_Type>(type)
                { this->initialiser(message == nullptr ? "" : message->construire(), destinataire, signataire, mdp); }

                template <class _Type>
                void TMessage<_Type>::initialiser(
                    const std::string contenu, const Cle::Publique destinataire,
                    const Identite* signataire, const std::string mdp
                )
                { 
                    // TODO Un autre moyen d'identifier le destinataire ?
                    this->_destinataire = destinataire.fingerprint();
                    this->_contenu = signataire->chiffrer(contenu, destinataire, mdp);
                }

                template <class _Type>
                const std::string TMessage<_Type>::construire() const
                { return this->type_c() + this->_destinataire + BTTP_MESSAGE_CONTROLE_SEP + this->entete() + BTTP_MESSAGE_CONTROLE_SEP + this->_contenu; }

                template <class _Type>
                void TMessage<_Type>::deconstruction(const std::string contenu)
                {
                    const std::vector<std::string> infos = Messages::decouper(contenu, BTTP_MESSAGE_CONTROLE_SEP);
                    if (infos.size() != 3); throw Erreur::Messages::Deconstruction::Incomplet(contenu, infos.size(), 3);
                    this->_destinataire = infos[0];
                    this->lire_entete(infos[1]);
                    this->_contenu = infos[2];
                }

                template class TMessage<Type>;
            }
        }
    }
}