#include "../include/Connexion.h"

namespace BTTP 
{

    namespace Client
    {

        Connexion::Connexion(const std::string adresse, const uint16_t port) 
            : _adresse{ adresse }, _port{ port }
        {
            asio::io_context contexte;
            this->_socket = new asio::ip::tcp::socket(contexte);
        }

        void Connexion::ouvrir() 
        {
            asio::ip::tcp::endpoint endpoint(asio::ip::make_address(this->_adresse, this->_erreur), this->_port);
            this->_socket->connect(endpoint, this->_erreur); 
        }

        void Connexion::envoyer(const std::string message_prepare) 
        {
            if(this->_socket->is_open()) 
                this->_socket->write_some(asio::buffer(message_prepare.data(), message_prepare.size()), this->_erreur);
            else
                throw Erreur::Connexion::Fermee(this->_adresse, this->_port);
        }

        const std::string Connexion::recevoir() 
        {

            if(this->_socket->is_open())
            {
                std::string message = "";
                size_t taille;

                const std::chrono::time_point<std::chrono::system_clock> debut = std::chrono::system_clock::now();
                std::chrono::time_point<std::chrono::system_clock> fin;
                const double tempsMax = (double) BTTP_TIMEOUT;

                while((taille = this->_socket->available()) == 0) 
                {
                    fin = std::chrono::system_clock::now();
                    auto temps = std::chrono::duration_cast<std::chrono::milliseconds>(fin - debut);
                    if(temps.count() >= tempsMax)
                        throw Erreur::Connexion::Timeout(this->_adresse, this->_port);
                }

                std::vector<char> buffer(taille);
                this->_socket->read_some(asio::buffer(buffer.data(), buffer.size()), this->_erreur);
                for(auto c : buffer)
                    message += c;
                return message;
            }
            else
                throw Erreur::Connexion::Fermee(this->_adresse, this->_port);
        }

    }

}