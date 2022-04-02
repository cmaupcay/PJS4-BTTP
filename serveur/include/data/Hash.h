#ifndef H_BTTP_SERVEUR_DATA_HASH
#define H_BTTP_SERVEUR_DATA_HASH

#include <openssl/sha.h>
#include <sstream>
#include "iomanip"

namespace BTTP
{
    namespace Serveur
    {
        namespace Data
        {
            namespace Hash
            {

                /**
                 * @brief Pour hasher à l'aide de sha256
                 * 
                 * @param message message à hasher 
                 * @return const std::string le hash calculé 
                 */
                const std::string sha256(const std::string message);

            }
        }
    }
}


#endif