#include "../include/Fichiers.h"

namespace BTTP
{
    namespace Client
    {
        namespace Fichiers
        {
            const std::string chemin(const std::string fichier, const std::string dossier, const Contexte* contexte)
            { return (contexte != nullptr ? contexte->dossier() + '/' : "") + (dossier.size() > 0 ? dossier + '/' : "") + fichier; }

            const std::string dossier(const std::string fichier)
            { return fichier.substr(0, fichier.find_last_of('/')); }

            std::ofstream ecriture(
                const std::string fichier, const std::string dossier,
                const bool ajouter, const bool binaire, const Contexte* contexte, const bool creer_chemin
            )
            {
                const std::string cible = chemin(fichier, dossier, contexte);
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
                const bool ajouter, const bool binaire, const Contexte* contexte, const bool creer_chemin
            )
            {
                std::ofstream flux = ecriture(fichier, dossier, ajouter, binaire, contexte, creer_chemin);
                flux << data;
                flux.close();
            }

            std::ifstream lecture(
                const std::string fichier, const std::string dossier, 
                const bool binaire, const Contexte* contexte
            )
            {
                const std::string cible = chemin(fichier, dossier, contexte);
                if (existe(fichier, dossier, contexte))
                {
                    std::ifstream flux{ cible, binaire ? std::ios::binary : std::ios::in };
                    if (flux.is_open()) return flux;
                    else throw Erreur::Fichiers::Ouverture(cible);
                }
                else throw Erreur::Fichiers::Inexistant(cible);
            }

            const std::string lire(
                const std::string fichier, const std::string dossier,
                const bool binaire, const Contexte* contexte
            )
            {
                std::ifstream flux = lecture(fichier, dossier, binaire, contexte);
                std::string contenu = "", ligne = "";
                while (std::getline(flux, ligne)) contenu += ligne += "\n";
                flux.close();
                return contenu;
            }

            const std::vector<std::string> liste(const std::string dossier, const Contexte* contexte)
            {
                std::vector<std::string> fichiers;
                if (existe("", dossier, contexte))
                {
                    const std::filesystem::directory_iterator idossier{ chemin("", dossier, contexte) };
                    for (const std::filesystem::directory_entry& fichier : idossier)
                    {
                        if (fichier.is_regular_file())
                            fichiers.push_back(fichier.path().filename());
                    }
                }
                return fichiers;
            }
        }
    }
}