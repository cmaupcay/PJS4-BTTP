#include "../../include/scripts/Autorisations.h"

namespace BTTP
{
    namespace Client
    {
        namespace Scripts
        {
            // TOFIX Chiffrement du fichier des autorisations.

            std::vector<std::string> Autorisations::lire(
                const Protocole::Identite& identite, const std::string mdp,
                const std::string dossier, const bool utiliser_contexte
            )
            {
                std::vector<std::string> cles;
                if (Fichiers::existe(BTTP_AUTORISATIONS_FICHIER, dossier, utiliser_contexte))
                {
                    std::string contenu = Fichiers::lire(BTTP_AUTORISATIONS_FICHIER, dossier, false, utiliser_contexte);
                    // contenu = identite.dechiffrer(contenu, identite.cle_publique(), mdp);
                    cles = Protocole::Messages::decouper(contenu, "\n");
                }
                return cles;
            }

            void Autorisations::ecrire(
                const std::vector<std::string>& cles,
                const Protocole::Identite& identite, const std::string mdp,
                const std::string dossier, const bool utiliser_contexte,
                const bool creer_chemin
            )
            {
                std::string contenu;
                const size_t n = cles.size();
                for (size_t c = 0; c < n; c++)
                {
                    contenu += cles[c];
                    if (c < n - 1) contenu += "\n";
                }
                // contenu = identite.chiffrer(contenu, identite.cle_publique(), mdp);
                Fichiers::ecrire(contenu, BTTP_AUTORISATIONS_FICHIER, dossier, false, false, utiliser_contexte, creer_chemin);
            }

            const bool Autorisations::autoriser(
                const Protocole::Cle::Publique& cle,
                const Protocole::Identite& identite, const std::string mdp,
                const std::string dossier, const bool utiliser_contexte, const bool creer_chemin
            )
            {
                const std::string empreinte = cle.empreinte();
                std::vector<std::string> cles = lire(identite, mdp, dossier, utiliser_contexte);
                for (const std::string& c : cles) if (empreinte == c) return false;
                cles.push_back(empreinte);
                ecrire(cles, identite, mdp, dossier, utiliser_contexte, creer_chemin);
                return true;
            }

            const bool Autorisations::revoquer(
                const std::string empreinte,
                const Protocole::Identite& identite, const std::string mdp,
                const std::string dossier, const bool utiliser_contexte
            )
            {
                std::vector<std::string> cles = lire(identite, mdp, dossier, utiliser_contexte);
                const size_t n = cles.size();
                for (size_t c = 0; c < n; c++)
                    if (empreinte == cles[c])
                    {
                        cles.erase(cles.begin() + c);
                        ecrire(cles, identite, mdp, dossier, utiliser_contexte, false);
                        return true;
                    }
                return false;
            }
        }
    }
}