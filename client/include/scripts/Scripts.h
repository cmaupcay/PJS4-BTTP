#ifndef H_BTTP_CLIENT_SCRIPTS
#define H_BTTP_CLIENT_SCRIPTS

#include "Script.h"
#include "../Fichiers.h"

namespace BTTP
{
    namespace Client
    {
        /**
         * @brief Classe abstraite rassemblant les utilitaires relatifs aux scripts locaux.
         */
        class Scripts
        {
        public:
            /**
             * @brief Ajout d'un script.
             * @param script Métadonnées du script à ajouter.
             * @param contenu Contenu du script (code source).
             * @param connexion_serveur Connexion au serveur.
             * @param dossier Dossier de destination.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @param creer_chemin Drapeau indiquant si le chemin doit être créé s'il n'existe pas.
             * @return true Le script a été ajouté localement et sur le serveur. Le fichier associé a été enregistré localement.
             * @return false L'ajout du script a échoué.
             */
            static const bool ajouter(
                const Script script, const std::string contenu,
                Protocole::IConnexion* connexion_serveur,
                const std::string dossier = BTTP_SCRIPT_DOSSIER, 
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT,
                const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT
            );

            /**
             * @brief Suppression d'un script.
             * @param script Métadonnées du script à supprimer.
             * @param connexion_serveur Connexion au serveur.
             * @param dossier Dossier de destination.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return true Le script a été supprimé localement et sur le serveur. Le fichier associé a été supprimé localement.
             * @return false La suppression du script a échoué.
             */
            static const bool supprimer(
                const Script script,
                Protocole::IConnexion* connexion_serveur,
                const std::string dossier = BTTP_SCRIPT_DOSSIER, 
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );

            /**
             * @brief Exécution d'un script.
             * @param script Métadonnées du script à lancer.
             * @param dossier Dossier de destination.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return true Le script a été exécuté avec succès.
             * @return false Une erreur est survenue avant ou pendant l'exécution.
             */
            static const bool executer(
                const Script script,
                const std::string dossier = BTTP_SCRIPT_DOSSIER, 
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );

            /**
             * @brief Retourne la liste des scripts locaux relatifs à un serveur.
             * @param serveur Serveur cible.
             * @param dossier Dossier de destination.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return const std::vector<Script> Liste des scripts locaux relatis au serveur cible.
             */
            static const std::vector<Script> liste(
                const Serveur& serveur,
                const std::string dossier = BTTP_SCRIPT_DOSSIER, 
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );
        };
    }
}

#endif