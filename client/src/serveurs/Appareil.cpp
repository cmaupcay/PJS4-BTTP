#include "../../include/serveurs/Appareil.h"

namespace BTTP
{
    namespace Client
    {
        Appareil::Appareil(const std::string serialisation)
        {
            const std::vector<std::string> elements = Protocole::Messages::decouper(serialisation, BTTP_MESSAGE_ARGS_SEP);
            if (elements.size() != 2) throw Protocole::Erreur::Messages::Deconstruction::Incomplet(serialisation, elements.size(), 2);
            this->_nom = elements[0];
            this->_cle = new Protocole::Cle::Publique(elements[1]);
        }
    }
}