#include "../include/Identites.h"

namespace BTTP 
{
    namespace Client 
    {
        void Identites::exporter(const Protocole::Identite& identite, const std::string dossier, const bool utiliser_contexte, const bool creer_chemin) 
        {
            const std::string nom = Protocole::Meta(identite.cle_publique()).nom();
            Fichiers::ecrire(identite.exporter(), nom + '.' + BTTP_IDENTITE_EXT, dossier, false, true, utiliser_contexte, creer_chemin);
        }

        const Protocole::Identite Identites::importer(const std::string nom, const std::string dossier, const bool utiliser_contexte)
        {
            std::ifstream fichier = Fichiers::lecture(nom + '.' + BTTP_IDENTITE_EXT, dossier, true, utiliser_contexte); 
            return Protocole::Identite(fichier);
        }
    }
}