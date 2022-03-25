#include "../../include/messages/ClePublique.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            ClePublique::ClePublique(const Cle::Publique cle)
                : BTTP::Protocole::Messages::Message(Type::CLE_PUBLIQUE),
                _cle{ cle.write(OpenPGP::PGP::Armored::NO) }
            {}

            ClePublique::ClePublique()
                : BTTP::Protocole::Messages::Message(Type::CLE_PUBLIQUE),
                _cle{ "" }
            {}

            ClePublique::ClePublique(const std::string paquet)
                : BTTP::Protocole::Messages::Message(Type::CLE_PUBLIQUE, paquet), 
                _cle{ "" }
            {}

            const Cle::Publique ClePublique::cle() const
            {
                if (this->_cle == "") throw Erreur::Messages::Vide();
                return Cle::Publique(this->_cle);
            }
        }
    }
}