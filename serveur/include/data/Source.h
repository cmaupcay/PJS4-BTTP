#ifndef H_BTTP_SERVEUR_DATA_SOURCE
#define H_BTTP_SERVEUR_DATA_SOURCE

#include "../Racine.h"

#define BTTP_DATA_SQL_BASE "bttp"
#define BTTP_DATA_SQL_HOTE "bd.bttp.resrc.club"
#define BTTP_DATA_SQL_PORT 0x14 // TODO Je sais plus deso
#define BTTP_DATA_SQL_UTILISATEUR "" // TODO Idenitifiant
#define BTTP_DATA_SQL_MDP "" // TODO Mot de passe (voir comment le masquer eventuellement, ou le demander au demarrage ?)

namespace BTTP
{
    namespace Serveur
    {
        namespace Data
        {
            // TODO Implémentation SQL
            class Source
            {
            private:
                const std::unique_ptr<Client::Contexte>& _contexte;

            public:
                Source(const std::unique_ptr<Client::Contexte>& contexte)
                    : _contexte{ contexte }
                {}  
            };
        }
    }
}

#endif