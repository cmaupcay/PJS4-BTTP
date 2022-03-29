#ifndef H_BTTP_CLIENT_SCRIPTS
#define H_BTTP_CLIENT_SCRIPTS

#include "messages/DemandeAjout.h"
#include "messages/ReponseAjout.h"
#include "messages/DemandeSuppression.h"
#include "../Fichiers.h"

#include "erreur/Execution.h"
#include "erreur/Ajout.h"
#include "erreur/Inexistant.h"
#include "erreur/SupressionFichierSortie.h"

namespace BTTP
{
    namespace Client
    {
        namespace Scripts
        {
            /**
             * @brief Ajout d'un script.
             * @param nom Nom du script à ajouter.
             * @param contenu Contenu du script (code source).
             * @param serveur Serveur de référence du script à ajouter.
             * @param identite Identité locale.
             * @param mdp Mot de passe de l'identité locale.
             * @param dossier Dossier de destination.
             * @param contexte Contexte BTTP à utiliser.
             * @param creer_chemin Drapeau indiquant si le chemin doit être créé s'il n'existe pas.
             * @return const Script Métadonnées du script ajouté.
             * 
             * @throws BTTP::Client::Erreur::Scripts::Ajout Impossible d'ajouter le script.
             */
            const Script ajouter(
                const std::string nom, const std::string contenu,
                const Serveurs::Serveur& serveur,
                const Protocole::Identite& identite, const std::string mdp,
                const std::string dossier = BTTP_SCRIPT_DOSSIER, 
                const Contexte* contexte = nullptr,
                const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT
            );

            /**
             * @brief Suppression d'un script.
             * @param script Métadonnées du script à supprimer.
             * @param serveur Serveur de référence du script à ajouter.
             * @param identite Identité locale.
             * @param mdp Mot de passe de l'identité locale.
             * @param dossier Dossier de destination.
             * @param contexte Contexte BTTP à utiliser.
             * @throw Type::Incoherent ou Type::Erreur
             */
            void supprimer(
                const Script script,
                const Serveurs::Serveur& serveur,
                const Protocole::Identite& identite, const std::string mdp,
                const std::string dossier = BTTP_SCRIPT_DOSSIER, 
                const Contexte* contexte = nullptr
            );

            /**
             * @brief Exécution d'un script.
             * @param script Métadonnées du script à lancer.
             * @param dossier Dossier de destination.
             * @param contexte Contexte BTTP à utiliser.
             * @return std::string Sortie.
             * 
             * @throws BTTP::Client::Erreur::Scripts::Execution L'exécution a engendré une erreur.
             */
            const std::string executer(
                const Script script,
                const std::string dossier = BTTP_SCRIPT_DOSSIER, 
                const Contexte* contexte = nullptr
            );

            /**
             * @brief Retourne la liste des scripts locaux relatifs à un serveur.
             * @param serveur Serveur cible.
             * @param dossier Dossier de destination.
             * @param contexte Contexte BTTP à utiliser.
             * @return const std::vector<Script> Liste des scripts locaux relatis au serveur cible.
             */
            const std::vector<Script> liste(
                const Serveurs::Serveur& serveur,
                const std::string dossier = BTTP_SCRIPT_DOSSIER, 
                const Contexte* contexte = nullptr
            );
        }
    }
}

#endif