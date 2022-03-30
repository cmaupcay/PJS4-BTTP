#include "../../../include/data/terminal/Client.h"

namespace BTTP
{
    namespace Serveur
    {
        namespace Data
        {
            namespace Terminal
            {
                const bool Client::existe_sans_id() const
                {
                    return false;
                }
                const bool Client::existe_depuis_id() const
                {
                    return false;
                }

                const bool Client::mettre_a_jour_sans_id()
                {
                    return false;
                }
                const bool Client::mettre_a_jour_depuis_id()
                {
                    return false;
                }
            }
        }
    }
}