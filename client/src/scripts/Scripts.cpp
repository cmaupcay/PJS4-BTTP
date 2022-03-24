#include "../../include/scripts/Scripts.h"

namespace BTTP
{
    namespace Client
    {
        const bool Scripts::ajouter(
            const Script script, const std::string contenu,
            Protocole::IConnexion* connexion_serveur,
            const std::string dossier, 
            const bool utiliser_contexte,
            const bool creer_chemin
        )
        {
            // Enregistrement du fichier en local.
            Fichiers::ecrire(contenu, script.reference(), dossier, false, false, utiliser_contexte, creer_chemin);
            // Annonce de l'ajout du script
            // TODO Envoi d'un message Script de type Ajout.
            return false;
        }


        const bool Scripts::supprimer(
            const Script script,
            Protocole::IConnexion* connexion_serveur,
            const std::string dossier, 
            const bool utiliser_contexte
        )
        {
            // Suppression du fichier local s'il existe.
            if (Fichiers::supprimer(script.reference(), dossier, utiliser_contexte))
            {
                // TODO Envoi d'un message Script de type Suppression.
            }
            return false;
        }

        const std::vector<Script> Scripts::liste(
            const Serveur& serveur, const std::string dossier, 
            const bool utiliser_contexte
        )
        {
            std::vector<Script> scripts;
            const std::vector<std::string> fichiers = Fichiers::liste(
                dossier + '/' + serveur.nom(), utiliser_contexte    
            );
            for (const std::string& fichier : fichiers)
                scripts.push_back(Script(serveur, fichier));
            return scripts;
        }
    }
}