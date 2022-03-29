#ifndef H_BTTP_CLIENT_SCRIPTS_AUTORISATIONS
#define H_BTTP_CLIENT_SCRIPTS_AUTORISATIONS

#include "../Fichiers.h"

namespace BTTP
{
    namespace Client
    {
        namespace Scripts
        {
            class Autorisations
            {
            private:
                static std::vector<std::string> lire(
                    const Protocole::Identite& identite, const std::string mdp,
                    const std::string dossier, const Contexte* contexte
                );
                static void ecrire(
                    const std::vector<std::string>& cles,
                    const Protocole::Identite& identite, const std::string mdp,
                    const std::string dossier, const Contexte* contexte,
                    const bool creer_chemin
                );

                inline static const std::string nom_fichier(const Protocole::Identite& identite)
                { return Protocole::Meta(identite.cle_publique()).nom(); }

            public:
                /**
                 * @brief Autorisation d'un nouvelle clé publique.
                 * @param cle Clé publique de l'appareil à autoriser.
                 * @param identite Identité locale.
                 * @param mdp Mot de passe de l'identité locale.
                 * @param dossier Dossier de destination.
                 * @param contexte Contexte BTTP à utiliser.
                 * @param creer_chemin Drapeau indiquant si le chemin doit être créé s'il n'existe pas.
                 * @return true La clé publique a été ajouté aux clés autorisées.
                 * @return false L'ajout de la clé a échoué.
                 */
                static const bool autoriser(
                    const Protocole::Cle::Publique& cle,
                    const Protocole::Identite& identite, const std::string mdp,
                    const std::string dossier = BTTP_AUTORISATIONS_DOSSIER, 
                    const Contexte* contexte = nullptr,
                    const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT
                );

                /**
                 * @brief Révocation d'un autorisation.
                 * @param empreinte Empreinte de la clé publique de l'appareil à révoquer.
                 * @param identite Identité locale.
                 * @param mdp Mot de passe de l'identité locale.
                 * @param dossier Dossier de destination.
                 * @param contexte Contexte BTTP à utiliser.
                 * @return true L'autorisation a été révoqué.
                 * @return false La suppression de l'autorisation a échoué.
                 */
                static const bool revoquer(
                    const std::string empreinte,
                    const Protocole::Identite& identite, const std::string mdp,
                    const std::string dossier = BTTP_AUTORISATIONS_DOSSIER, 
                    const Contexte* contexte = nullptr
                );

                /**
                 * @brief Retourne la liste des clés publiques des appareils autorisés.
                 * @param identite Identité locale.
                 * @param mdp Mot de passe de l'identité locale.
                 * @param dossier Dossier de destination.
                 * @param contexte Contexte BTTP à utiliser.
                 * @return const std::vector<Script> Liste des clés publiques des appareils autorisés.
                 */
                inline static const std::vector<std::string> liste(
                    const Protocole::Identite& identite, const std::string mdp,
                    const std::string dossier = BTTP_AUTORISATIONS_DOSSIER, 
                    const Contexte* contexte = nullptr
                )
                { return lire(identite, mdp, dossier, contexte); }
            };
        }
    }
}

#endif