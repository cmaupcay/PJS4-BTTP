#ifndef H_BTTP_SERVEUR_ACCEPTEUR
#define H_BTTP_SERVEUR_ACCEPTEUR

#include "sessions/Gestionnaire.h"
#include "sessions/Session.h"

#define BTTP_SERVEUR_COMPOSANT_ACCEPTEUR "Accepteur"

namespace BTTP
{
    namespace Serveur
    {
        class Accepteur
        {
        private:
            const uint16_t _port;
            const std::unique_ptr<Client::Contexte>& _contexte;
            std::unique_ptr<Sessions::Gestionnaire>& _sessions;
            std::unique_ptr<Data::Source>& _source;

        public:
            Accepteur(
                const uint16_t port, const std::unique_ptr<Client::Contexte>& contexte,
                std::unique_ptr<Data::Source>& source, std::unique_ptr<Sessions::Gestionnaire>& sessions
            )
                : _port{ port }, _contexte{ contexte }, _source{ source }, _sessions{ sessions }
            {}

            inline const uint16_t& port() const { return this->_port; }

            void lancer();
        };
    }
}

#endif