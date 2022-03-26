#include "../include/Identites.h"

namespace BTTP 
{
    namespace Client 
    {
        namespace Identites
        {

            void exporter(const Protocole::Identite& identite, const std::string dossier, const bool utiliser_contexte, const bool creer_chemin) 
            {
                const std::string nom = Protocole::Meta(identite.cle_publique()).nom();
                Fichiers::ecrire(identite.exporter(), nom + '.' + BTTP_IDENTITE_EXT, dossier, false, true, utiliser_contexte, creer_chemin);
            }

            const Protocole::Identite importer(const std::string nom, const std::string dossier, const bool utiliser_contexte)
            {
                std::ifstream fichier = Fichiers::lecture(nom + '.' + BTTP_IDENTITE_EXT, dossier, true, utiliser_contexte); 
                return Protocole::Identite(fichier);
            }

            const Protocole::Identite importer(const Protocole::Meta& meta, const std::string dossier, const bool utiliser_contexte)
            {
                const Protocole::Identite identite = importer(meta.nom(), dossier, utiliser_contexte);
                const Protocole::Meta meta_importees{ Protocole::Meta(identite.cle_publique()) };
                if (meta_importees == meta) return identite;
                throw Erreur::Identites::MetaIncorrectes(meta, meta_importees);
            }
        }
    }
}