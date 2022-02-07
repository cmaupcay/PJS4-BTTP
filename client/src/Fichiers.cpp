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
                // if (!std::filesystem::exists(cible)) throw // TODO Classe d'erreur
                std::ios::openmode mode = std::ios::out;
                if (ajouter) mode = std::ios::app;
                if (binaire) mode |= std::ios::binary;
                std::ofstream flux{ cible, mode };
                return flux;
                // TODO Classe d'erreur
                // if (flux.is_open()) return flux;
                // else throw
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
                // if (!std::filesystem::exists(cible)) throw // TODO Classe d'erreur
                std::ifstream flux{ cible, binaire ? std::ios::binary : std::ios::in };
                return flux;
                // TODO Classe d'erreur
                // if (flux.is_open()) return flux;
                // else throw
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
        }
    }
}