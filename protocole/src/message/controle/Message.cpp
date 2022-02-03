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
                        const std::string contenu, const Identite::ClePublique destinataire,
                        const Identite* signataire, const std::string mdp
                    )
                    : Messages::TMessage<T>(type)
                { this->initialiser(contenu, destinataire, signataire, mdp); }
                
                template <class T>
                TMessage<T>::TMessage(
                        T type, 
                        const IMessage* message, const Identite::ClePublique destinataire,
                        const Identite* signataire, const std::string mdp
                    )
                    : Messages::TMessage<T>(type)
                { this->initialiser(message == nullptr ? "" : message->construire(), destinataire, signataire, mdp); }

                template <class T>
                void TMessage<T>::initialiser(
                    const std::string contenu, const Identite::ClePublique destinataire,
                    const Identite* signataire, const std::string mdp
                )
                { 
                    this->_destinataire = destinataire.fingerprint();
                    this->_contenu = signataire->chiffrer(contenu, destinataire, mdp);
                }

                template <class T>
                const std::string TMessage<T>::construire() const
                { return this->type_c() + this->_destinataire + BTTP_MESSAGE_CONTROLE_SEP + this->entete() + BTTP_MESSAGE_CONTROLE_SEP + this->_contenu; }

                template <class T>
                void TMessage<T>::construction(const std::string contenu)
                {
                    const size_t debut_entete = contenu.find(BTTP_MESSAGE_CONTROLE_SEP);
                    this->_destinataire = contenu.substr(0, debut_entete);
                    const size_t fin_entete = contenu.find(BTTP_MESSAGE_CONTROLE_SEP, debut_entete + 1);
                    this->lire_entete(contenu.substr(debut_entete + 1, fin_entete - debut_entete - 1));
                    this->_contenu = contenu.substr(fin_entete + 1);
                }
            }
        }
    }
}