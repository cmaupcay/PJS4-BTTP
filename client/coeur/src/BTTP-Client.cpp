#include "../include/BTTP-Client.h"

namespace BTTP 
{

    namespace Client 
    {

        namespace Coeur
        {

            const std::string chemin_fichier(const std::string nom, const std::string dossier, const bool utiliser_contexte)
            { return (utiliser_contexte ? Contexte::dossier() + '/' : "") + dossier + '/' + nom + '.' + BTTP_IDENTITE_EXT; }

            void exporter(const Protocole::Identite& identite, const std::string dossier, const bool creer_chemin, const bool utiliser_contexte) 
            {
                const std::string nom = Protocole::Meta(identite.cle_publique()).nom();
                const std::string cible = chemin_fichier(nom, dossier, utiliser_contexte);
                const std::string chemin = cible.substr(0, cible.find_last_of('/'));
                if(!std::filesystem::is_directory(chemin))
                {
                    if(creer_chemin) std::filesystem::create_directories(chemin);
                    // else throw // TODO Classe d'erreur
                }
                std::ofstream fichier(cible, std::ios::binary);
                if (fichier.is_open())
                {
                    fichier << identite.exporter();
                    fichier.close();
                }
                // else throw // TODO Classe d'erreur
            }

            const Protocole::Identite importer(const std::string nom, const std::string dossier, const bool utiliser_contexte){

                const std::string cible = chemin_fichier(nom, dossier, utiliser_contexte);
                std::ifstream fichier(cible, std::ios::binary);
                // if (fichier.is_open())
                    // return Protocole::Identite(fichier); 
                // else throw // TODO Classe d'erreur
                return Protocole::Identite(fichier); 
            }
        }
    }
}