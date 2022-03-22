#include "../../include/message/Ouverture.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            Ouverture::Ouverture(const Cle::Publique cle)
                : BTTP::Protocole::Messages::Message(Type::OUVERTURE),
                _cible{ cle.write(OpenPGP::PGP::Armored::NO) }
            {}

            Ouverture::Ouverture()
                : BTTP::Protocole::Messages::Message(Type::OUVERTURE), _cible{ "" }
            {}

            Ouverture::Ouverture(const std::string paquet)
                : BTTP::Protocole::Messages::Message(Type::OUVERTURE, paquet), 
                _cible{ "" }
            {}

            const Cle::Publique Ouverture::cible() const
            {
                if (this->_cible == "") throw Erreur::Messages::Vide();
                return Cle::Publique(this->_cible);
            }
        }
    }
}