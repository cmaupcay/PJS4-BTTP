#include "../../include/transactions/Client.h"

namespace BTTP
{
    namespace Client
    {
        namespace Transactions
        {
            const Protocole::Messages::Resultat Client::executer(const Serveurs::Script& script, const std::string mdp)
            {
                const Protocole::Messages::Execution demande{ script.id() };
                this->envoyer(demande, mdp);
                const std::string reponse = this->recevoir_brut(mdp);
                const char type = reponse[0];
                if (type == static_cast<char>(Protocole::Messages::Type::RESULTAT))
                    return Protocole::Messages::Resultat(reponse);
                else if (type == static_cast<char>(Protocole::Messages::Type::ERREUR))
                {
                    const Protocole::Messages::Erreur erreur{ reponse };
                    throw BTTP::Erreur(erreur.nom(), erreur.message(), erreur.code());
                }
                else throw Protocole::Erreur::Messages::Type::Incoherent(type, reponse);
            }

            const time_t timestamp() {

                try 
                {

                    asio::io_context contexte;
                    asio::ip::udp::resolver resolver(contexte);

                    asio::ip::udp::endpoint serveur = *resolver.resolve(asio::ip::udp::v4(), "fr.pool.ntp.org", "ntp").begin();

                    asio::ip::udp::socket socket(contexte);
                    socket.open(asio::ip::udp::v4());

                    /** 
                     * 'c' == 0x63 == 0110 0011
                     * 01 = 1 -> Leap Indicator (ignoré dans la requête)
                     * 100 = 4 -> Version Number
                     * 011 = 3 -> Mode (Client ici)
                    */
                    std::string requete = "c";

                    for(int i = 0 ; i < 47 ; i++) requete += " "; // On rajoute 47 espaces (0x20) pour que la requête fasse 48 octets ('c' = 1 octet)

                    socket.send_to(asio::buffer(requete.data(), requete.size()), serveur); // On envoie la requête

                    std::vector<char> reception(48); // On attend une réponse qui fait précisemment 48 octets
                    asio::ip::udp::endpoint local;
                    size_t len = socket.receive_from(asio::buffer(reception), local); // On attend la réponse (appel bloquant)

                    char buffer[4] = {reception[40], reception[41], reception[42], reception[43]}; // On récupère les 4 octets correspondant au timestamp NTP (les octets 41, 42, 43 et 44)
                    
                    unsigned int ntp_timestamp = static_cast<int>(static_cast<unsigned char>(buffer[0]) << 24 | // On convertie les 4 octets en uint
                        static_cast<unsigned char>(buffer[1]) << 16 |                                           
                        static_cast<unsigned char>(buffer[2]) << 8 |                                
                        static_cast<unsigned char>(buffer[3]));

                    time_t unix_timestamp = ntp_timestamp - 2208988800; // On soustrait le timestamp avec le nombre de secondes écoulées entre 1900 et 1980 (RFC 868) pour avoir le timestamp unix

                    return unix_timestamp;

                } 
                catch (std::exception& e){ throw Erreur::Transactions::Timestamp(e.what());}

            }

        }
    }
}