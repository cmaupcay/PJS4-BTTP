#ifndef BTTP_CLIENT_SCRIPT
#define BTTP_CLIENT_SCRIPT

#include "../serveurs/Serveur.h"

namespace BTTP
{
    namespace Client
    {
        class Script
        {
        private:
            /** Serveur de référence du script. */
            const Serveur& _serveur;
            /** Identifiant numérique du script commun avec le serveur. */
            const uint64_t _id;
            /** Nom d'affichage du script. */
            std::string _nom;
        
        public:
            Script(const Serveur& serveur, const uint64_t id, const std::string nom);

            /**
             * @brief Retourne le serveur de référence du script.
             * @return const Serveur& Serveur de référence du script.
             */
            inline const Serveur& serveur() const { return this->_serveur; }

            /**
             * @brief Retourne l'identifiant numérique UNIQUE du script et commun avec le serveur.
             * @return const uint64_t& Identifiant numérique du script.
             */
            inline const uint64_t& id() const { return this->_id; }
            /**
             * @brief Retourne le nom d'affichage du script.
             * @return const std::string& Nom d'affichage du script.
             */
            inline const std::string& nom() const { return this->_nom; }

            inline friend std::ostream& operator<<(std::ostream& os, const Script& script) 
            { return (os << script.serveur().nom() + '/' + script.nom()); }
        };
    }
}

#endif