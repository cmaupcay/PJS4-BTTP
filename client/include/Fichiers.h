#ifndef H_BTTP_CLIENT_FICHIERS
#define H_BTTP_CLIENT_FICHIERS

#include "Contexte.h"

#include "erreur/fichiers/Inexistant.h"
#include "erreur/fichiers/Ouverture.h"

namespace BTTP
{
    namespace Client
    {
        namespace Fichiers
        {
            /**
             * @brief Construction du chemin absolu d'un fichier.
             * @param fichier Nom du fichier cible.
             * @param dossier Dossier contenant le fichier.
             * @param utiliser_contexte Défini si le chemin est relatif au dossier du contexte client. 
             * @return const std::string Chemin absolu du fichier.
             */
            const std::string chemin(
                const std::string fichier, const std::string dossier = BTTP_DOSSIER,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );

            /**
             * @brief Supprime le nom du fichier du chemin.
             * @param fichier Chemin du fichier cible.
             * @return const std::string Chemin du dossier parent.
             */
            const std::string dossier(const std::string fichier);

            /**
             * @brief Vérifie l'existence d'un fichier.
             * @param fichier Nom du fichier cible.
             * @param dossier Dossier contenant le fichier.
             * @param utiliser_contexte Défini si le chemin est relatif au dossier du contexte client. 
             * @return true Le fichier existe.
             * @return false Le fichier n'existe pas.
             */
            inline const bool existe(
                const std::string fichier,
                const std::string dossier = BTTP_DOSSIER,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            )
            { return std::filesystem::exists(chemin(fichier, dossier, utiliser_contexte)); }

            // TOTEST
            /**
             * @brief Fournit un flux d'écriture sur un fichier.
             * @param fichier Nom du fichier cible.
             * @param dossier Dossier contenant le fichier.
             * @param ajouter Ecrire à la suite du contenu actuel du fichier.
             * @param binaire Ouvrir le fichier en mode binaire.
             * @param utiliser_contexte Défini si le chemin est relatif au dossier du contexte client. 
             * @param creer_chemin Défini si BTTP doit tenter de créer le dossier s'il n'existe pas.
             * @return std::ofstream Flux de sortie sur le fichier cible.
             */
            std::ofstream ecriture(
                const std::string fichier,
                const std::string dossier = BTTP_DOSSIER,
                const bool ajouter = false, const bool binaire = false,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT,
                const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT
            );

            // TOTEST
            /**
             * @brief Ecrit des données dans un fichier.
             * @param data Données à écrire.
             * @param fichier Nom du fichier cible.
             * @param dossier Dossier contenant le fichier.
             * @param ajouter Ecrire à la suite du contenu actuel du fichier.
             * @param binaire Ouvrir le fichier en mode binaire.
             * @param utiliser_contexte Défini si le chemin est relatif au dossier du contexte client. 
             * @param creer_chemin Défini si BTTP doit tenter de créer le dossier s'il n'existe pas.
             */
            void ecrire(
                const std::string data, const std::string fichier,
                const std::string dossier = BTTP_DOSSIER,
                const bool ajouter = false, const bool binaire = false,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT,
                const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT
            );

            // TOTEST
            /**
             * @brief Fournit un flux de lecture sur un fichier.
             * @param fichier Nom du fichier cible.
             * @param dossier Dossier contenant le fichier.
             * @param binaire Ouvrir le fichier en mode binaire.
             * @param utiliser_contexte Défini si le chemin est relatif au dossier du contexte client. 
             * @return std::ifstream Flux d'entrée sur le fichier cible.
             */
            std::ifstream lecture(
                const std::string fichier,
                const std::string dossier = BTTP_DOSSIER,
                const bool binaire = false,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );
            
            // TOTEST
            /**
             * @brief Lit les données d'un fichier.
             * @param fichier Nom du fichier cible.
             * @param dossier Dossier contenant le fichier.
             * @param binaire Ouvrir le fichier en mode binaire.
             * @param utiliser_contexte Défini si le chemin est relatif au dossier du contexte client. 
             * @return const std::string Données lues dans le dossier.
             */
            const std::string lire(
                const std::string fichier,
                const std::string dossier = BTTP_DOSSIER,
                const bool binaire = false,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );

            /**
             * @brief Retourne la liste des fichiers présents dans un dossier.
             * @param dossier Dossier cible.
             * @param utiliser_contexte Défini si le chemin est relatif au dossier du contexte client. 
             * @return const std::vector<std::string> Liste des noms de fichier.
             */
            const std::vector<std::string> liste(
                const std::string dossier,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );

            /**
             * @brief Suppression d'un fichier.
             * @param fichier Nom du fichier cible.
             * @param dossier Dossier contenant le fichier.
             * @param utiliser_contexte Défini si le chemin est relatif au dossier du contexte client.
             * @throw Erreur::Fichiers::Inexistant si le fichier n'est pas trouvé
             */
            inline void supprimer(
                const std::string fichier,
                const std::string dossier = BTTP_DOSSIER,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            )
            { if(!std::filesystem::remove(chemin(fichier, dossier, utiliser_contexte))) throw Erreur::Fichiers::Inexistant(fichier);}
        }
    }
}

#endif