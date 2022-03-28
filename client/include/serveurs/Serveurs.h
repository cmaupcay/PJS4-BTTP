#ifndef H_BTTP_CLIENT_SERVEURS
#define H_BTTP_CLIENT_SERVEURS

#include "Serveur.h"
#include "../Fichiers.h"
#include "messages/ReponseAppareils.h"
#include "messages/ReponseScripts.h"


namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            // TODO Peut-être remplacer le booléen par void et lever des exceptions en cas d'erreur.
            /**
             * @brief Ajout d'un serveur de contrôle et récupération de la clé publique. L'appareil s'annonce au serveur.
             * @param serveur Serveur de contrôle à ajouter et dont on souhaite mettre à jour la clé publique enregistrée localement.
             * @param identite Identité locale.
             * @param mdp Mot de passe de l'identité locale.
             * @param dossier Dossier de destination.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return true Le serveur a été ajouté localement et a enregistré la clé publique de l'appareil.
             * @return false La procédure d'ajout n'a pas pu être finalisé.
             */
            const bool ajout(
                Serveur& serveur,
                const Protocole::Identite& identite, const std::string mdp,
                const std::string dossier = BTTP_SERVEUR_DOSSIER, 
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT,
                const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT
            );

            /**
             * @brief Importation des informations d'un serveur de contrôle enregistré localement et précédemment ajouté.
             * @param nom Nom du serveur à 
             * @param dossier Dossier de destination.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return const Serveur Serveur importé.
             */
            inline const Serveur charger(
                const std::string nom,
                const std::string dossier = BTTP_SERVEUR_DOSSIER, 
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            )
            { return Serveur(nom, Fichiers::lire(nom, dossier, false, utiliser_contexte)); }

            // TODO Annoncement de la suppression au serveur cible.
            /**
             * @brief Suppression d'un serveur de contrôle.
             * @param serveur Serveur de contrôle à supprimer.
             * @param dossier Dossier de destination.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return true Le serveur a été supprimé localement.
             * @return false La suppression du serveur a échoué.
             */
            inline const bool suppression(
                const Serveur& serveur,
                const std::string dossier = BTTP_SERVEUR_DOSSIER, 
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            )
            { return Fichiers::supprimer(serveur.nom(), dossier, utiliser_contexte); }

            /**
             * @brief Retourne la liste des serveurs enregistrés localement.
             * @param dossier Dossier de destination.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return const std::vector<Serveur> 
             */
            const std::vector<Serveur> liste(
                const std::string dossier = BTTP_SERVEUR_DOSSIER, 
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );
        
            /**
             * @brief Demande au serveur la liste des appareils distants disponibles associés à l'identité locale.
             * @param serveur Serveur de contrôle.
             * @param identite Identité locale.
             * @param mdp Mot de passe de l'identité locale.
             * @return const std::vector<Appareil> Liste des appareils distants disponibles.
             */
            const std::vector<Appareil> appareils(const Serveur& serveur, const Protocole::Identite& identite, const std::string mdp);

            /**
             * @brief Demande au serveur la liste des scripts disponibles sur l'appareil distant cible.
             * @param appareil Appareil distant cible.
             * @param serveur Serveur de contrôle.
             * @param identite Identité locale.
             * @param mdp Mot de passe de l'identité locale.
             * @return const std::vector<Script> Liste des scripts disponibles sur l'appareil cible.
             */
            const std::vector<Script> scripts(const Appareil& appareil, const Serveur& serveur, const Protocole::Identite& identite, const std::string mdp);
        }
    }
}

#endif