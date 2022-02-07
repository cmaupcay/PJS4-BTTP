#ifndef H_BTTP_CLIENT_FICHIERS
#define H_BTTP_CLIENT_FICHIERS

#include "Contexte.h"

namespace BTTP
{
    namespace Client
    {
        namespace Fichiers
        {
            /**
             * @brief Construction du chemin absolu d'un fichier.
             * @param fichier Nom du fichier cible.
             * @param dossier Dossier.
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

            // TOTEST
            // TOCOMMENT
            std::ofstream ecriture(
                const std::string fichier,
                const std::string dossier = BTTP_DOSSIER,
                const bool ajouter = false, const bool binaire = false,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT,
                const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT
            );
            // TOTEST
            // TOCOMMENT
            void ecrire(
                const std::string data, const std::string fichier,
                const std::string dossier = BTTP_DOSSIER,
                const bool ajouter = false, const bool binaire = false,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT,
                const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT
            );

            // TOTEST
            // TOCOMMENT
            const std::ifstream lecture(
                const std::string fichier,
                const std::string dossier = BTTP_DOSSIER,
                const bool binaire = false,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );
            // TOTEST
            // TOCOMMENT
            const std::string lire(
                const std::string fichier,
                const std::string dossier = BTTP_DOSSIER,
                const bool binaire = false,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );
        }
    }
}

#endif