#ifndef H_BTTP_CLIENT_COEUR
#define H_BTTP_CLIENT_COEUR

#include "Fichiers.h"

namespace BTTP 
{
    namespace Client 
    {
        // TODO Déplacer dans une classe gérant les identités du client (les 2).
        void exporter(
            const Protocole::Identite& identite,
            const std::string dossier = BTTP_IDENTITE_DOSSIER, 
            const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT,
            const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT
        );
        // TODO Surcharge avec un objet BTTP::Protocole::Meta au lieu du string nom ?
        const Protocole::Identite importer(
            const std::string nom, 
            const std::string dossier = BTTP_IDENTITE_DOSSIER,
            const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
        );
    }
}


#endif