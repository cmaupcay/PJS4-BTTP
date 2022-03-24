#ifndef BTTP_CLIENT_CONNEXION
#define BTTP_CLIENT_CONNEXION

#include "Racine.h"
#include "serveurs/Serveur.h"
#include <chrono>
#include <asio.hpp>

namespace BTTP
{
    namespace Client
    {
        class Connexion : public Protocole::IConnexion
        {
            // TODO Implémentation de l'interface définie dans le protocole grâce à asio.

            private:
                asio::ip::tcp::socket* _socket;
                const Serveur& _serveur;
                asio::error_code _erreur;

            public:
                Connexion(const Serveur& serveur);
                const bool ouverte() override;
                void ouvrir() override;
                inline void fermer() override {this->_socket->close();}
                void envoyer(const std::string message_prepare) override;
                const std::string recevoir() override;

        };
    }
}

#endif