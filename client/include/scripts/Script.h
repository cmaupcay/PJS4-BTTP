#ifndef H_BTTP_CLIENT_SCRIPT
#define H_BTTP_CLIENT_SCRIPT

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
            const std::string _nom;
        
        public:
            /**
             * @brief Construction d'un nouveau script depuis ses métadonnées.
             * @note Correspond à l'ajout d'un nouveau script.
             * @param serveur Serveur de référence.
             * @param id Identifiant numérique unique et commun avec le serveur.
             * @param nom Nom d'affichage du script.
             */
            Script(const Serveur& serveur, const uint64_t id, const std::string nom);

            /**
             * @brief Construction d'un script depuis son nom de référence.
             * @param reference 
             */
            Script(const std::string reference);

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

            /**
             * @brief Retourne le nom de référence du script, qui est utilisé comme nom de fichier.
             * @return const std::string Nom de référence du script.
             */
            inline const std::string reference() const
            { return this->_serveur.nom() + '/' + std::to_string(this->_id) + '.' + this->_nom; }

            inline friend std::ostream& operator<<(std::ostream& os, const Script& script) 
            { return (os << script.reference()); }
        };
    }
}

#endif