#ifndef BTTP_CLIENT_SERVEUR
#define BTTP_CLIENT_SERVEUR

#include "../Racine.h"

namespace BTTP
{
    namespace Client
    {
        /**
         * @brief Représentation d'un serveur BTTP enregistré localement.
         */
        class Serveur
        {
        private:
            /** Nom d'affichage du serveur et nom du fichier local. */
            const std::string _nom;
            /** Adresse (nom d'hôte OU adresse IPv4 ou IPv6) du serveur. */
            std::string _adresse;
            /** Port de connexion à l'application BTTP. */
            uint16_t _port;

        public:
            /**
             * @brief Construction d'un nouvel objet représentant un serveur BTTP.
             * @param nom Nom d'affichage du serveur et nom du fichier local.
             * @param adresse Adresse du serveur.
             * @param port Port de connexion à l'application BTTP.
             */
            Serveur(const std::string nom, const std::string adresse, const uint16_t port = BTTP_PORT)
                : _nom{ nom }, _adresse{ adresse }, _port{ port }
            {}

            /**
             * @brief Retourne le nom d'affichage du serveur.
             * @return const std::string& Nom d'affichage du serveur.
             */
            inline const std::string& nom() const { return this->_nom; }

            /**
             * @brief Retourne l'adresse du serveur. Il peut s'agir d'un nom d'hôte ou d'une adresse IP.
             * @return const std::string& Adresse du serveur.
             */
            inline const std::string& adresse() const { return this->_adresse; }
            /**
             * @brief Modification de l'adresse du serveur.
             * @param adresse Nouvelle adresse du serveur. Il peut s'agir d'un nom d'hôte ou d'une adresse IP.
             */
            inline void modifier_adresse(const std::string adresse) { this->_adresse = adresse; }

            /**
             * @brief Retourne le port de connexion à l'application BTTP sur le serveur.
             * @return const uint16_t& Port de connexion BTTP.
             */
            inline const uint16_t& port() const { return this->_port; }
            /**
             * @brief Modification du port de connexion du serveur.
             * @param port Nouveau port de connexion à l'application BTTP sur le serveur.
             */
            inline void modifier_port(const uint16_t port) { this->_port = port; }

            inline friend std::ostream& operator<<(std::ostream& os, const Serveur& srv) 
            { return (os << srv.nom() + " (" + srv.adresse() + ':' + std::to_string(srv.port()) + ')'); }
        };
    }
}

#endif