#ifndef H_BTTP_CLIENT_SERVEUR
#define H_BTTP_CLIENT_SERVEUR

#include "../Connexion.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
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
                /** Clé publique du serveur. */
                const Protocole::Cle::Publique* _cle;
                /** Connexion réseau avec le serveur. */
                Protocole::IConnexion* _connexion;

            public:
                /**
                 * @brief Construction d'un nouvel objet représentant un serveur BTTP.
                 * @param nom Nom d'affichage du serveur et nom du fichier local.
                 * @param adresse Adresse du serveur.
                 * @param port Port de connexion à l'application BTTP.
                 */
                Serveur(const std::string nom, const std::string adresse, const uint16_t port)
                    : _nom{ nom }, _adresse{ adresse }, _port{ port }, _cle{ nullptr },
                    _connexion{ new Connexion(adresse, port) }
                {}
                // TOTEST
                /**
                 * @brief Construction d'un objet serveur depuis un objet serveur sérialisé.
                 * @param nom Nom d'affichage du serveur et nom du fichier local.
                 * @param serialisation Informations sérialisées du serveur.
                 */
                Serveur(const std::string nom, const std::string serialisation);

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

                /**
                 * @brief Retourne la clé publique du serveur.
                 * @return const Cle::Publique& Clé publique du serveur.
                 */
                inline const Protocole::Cle::Publique& cle() const { return *this->_cle; }
                /**
                 * @brief Modification de la clé publique du serveur.
                 * @param cle Clé publique du serveur.
                 */
                inline void modifier_cle(const Protocole::Cle::Publique* cle) { this->_cle = cle; }

                inline Protocole::IConnexion* connexion() const { return this->_connexion; }

                /**
                 * @brief Sérialisation des informations du serveur. Utilisé lors de l'export dans un fichier notamment.
                 * @return const std::string Informations sérialisées du serveur.
                 */
                const std::string serialiser() const;

                inline const std::string informations() const
                { return this->_nom + " (" + this->_adresse + ':' + std::to_string(this->_port) + ')'; }

                inline friend std::ostream& operator<<(std::ostream& os, const Serveur& srv) 
                { return (os << srv.informations()); }
            };
        }
    }
}

#endif