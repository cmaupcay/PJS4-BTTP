#include "../../include/serveurs/Script.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            Script::Script(const std::string serialisation)
            {
                const std::vector<std::string> elements = Protocole::Messages::decouper(serialisation, BTTP_MESSAGE_ARGS_SEP);
                if (elements.size() != 2) throw Protocole::Erreur::Messages::Deconstruction::Incomplet(serialisation, elements.size(), 2);
                this->_nom = elements[0];
                this->_id = (uint32_t)std::atol(elements[1].c_str());
            }
        }
    }
}