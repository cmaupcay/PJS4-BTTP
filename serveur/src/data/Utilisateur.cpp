#include "../../include/data/Utilisateur.h"

namespace BTTP
{
    namespace Serveur
    {
        namespace Data
        {
            const bool Utilisateur::existe_sans_id() const
            {
                return false;
            }
            const bool Utilisateur::existe_depuis_id() const
            {
                return false;
            }

            const bool Utilisateur::mettre_a_jour_sans_id()
            {
                return false;
            }
            const bool Utilisateur::mettre_a_jour_depuis_id()
            {
                return false;
            }

            const bool Utilisateur::authentification(const std::string mdp)
            {
                return false;
            }
        }
    }
}