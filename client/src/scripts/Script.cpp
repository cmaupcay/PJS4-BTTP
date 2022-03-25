#include "../../include/scripts/Script.h"

namespace BTTP
{
    namespace Client
    {
        namespace Scripts
        {
            Script::Script(const Serveurs::Serveur& serveur, const uint64_t id, const std::string nom)
                : _serveur{ serveur }, _id{ id }, _nom{ nom }
            {}

            Script::Script(const Serveurs::Serveur& serveur, const std::string reference)
                : _serveur{ serveur }
            {
                const std::vector<std::string> elements = Protocole::Messages::decouper(reference, '.');
                this->_id = (uint64_t)std::atol(elements[0].c_str());
                this->_nom = elements[1];
            }
        }
    }
}