#ifndef H_BTTP_CLIENT_CONNEXION
#define H_BTTP_CLIENT_CONNEXION

#include "Racine.h"
#include "erreur/connexion/Fermee.h"
#include "erreur/connexion/Timeout.h"
#include "erreur/connexion/DejaOuverte.h"
#include "erreur/connexion/Resolution.h"
#include "erreur/connexion/Ouverture.h"
#include <chrono>
#include <asio.hpp>

namespace BTTP
{
    namespace Client
    {
        class Connexion : public Protocole::IConnexion
        {
            private:
                /** Socket de la connexion. */
                asio::ip::tcp::socket* _socket;
                /** Adresse de connexion. */
                const std::string _adresse;
                /** Port de connexion. */
                const uint16_t _port;
                /** pour la gestion des erreurs avec asio.*/
                asio::error_code _erreur;

            public:
                /**
                 * @brief Construction d'un nouvel objet représentant une connexion.
                 * @param adresse Adresse de connexion.
                 * @param port Port de connexion.
                 */
                Connexion(const std::string adresse, const uint16_t port);
                /**
                * @brief Vérifie si la connexion est ouverte.
                * @return true La connexion est ouverte.
                * @return false La connexion est fermée.
                */
                inline const bool ouverte() override 
                { return (this->_socket == nullptr ? false : this->_socket->is_open()); }
                /**
                * @brief Ouvre une nouvelle connexion.
                */
                void ouvrir() override;
                /**
                * @brief Ferme la connexion.
                */
                inline void fermer() override { this->_socket->close(); }
                /**
                * @brief Envoie un message sur la connexion.
                * @param message_prepare Le message à envoyer.
                */
                void envoyer(const std::string message_prepare) override;
                /**
                * @brief Reçoit un message depuis la connexion.
                * @return Retourne le message reçu.
                */
                const std::string recevoir() override;
        };
    }
}

#endif