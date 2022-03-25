#include "../../include/serveurs/Serveur.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            Serveur::Serveur(const std::string nom, const std::string serialisation)
                : _nom{ nom }, _cle{ nullptr }, _connexion{ nullptr }
            {
                const size_t fin_premiere_ligne = serialisation.find_first_of('\n');
                const size_t fin_deuxieme_ligne = serialisation.find_first_of('\n', fin_premiere_ligne + 1);
                // Adresse sur la première ligne.
                this->_adresse = serialisation.substr(0, fin_premiere_ligne);
                // Port sur la deuxième ligne.
                this->_port = (uint16_t)std::atoi(serialisation.substr(fin_premiere_ligne + 1, fin_deuxieme_ligne - (fin_premiere_ligne + 1)).c_str());
                // Reste du fichier = clé publique.
                this->_cle = new Protocole::Cle::Publique(serialisation.substr(fin_deuxieme_ligne + 1));
            }

            const std::string Serveur::serialiser() const
            {
                std::string infos = this->_adresse;
                infos += "\n" + std::to_string(this->_port);
                infos += "\n" + this->_cle->write(BTTP_IDENTITE_ARMOR ? OpenPGP::PGP::Armored::YES : OpenPGP::PGP::Armored::NO);
                return infos;
            }
        }
    }
}