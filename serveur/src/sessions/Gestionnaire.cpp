#include "../../include/sessions/Gestionnaire.h"

namespace BTTP
{
    namespace Serveur
    {
        namespace Sessions
        {
            const size_t Gestionnaire::index_session(const std::string& empreinte) const
            {
                const size_t n = this->_sessions.size();
                for (int s = 0; s < n; s++)
                    if (this->_sessions[s]->client()->empreinte() == empreinte) return s;
                return n;
            }

            const size_t Gestionnaire::ajout_session(ISession* session)
            {
                Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_GESTIONNAIRE, "Ajout d'une nouvelle session...");
                const size_t s = this->index_session(session->client()->empreinte());
                const size_t n = this->_sessions.size();
                if (s >= n)
                {
                    this->_sessions.push_back(session);
                    Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_GESTIONNAIRE, "Nouvelle session ajoutée.");
                    return n;
                }
                // else throw // TODO Erreur::SessionDejaExistante(empreinte);
            }
            
            const ISession& Gestionnaire::session(const std::string empreinte) const
            {
                Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_GESTIONNAIRE, "Recherche de l'empreinte \"" + empreinte + "\"...");
                const size_t s = this->index_session(empreinte);
                if (s < this->_sessions.size()) return *this->_sessions[s];
                // else throw // TODO Erreur::SessionInexistante(empreinte);
            }

            void Gestionnaire::fermer()
            {
                Journal::ecrire(BTTP_SERVEUR_COMPOSANT_SESSIONS_GESTIONNAIRE, "Fermeture des sessions...");
                for (ISession* session : this->_sessions)
                    if (session->thread().joinable())
                        session->thread().join();
            }
        }
    }
}