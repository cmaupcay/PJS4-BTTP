#ifndef H_BTTP_SERVEUR_SESSIONS_GESTIONNAIRE
#define H_BTTP_SERVEUR_SESSIONS_GESTIONNAIRE

#include "../Journal.h"
#include "ISession.h"

#define BTTP_SERVEUR_COMPOSANT_SESSIONS_GESTIONNAIRE BTTP_SERVEUR_COMPOSANT_SESSIONS "Gestionnaire"

namespace BTTP
{
    namespace Serveur
    {
        namespace Sessions
        {
            class Gestionnaire
            {
            private:
                const std::unique_ptr<Client::Contexte>& _contexte;
                std::vector<ISession*> _sessions;

                const size_t index_session(const std::string& empreinte) const;

            public:
                Gestionnaire(const std::unique_ptr<Client::Contexte>& contexte)
                    : _contexte{ contexte }
                {}

                inline const size_t sessions() const { return this->_sessions.size(); }

                const size_t ajout_session(ISession* session);
                // TODO Suppression session avec plus de vérifications.
                inline void supprimer_session(const size_t id) { this->_sessions.erase(this->_sessions.begin() + id); }
                const ISession& session(const std::string empreinte) const;
                void fermer();
            };
        }
    }
}

#endif