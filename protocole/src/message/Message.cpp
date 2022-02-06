#include "../../include/message/Message.h"
                #include <iostream>

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            template <class _Type>
            void TMessage<_Type>::deconstruire(const std::string paquet)
            {
                if (paquet.length() > 0 && paquet[0] == this->type_c())
                    this->deconstruction(paquet.substr(1));
                else throw Erreur::Messages::Type::Incoherent(this->type_c(), paquet);
            }

            const std::vector<std::string> decouper(const std::string contenu, const std::string separateur)
            {
                std::vector<std::string> vecteur;
                const size_t n = contenu.size();
                size_t debut = 0, fin = 1;
                // Tant qu'on trouve un séparateur dans la chaîne...
                while ((fin = contenu.find(separateur, debut)) < n)
                {
                    // On ajoute la partie entre les dernier et avant-dernier séparateurs trouvés.
                    vecteur.push_back(contenu.substr(debut, fin - debut));
                    debut = fin + 1; // On saute le séparateur trouvé
                }
                if (debut < n) // Si la chaîne ne se termine pas par un séparateur...
                    vecteur.push_back(contenu.substr(debut)); // On ajoute la dernière partie.
                return vecteur;
            }

            const std::string joindre(const std::vector<std::string>& vecteur, const std::string jointure)
            {
                std::string contenu = "";
                const size_t vn = vecteur.size();
                for (int n = 0; n < vn; n++)
                {
                    contenu += vecteur[n]; // On concatène les chaînes ensembles.
                    if (n + 1 < vn) // Pour toutes les chaînes sauf la dernière...
                        contenu += jointure; // On ajoute la jointure à la fin.
                }
                return contenu;
            }

            template class TMessage<Type>;
        }
    }
}