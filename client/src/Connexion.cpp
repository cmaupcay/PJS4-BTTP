#include "../include/Connexion.h"

namespace BTTP 
{
    namespace Client
    {
        Connexion::Connexion(const std::string adresse, const uint16_t port) 
            : _adresse{ adresse }, _port{ port }, _socket{ nullptr }
        {}


        void Connexion::ouvrir() 
        {
            if (this->ouverte()) throw Erreur::Connexion::DejaOuverte(this->_adresse, this->_port); 
            else
            {
                asio::io_context contexte;
                asio::ip::tcp::resolver resolver{ contexte };
                const asio::ip::tcp::resolver::results_type resultats = resolver.resolve(
                    this->_adresse, std::to_string(this->_port), this->_erreur
                );
                if (resultats.size() == 0 || this->_erreur) throw Erreur::Connexion::Resolution(this->_adresse, this->_port);
                else
                {
                    // Création du socket et connexion.
                    const asio::ip::tcp::endpoint hote = *resultats;
                    this->_socket = new asio::ip::tcp::socket(contexte);
                    this->_socket->connect(hote, this->_erreur);
                    if (this->_erreur) throw Erreur::Connexion::Ouverture(this->_adresse, this->_port);
                }
            }
        }

        void Connexion::envoyer(const std::string message_prepare) 
        {
            if (this->ouverte()) 
                this->_socket->write_some(asio::buffer(message_prepare.data(), message_prepare.size()), this->_erreur);
            else
                throw Erreur::Connexion::Fermee(this->_adresse, this->_port);
        }

        const std::string Connexion::recevoir() 
        {
            if (this->ouverte())
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