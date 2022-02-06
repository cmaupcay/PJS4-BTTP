#include "../../include/identite/Meta.h"

namespace BTTP
{
    namespace Protocole
    {
        Meta::Meta(const Cle::Publique cle_publique)
        {
            // Récupération de la liste des clés
            std::string suid = cle_publique.list_keys();
            // Recherche des premiers UID
            const size_t debut = suid.find("uid") + 4; // ("uid ").length() == 4
            // Détermination de la chaine des UID
            suid = suid.substr(debut, suid.find("sig") - debut - 1); // La ligne des UID est suivie d'une ligne SIG
            // Recherche récursive des espaces entre les informations
            const size_t fin_nom = suid.find_first_of(' ');
            const size_t debut_contact = suid.find_first_of('<', fin_nom + 1) - 1;
            // Enregistrement des informations
            this->_nom = suid.substr(0, fin_nom);
            this->_commentaire = suid.substr(fin_nom + 2, debut_contact - fin_nom - 3); // On évite les parenthèses au début et à la fin
            this->_contact = suid.substr(debut_contact + 2); // On évite le premier crochet
            this->_contact.pop_back(); // Et on retire le dernier
        }
    }
}