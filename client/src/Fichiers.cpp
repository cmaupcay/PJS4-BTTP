#include "../include/Fichiers.h"

namespace BTTP
{
    namespace Client
    {
        namespace Fichiers
        {
            const std::string chemin(const std::string fichier, const std::string dossier, const bool utiliser_contexte)
            { return (utiliser_contexte ? Contexte::dossier() + '/' : "") + dossier + '/' + fichier; }

            const std::string dossier(const std::string fichier)
            { return fichier.substr(0, fichier.find_last_of('/')); }

            std::ofstream ecriture(
                const std::string fichier, const std::string dossier,
                const bool ajouter, const bool binaire, const bool utiliser_contexte, const bool creer_chemin
            )
            {
                const std::string cible = chemin(fichier, dossier, utiliser_contexte);
                if (!std::filesystem::exists(cible))
                {
                    if (creer_chemin) std::filesystem::create_directories(Fichiers::dossier(cible));
                    else throw Erreur::Fichiers::Inexistant(cible);
                }
                std::ios::openmode mode = std::ios::out;
                if (ajouter) mode = std::ios::app;
                if (binaire) mode |= std::ios::binary;
                std::ofstream flux{ cible, mode };
                if (flux.is_open()) return flux;
                else throw Erreur::Fichiers::Ouverture(cible);
            }

            void ecrire(
                const std::string data, const std::string fichier, const std::string dossier,
                const bool ajouter, const bool binaire, const bool utiliser_contexte, const bool creer_chemin
            )
            {
                std::ofstream flux = ecriture(fichier, dossier, ajouter, binaire, utiliser_contexte, creer_chemin);
                flux << data;
                flux.close();
            }

            const std::ifstream lecture(
                const std::string fichier, const std::string dossier, 
                const bool binaire, const bool utiliser_contexte
            )
            {
                const std::string cible = chemin(fichier, dossier, utiliser_contexte);
                if (!std::filesystem::exists(cible)) throw Erreur::Fichiers::Inexistant(cible);
                std::ifstream flux{ cible, binaire ? std::ios::binary : std::ios::in };
                if (flux.is_open()) return flux;
                else throw Erreur::Fichiers::Ouverture(cible);
            }

            const std::string lire(
                const std::string fichier, const std::string dossier,
                const bool binaire, const bool utiliser_contexte
            )
            {
                std::ifstream flux = lecture(fichier, dossier, binaire, utiliser_contexte);
                std::string contenu = "", ligne = "";
                while (std::getline(flux, ligne))
                    contenu += ligne;
                flux.close();
                return contenu;
            }

            const std::vector<std::string> liste(const std::string dossier, const bool utiliser_contexte)
            {
                std::vector<std::string> fichiers;
                const std::filesystem::directory_iterator idossier{chemin("", dossier, utiliser_contexte)};
                for (const std::filesystem::directory_entry& fichier : idossier)
                {
                    if (fichier.is_regular_file())
                        fichiers.push_back(fichier.path().filename());
                }
                return fichiers;
            }
        }
    }
}