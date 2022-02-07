#include "../include/BTTP-Client.h"

namespace BTTP 
{

    namespace Client 
    {

        void exporter(const Protocole::Identite& identite, const std::string dossier, const bool utiliser_contexte, const bool creer_chemin) 
        {
            const std::string nom = Protocole::Meta(identite.cle_publique()).nom();
            Fichiers::ecrire(identite.exporter(), nom + '.' + BTTP_IDENTITE_EXT, dossier, false, true, utiliser_contexte, creer_chemin);
            // const std::string cible = chemin_fichier(nom, dossier, utiliser_contexte);
            // const std::string chemin = cible.substr(0, cible.find_last_of('/'));
            // if(!std::filesystem::is_directory(chemin))
            // {
            //     if(creer_chemin) std::filesystem::create_directories(chemin);
            //          else throw // TODO Classe d'erreur
            // }
            // std::ofstream fichier(cible, std::ios::binary);
            // if (fichier.is_open())
            // {
            // }
            // else throw // TODO Classe d'erreur
        }

        const Protocole::Identite importer(const std::string nom, const std::string dossier, const bool utiliser_contexte)
        {
            std::ifstream fichier = Fichiers::lecture(nom + '.' + BTTP_IDENTITE_EXT, dossier, true, utiliser_contexte); 
            return Protocole::Identite(fichier);
        }
    }
}