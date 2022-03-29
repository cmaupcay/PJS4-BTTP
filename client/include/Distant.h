#ifndef H_BTTP_CLIENT_DISTANT
#define H_BTTP_CLIENT_DISTANT

#include "serveurs/Serveur.h"
#include "transactions/Distant.h"
#include "transactions/messages/DemandeDistant.h"

namespace BTTP
{
    namespace Client
    {
        // TODO A terminer
        class Distant
        {
        private:
            const Protocole::Identite& _identite;
            const Serveurs::Serveur& _serveur;
            const std::vector<std::string>& _cles_autorisees;

            void annonce(const std::string mdp);

            std::string _status;

        public:
            Distant(
                const Protocole::Identite& identite, const Serveurs::Serveur& serveur,
                const std::vector<std::string>& cles_autorisees
            )
                : _identite{ identite }, _serveur{ serveur }, _cles_autorisees{ cles_autorisees }
            {}

            void processus(const std::string mdp);
            inline const std::string& status() const { return this->_status; }

            inline const Protocole::Identite& identite() const { return this->_identite; }
            inline const Serveurs::Serveur& serveur() const { return this->_serveur; }
        };
    }
}

#endif