#ifndef H_BTTP_SERVEUR_JOURNAL
#define H_BTTP_SERVEUR_JOURNAL

#include "Racine.h"

namespace BTTP
{
    namespace Serveur
    {
        namespace Journal
        {
            inline void ecrire(const std::string composant, const std::string message)
            { std::cout << "[BTTP/Serveur" << (composant == "" ? "" : "/" + composant) << "] " << message << std::endl; }
            inline void ecrire(const std::string message) { ecrire("", message); }
            inline void ecrire(const BTTP::Erreur& erreur) { std::cerr << erreur.afficher(); }
        }
    }
}

#endif