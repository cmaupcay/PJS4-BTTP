#include "../../include/message/ClePublique.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            const Cle::Publique ClePublique::cle() const
            {
                if (this->_cle == BTTP_MESSAGE_CLE_PUBLIQUE_VIDE)
                    throw Erreur::Messages::Vide();
                return Cle::Publique(this->_cle);
            }
        }
    }
}