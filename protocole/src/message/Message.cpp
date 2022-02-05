#include "../../include/message/Message.h"
                #include <iostream>

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            // TOCOMMENT
            const std::vector<std::string> decouper(const std::string contenu, const std::string pattern)
            {
                std::vector<std::string> vecteur;
                const size_t n = contenu.size();
                size_t debut = 0, fin = 1;
                while ((fin = contenu.find(pattern, debut)) < n)
                {
                    vecteur.push_back(contenu.substr(debut, fin - debut));
                    debut = fin + 1;
                }
                if (debut < n)
                    vecteur.push_back(contenu.substr(debut));
                return vecteur;
            }

            // TOCOMMENT
            const std::string joindre(const std::vector<std::string>& vecteur, const std::string jointure)
            {
                std::string contenu = "";
                const size_t vn = vecteur.size();
                for (int n = 0; n < vn; n++)
                {
                    contenu += vecteur[n];
                    if (n + 1 < vn) contenu += jointure;
                }
                return contenu;
            }
        }
    }
}