#ifndef H_BTTP_CLIENT_DISTANT
#define H_BTTP_CLIENT_DISTANT

#include <thread>

#include "serveurs/Serveur.h"
#include "transactions/Distant.h"

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

            void processus(const std::string mdp) noexcept;

        public:
            Distant(
                const Protocole::Identite& identite, const Serveurs::Serveur& serveur,
                const std::vector<std::string>& cles_autorisees
            )
                : _identite{ identite }, _serveur{ serveur }, _cles_autorisees{ cles_autorisees }
            {}

            inline const Protocole::Identite& identite() const { return this->_identite; }
            inline const Serveurs::Serveur& serveur() const { return this->_serveur; }
        };
    }
}

#endif