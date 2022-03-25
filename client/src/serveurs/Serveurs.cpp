#include "../../include/serveurs/Serveurs.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {

            const bool ajout(
                const Serveur& serveur,
                const Protocole::Identite* identite, const std::string mdp,
                const std::string dossier, const bool utiliser_contexte
            )
            {
                // TODO Init (voir diagramme de séquence).
                return false;
            }

            const bool suppression(
                const Serveur& serveur,
                const std::string dossier, const bool utiliser_contexte
            )
            {
                // TODO Suppression du fichier local.
                return false;
            }

            const std::vector<Serveur> liste(const std::string dossier, const bool utiliser_contexte)
            {
                std::vector<Serveur> serveurs;
                const std::vector<std::string> fichiers = Fichiers::liste(dossier, utiliser_contexte);
                std::string contenu;
                for (const std::string& fichier : fichiers)
                {
                    contenu = Fichiers::lire(fichier, dossier, false, utiliser_contexte);
                    serveurs.push_back(Serveur(fichier, contenu));
                }
                return serveurs;
            }   
        }
    }
}