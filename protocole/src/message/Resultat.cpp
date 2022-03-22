#include "../../include/message/Resultat.h"

namespace BTTP 
{
    namespace Protocole
    {
        namespace Messages
        {
            // TOTEST
            Resultat::Resultat(const uint32_t id, const std::string data)
                : Message(Type::RESULTAT),
                _id{ new uint32_t(id) }, _resultat{ data }
            {}

            //TOTEST
            Resultat::Resultat() 
                : Message(Type::RESULTAT),
                _id{ nullptr }, _resultat{ "" }
            {}

            //TOTEST
            Resultat::Resultat(const std::string paquet)
                : Message(Type::RESULTAT, paquet),
                _id{ nullptr }, _resultat { "" }
            {}

            //TOTEST
            const std::string Resultat::contenu() const 
            { return std::to_string(*this->_id) + BTTP_MESSAGE_SEP + this->_resultat; }

            //TOTEST
            void Resultat::deconstruction(const std::string contenu) 
            {
                // Découpage selon le séparateur des messages BTTP standards.
                const std::vector<std::string> elements = decouper(contenu, BTTP_MESSAGE_SEP);
                if (elements.size() < 2) throw Erreur::Messages::Deconstruction::Incomplet(contenu, elements.size(), 2);

                // Enregistrement des informations.
                if (this->_id != nullptr) delete this->_id;
                this->_id = new uint32_t(std::atoi(elements[0].c_str()));

                this->_resultat = elements[1];
            }
        }
    }
}