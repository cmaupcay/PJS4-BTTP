#include "../../include/messages/Reponse.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            Reponse::Reponse(const std::string champs, const std::string data)
                : BTTP::Protocole::Messages::Message(Type::REPONSE),
                _champs{ champs }, _data{ data }
            {}

            Reponse::Reponse()
                : BTTP::Protocole::Messages::Message(Type::REPONSE), 
                _champs{ "" }, _data{ "" }
            {}

            Reponse::Reponse(const std::string paquet)
                : BTTP::Protocole::Messages::Message(Type::REPONSE, paquet), 
                _champs{ "" }, _data{ "" }
            {}

            const std::string Reponse::contenu() const
            // TOFIX Remplacer les occurences du séparateur dans _data.
            { return this->_champs + BTTP_MESSAGE_SEP + this->_data; }

            void Reponse::deconstruction(const std::string contenu)
            {
                // Découpage selon le séparateur des messages BTTP standards.
                const std::vector<std::string> elements = decouper(contenu, BTTP_MESSAGE_SEP);
                if (elements.size() != 2) throw Erreur::Messages::Deconstruction::Incomplet(contenu, elements.size(), 2);
                // Enregistrement des informations
                this->_champs = elements[0];
                this->_data = elements[1];
            }
        }
    }
}