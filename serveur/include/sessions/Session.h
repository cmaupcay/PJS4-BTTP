#ifndef H_BTTP_SERVEUR_SESSION
#define H_BTTP_SERVEUR_SESSION

#include "Gestionnaire.h"
#include "../data/terminal/Distant.h"
#include "../data/Source.h"
#define BTTP_SERVEUR_COMPOSANT_SESSIONS_SESSION BTTP_SERVEUR_COMPOSANT_SESSIONS "Session"

namespace BTTP
{
    namespace Serveur
    {
        namespace Sessions
        {
            class Session : public _Session
            {
            private:
                const std::unique_ptr<Gestionnaire>& _gestionnaire;

                const bool authentification();
                const bool inscription(const std::string empreinte);

                void mode_distant(const std::string& mdp);
                void mode_client(const std::string& mdp, const Protocole::Messages::Demande& demande_initiale);

                void lancer() override;

            public:
                Session(
                    const std::unique_ptr<Client::Contexte>& contexte,
                    std::unique_ptr<Data::Source>& source, std::shared_ptr<Client::Connexion> connexion,
                    const std::unique_ptr<Gestionnaire>& gestionnaire
                )
                    : _Session(contexte, source, connexion), _gestionnaire{ gestionnaire }
                {}
            };
        }
    }
}

#endif