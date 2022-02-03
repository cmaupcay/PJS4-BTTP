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
                        const IMessage* message, const Identite::ClePublique destinataire,
                        const Identite* signataire, const std::string mdp
                    )
                    : Messages::TMessage<T>(type)
                {
                    this->_destinataire = destinataire.fingerprint();
                    if (message != nullptr)
                        this->_contenu = charger_contenu(message, destinataire, signataire, mdp);
                    else this->_contenu = "";
                }

                template <class T>
                const std::string TMessage<T>::charger_contenu(
                    const IMessage* message, const Identite::ClePublique destinataire,
                    const Identite* signataire, const std::string mdp
                )
                { return signataire->chiffrer(message->construire(), destinataire, mdp); }

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