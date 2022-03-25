#ifndef H_BTTP_CLIENT_SERVEURS
#define H_BTTP_CLIENT_SERVEURS

#include "Serveur.h"
#include "../Fichiers.h"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            /**
             * @brief Ajout d'un serveur de contrôle. L'appareil s'annonce au serveur.
             * @param serveur Serveur de contrôle à ajouter.
             * @param identite Identité locale.
             * @param mdp Mot de passe de l'identité locale.
             * @param dossier Dossier de destination.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return true Le serveur a été ajouté localement et a enregistré la clé publique de l'appareil.
             * @return false La procédure d'ajout n'a pas pu être finalisé.
             */
            static const bool ajout(
                const Serveur& serveur,
                const Protocole::Identite* identite, const std::string mdp,
                const std::string dossier = BTTP_SERVEUR_DOSSIER, 
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );

            // TODO Annoncement de la suppression au serveur cible.
            /**
             * @brief Suppression d'un serveur de contrôle.
             * @param serveur Serveur de contrôle à supprimer.
             * @param dossier Dossier de destination.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return true Le serveur a été supprimé localement.
             * @return false La suppression du serveur a échoué.
             */
            static const bool suppression(
                const Serveur& serveur,
                const std::string dossier = BTTP_SERVEUR_DOSSIER, 
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );

            /**
             * @brief Retourne la liste des serveurs enregistrés localement.
             * @param dossier Dossier de destination.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return const std::vector<Serveur> 
             */
            static const std::vector<Serveur> liste(
                const std::string dossier = BTTP_SERVEUR_DOSSIER, 
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );
        }
    }
}

#endif