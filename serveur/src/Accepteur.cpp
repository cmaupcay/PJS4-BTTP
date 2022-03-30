#include "../include/Accepteur.h"

namespace BTTP
{
    namespace Serveur
    {
        void Accepteur::lancer()
        {
            asio::io_context contexte;
            asio::ip::tcp::acceptor accepteur{ contexte, { asio::ip::tcp::v6(), this->_port } };

            Journal::ecrire("Accepteur", "Écoute active sur le port " + std::to_string(this->_port) + ".");
            while (accepteur.is_open())
            {
                asio::ip::tcp::socket socket{ contexte };
                accepteur.accept(socket);
                Journal::ecrire("Accepteur", "Nouvelle connexion.");
                new Sessions::Session(this->_contexte, this->_source, std::make_shared<Client::Connexion>(std::move(socket), contexte), this->_sessions);
            }
            Journal::ecrire("Accepteur", "Écoute desactivée.");            
        }
    }
}