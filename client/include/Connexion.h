#ifndef H_BTTP_CLIENT_CONNEXION
#define H_BTTP_CLIENT_CONNEXION

#include "Racine.h"
#include "serveurs/Serveur.h"
#include "erreur/connexion/Fermee.h"
#include "erreur/connexion/Timeout.h"
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
                /** Serveur sur lequel pointe la connexion.*/
                const Serveur& _serveur;
                /** pour la gestion des erreurs avec asio.*/
                asio::error_code _erreur;

            public:
                /**
                * @brief Construction d'un nouvel objet représentant une connexion.
                * @param serveur Serveur cible.
                */
                Connexion(const Serveur& serveur);
                /**
                * @brief Vérifie si la connexion est ouverte.
                * @return true La connexion est ouverte.
                * @return false La connexion est fermée.
                */
                const bool ouverte() override;
                /**
                * @brief Ouvre une nouvelle connexion.
                */
                void ouvrir() override;
                /**
                * @brief Ferme la connexion.
                */
                inline void fermer() override {this->_socket->close();}
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