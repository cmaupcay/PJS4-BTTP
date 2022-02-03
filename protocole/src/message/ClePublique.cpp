#include "../../include/message/ClePublique.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            const Identite::ClePublique ClePublique::cle() const
            {
                if (this->_cle == BTTP_MESSAGE_CLE_PUBLIQUE_VIDE)
                    throw Erreur::ClePublique_Vide();
                return Identite::ClePublique(this->_cle);
            }
        }
    }
}