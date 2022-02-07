#ifndef H_BTTP_CLIENT
#define H_BTTP_CLIENT

#include "Contexte.h"

#include <fstream>
#include <filesystem>

namespace BTTP 
{
    namespace Client 
    {
        namespace Coeur
        {
            // TODO Déplacer dans une classe gérant les fichiers et dossier du client (les 3).
            void exporter(
                const Protocole::Identite& identite,
                const std::string dossier = BTTP_IDENTITE_DOSSIER, 
                const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );
            // TODO Surcharge avec un objet BTTP::Protocole::Meta au lieu du string nom ?
            const Protocole::Identite importer(
                const std::string nom, 
                const std::string dossier = BTTP_IDENTITE_DOSSIER,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );
            const std::string chemin_fichier(const std::string nom, const std::string dossier, const bool utiliser_contexte);
        }
    }
}


#endif