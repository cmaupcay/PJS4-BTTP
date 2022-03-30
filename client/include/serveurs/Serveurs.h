#ifndef H_BTTP_CLIENT_SERVEURS
#define H_BTTP_CLIENT_SERVEURS

#include "Serveur.h"
#include "../Fichiers.h"
#include "messages/ReponseClePublique.h"
#include "messages/ReponseAppareils.h"
#include "messages/ReponseScripts.h"

#include "serveurs/erreur/DejaPresent.h"


namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            /**
             * @brief Ajout d'un serveur de contrôle et récupération de la clé publique. L'appareil s'annonce au serveur.
             * @param serveur Serveur de contrôle à ajouter et dont on souhaite mettre à jour la clé publique enregistrée localement.
             * @param identite Identité locale.
             * @param mdp Mot de passe de l'identité locale.
             * @param dossier Dossier de destination.
             * @param contexte Contexte BTTP à utiliser.
             * @throw Type::Incoherent ou Type::Erreur
             */
            void ajout(
                Serveur& serveur,
                const Protocole::Identite& identite, const std::string mdp,
                const std::string dossier = BTTP_SERVEUR_DOSSIER, 
                const Contexte* contexte = nullptr,
                const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT
            );

            /**
             * @brief Importation des informations d'un serveur de contrôle enregistré localement et précédemment ajouté.
             * @param nom Nom du serveur à 
             * @param dossier Dossier de destination.
             * @param contexte Contexte BTTP à utiliser.
             * @return const Serveur Serveur importé.
             */
            inline const Serveur charger(
                const std::string nom,
                asio::io_context& contexte_asio,
                const std::string dossier = BTTP_SERVEUR_DOSSIER, 
                Contexte* contexte = nullptr
            )
            { return Serveur(nom, Fichiers::lire(nom, dossier, true, contexte), contexte_asio); }

            // TODO Annoncement de la suppression au serveur cible.
            /**
             * @brief Suppression d'un serveur de contrôle.
             * @param serveur Serveur de contrôle à supprimer.
             * @param dossier Dossier de destination.
             * @param contexte Contexte BTTP à utiliser.
             * @return true Le serveur a été supprimé localement.
             * @return false La suppression du serveur a échoué.
             */
            inline void suppression(
                const Serveur& serveur,
                const std::string dossier = BTTP_SERVEUR_DOSSIER, 
                const Contexte* contexte = nullptr
            )
            { Fichiers::supprimer(serveur.nom(), dossier, contexte); }

            /**
             * @brief Retourne la liste des serveurs enregistrés localement.
             * @param dossier Dossier de destination.
             * @param contexte Contexte BTTP à utiliser.
             * @return const std::vector<Serveur> 
             */
            const std::vector<Serveur> liste(
                asio::io_context& contexte_asio,
                const std::string dossier = BTTP_SERVEUR_DOSSIER, 
                Contexte* contexte = nullptr
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