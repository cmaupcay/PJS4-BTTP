#include "../../include/message/Ouverture.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            Ouverture::Ouverture(const Cle::Publique cible, const Cle::Publique client)
                : BTTP::Protocole::Messages::Message(Type::OUVERTURE),
                _cible{ cible.fingerprint() }, _client{ client.write(OpenPGP::PGP::Armored::NO) }
            {}

            Ouverture::Ouverture()
                : BTTP::Protocole::Messages::Message(Type::OUVERTURE),
                _cible{ "" }, _client{ "" }
            {}

            Ouverture::Ouverture(const std::string paquet)
                : BTTP::Protocole::Messages::Message(Type::OUVERTURE, paquet), 
                _cible{ "" }, _client{ "" }
            {}

            //TOTEST
            const std::string Ouverture::contenu() const 
            { return this->_cible + BTTP_MESSAGE_SEP + this->_client; }

            //TOTEST
            void Ouverture::deconstruction(const std::string contenu) 
            {
                // Découpage selon le séparateur des messages BTTP standards.
                const std::vector<std::string> elements = decouper(contenu, BTTP_MESSAGE_SEP);
                if (elements.size() != 2) throw Protocole::Erreur::Messages::Deconstruction::Incomplet(contenu, elements.size(), 2);
                // Enregistrement des informations.
                this->_cible = elements[0];
                this->_client = elements[1];
            }

            const Cle::Publique Ouverture::client() const
            {
                if (this->_client == "") throw Erreur::Messages::Vide();
                return Cle::Publique(this->_client);
            }
        }
    }
}