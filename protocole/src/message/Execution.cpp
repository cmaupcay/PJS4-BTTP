#include "../../include/message/Execution.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            Execution::Execution(const uint32_t id_script)
                : Message(Type::EXECUTION)
            {
                this->_id = new uint32_t(std::rand());
                this->_id_script = new uint32_t(id_script);
            }

            Execution::Execution()
                : Message(Type::EXECUTION),
                _id{ nullptr }, _id_script{ nullptr }
            {}

            Execution::Execution(const std::string paquet)
                : Message(Type::EXECUTION, paquet),
                _id{ nullptr }, _id_script{ nullptr }
            {}

            Execution::~Execution()
            {
                delete this->_id, this->_id_script;
                this->_args.~vector();
            }

            const std::string Execution::contenu() const
            {
                std::string contenu = std::to_string(*this->_id) + BTTP_MESSAGE_SEP + std::to_string(*this->_id_script) + BTTP_MESSAGE_SEP;
                const std::vector<std::string> args = joindre_args(this->_args);
                contenu += joindre(args, BTTP_MESSAGE_SEP);
                return contenu;
            }

            void Execution::deconstruction(const std::string contenu)
            {
                // Découpage selon le séparateur des messages BTTP standards.
                const std::vector<std::string> elements = decouper(contenu, BTTP_MESSAGE_SEP);
                if (elements.size() < 2) throw Erreur::Messages::Deconstruction::Incomplet(contenu, elements.size(), 2);
                // Enregistrement des informations
                if (this->_id != nullptr) delete this->_id;
                this->_id = new uint32_t(std::atoi(elements[0].c_str()));
                if (this->_id_script != nullptr) delete this->_id_script;
                this->_id_script = new uint32_t(std::atoi(elements[1].c_str()));
                std::vector<std::string> args = std::vector<std::string>(elements.begin() + 2, elements.end());
                this->_args = decouper_args(args);
            }
        }
    }
}