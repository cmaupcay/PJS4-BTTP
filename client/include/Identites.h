#ifndef BTTP_CLIENT_IDENTITES
#define BTTP_CLIENT_IDENTITES

#include "Fichiers.h"

#include "erreur/identites/MetaIncorrectes.h"

namespace BTTP
{
    namespace Client
    {
        namespace Identites
        {
            /**
             * @brief Exportation d'une identité dans un fichier.
             * @param identite Identité à exporter.
             * @param dossier Dossier de destination.
             * @param contexte Contexte BTTP à utiliser.
             * @param creer_chemin Drapeau indiquant si le chemin doit être créé s'il n'existe pas.
             */
            void exporter(
                const Protocole::Identite& identite,
                const std::string dossier = BTTP_IDENTITE_DOSSIER, 
                const Contexte* contexte = nullptr,
                const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT
            );
            
            /**
             * @brief Importation d'une identité depuis un fichier.
             * @param nom Nom du fichier cible.
             * @param dossier Dossier cible.
             * @param contexte Contexte BTTP à utiliser.
             * @param ajouter_extension Drapeau indiquant si l'extension par défaut des identités doit être ajoutée au nom du fichier.
             * @return const Protocole::Identite Identité importée.
             */
            const Protocole::Identite importer(
                const std::string nom,
                const std::string dossier = BTTP_IDENTITE_DOSSIER,
                const Contexte* contexte = nullptr,
                const bool ajouter_extension = true
            );
            /**
             * @brief Importation d'une identité depuis un fichier.
             * @param meta Métadonnées de l'identité à importer. Le nom est utilisé comme nom de fichier cible.
             * @param dossier Dossier cible.
             * @param contexte Contexte BTTP à utiliser.
             * @return const Protocole::Identite Identité importée.
             */
            const Protocole::Identite importer(
                const Protocole::Meta& meta,
                const std::string dossier = BTTP_IDENTITE_DOSSIER,
                const Contexte* contexte = nullptr
            );

            /**
             * @brief Suppression d'une identité locale.
             * @param nom Nom du fichier cible.
             * @param dossier Dossier cible.
             * @param contexte Contexte BTTP à utiliser.
             * @return true L'identité a été supprimé.
             * @return false L'identité n'a pas pu être supprimé.
             */
            inline void supprimer(
                const std::string nom,
                const std::string dossier = BTTP_IDENTITE_DOSSIER,
                const Contexte* contexte = nullptr
            )
            { Fichiers::supprimer(nom + '.' + BTTP_IDENTITE_EXT, dossier, contexte); }

            /**
             * @brief Vérifie l'existence d'une identité locale.
             * @param nom Nom du fichier cible.
             * @param dossier Dossier cible.
             * @param contexte Contexte BTTP à utiliser.
             * @return true L'identité locale existe.
             * @return false L'identité locale n'existe pas.
             */
            inline const bool existe(
                const std::string nom,
                const std::string dossier = BTTP_IDENTITE_DOSSIER,
                const Contexte* contexte = nullptr
            )
            { return Fichiers::existe(nom + '.' + BTTP_IDENTITE_EXT, dossier, contexte); }

            /**
             * @brief Retourne la liste des identités disponibles.
             * @param dossier Dossier cible.
             * @param contexte Contexte BTTP à utiliser.
             * @return const std::vector<Protocole::Identite> Liste des identités importées.
             */
            const std::vector<Protocole::Identite> liste(
                const std::string dossier = BTTP_IDENTITE_DOSSIER,
                const Contexte* contexte = nullptr
            );
        };
    }
}

#endif