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
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @param creer_chemin Drapeau indiquant si le chemin doit être créé s'il n'existe pas.
             */
            void exporter(
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
            const Protocole::Identite importer(
                const std::string nom, 
                const std::string dossier = BTTP_IDENTITE_DOSSIER,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );
            /**
             * @brief Importation d'une identité depuis un fichier.
             * @param meta Métadonnées de l'identité à importer. Le nom est utilisé comme nom de fichier cible.
             * @param dossier Dossier cible.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return const Protocole::Identite Identité importée.
             */
            const Protocole::Identite importer(
                const Protocole::Meta& meta,
                const std::string dossier = BTTP_IDENTITE_DOSSIER,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );

            /**
             * @brief Retourne la liste des identités disponibles.
             * @param dossier Dossier cible.
             * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
             * @return const std::vector<Protocole::Identite> Liste des identités importées.
             */
            const std::vector<Protocole::Identite> liste(
                const std::string dossier = BTTP_IDENTITE_DOSSIER,
                const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
            );
        };
    }
}

#endif