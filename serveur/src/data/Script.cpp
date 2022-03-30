#include "../../include/data/Script.h"

namespace BTTP
{
    namespace Serveur
    {
        namespace Data
        {
            const bool Script::existe_sans_id() const
            {
                return false;
            }
            const bool Script::existe_depuis_id() const
            {
                return false;
            }

            const bool Script::mettre_a_jour_sans_id()
            {
                return false;
            }
            const bool Script::mettre_a_jour_depuis_id()
            {
                return false;
            }

            const bool Script::verifier_acces(const Utilisateur& utilisateur) const
            {
                return false;
            }
        }
    }
}