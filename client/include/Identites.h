#ifndef BTTP_CLIENT_IDENTITES
#define BTTP_CLIENT_IDENTITES

#include "Fichiers.h"

namespace BTTP
{
    namespace Client
    {
        /**
         * @brief Classe abstraite rassemblant les utilitaires relatifs aux identités locales.
         */
        class Identites
        {
        public:
            /**
             * @brief Exportation d'une identité dans un fichier.
             * @param identite Identité à exporter.
             * @param dossier Dossier de destination.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @param creer_chemin Drapeau indiquant si le chemin doit être créé s'il n'existe pas.
             */
            static void exporter(
                const Protocole::Identite& identite,
                const std::string dossier = BTTP_IDENTITE_DOSSIER, 
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT,
                const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT
            );
            
            /**
             * @brief Importation d'une identité depuis un fichier.
             * @param nom Nom du fichier cible.
             * @param dossier Dossier cible.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return const Protocole::Identite Identité importée.
             */
            static const Protocole::Identite importer(
                const std::string nom, 
                const std::string dossier = BTTP_IDENTITE_DOSSIER,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );
            // TODO Vérification des autres métadonnées une fois l'importation réussie (et donc à mettre dans le .cpp).
            /**
             * @brief Importation d'une identité depuis un fichier.
             * @param meta Métadonnées de l'identité à importer. Le nom est utilisé comme nom de fichier cible.
             * @param dossier Dossier cible.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return const Protocole::Identite Identité importée.
             */
            inline static const Protocole::Identite importer(
                const Protocole::Meta& meta,
                const std::string dossier = BTTP_IDENTITE_DOSSIER,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            )
            { return importer(meta.nom(), dossier, utiliser_contexte); }

            // TODO Déplacer et adapter l'implémentation (voir cli/src/CLI.cpp).
            /**
             * @brief Tentative d'importation d'une identité. Si introuvable, elle est générée.
             * @param meta Métadonnées de l'identité à importer. Le nom est utilisé comme nom de fichier cible.
             * @param dossier Dossier cible.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return const Protocole::Identite Identité importée.
             */
            static const Protocole::Identite demarrer(
                const Protocole::Meta& meta,
                const std::string dossier = BTTP_IDENTITE_DOSSIER,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );

            // TODO Implémentation.
            /**
             * @brief Retourne la liste des identités disponibles.
             * @param dossier Dossier cible.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return const std::vector<Protocole::Identite> Liste des identités importées.
             */
            static const std::vector<Protocole::Identite> disponibles(
                const std::string dossier = BTTP_IDENTITE_DOSSIER,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );
        };
    }
}

#endif