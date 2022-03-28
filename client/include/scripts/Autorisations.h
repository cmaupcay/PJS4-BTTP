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
                    const std::string dossier, const bool utiliser_contexte
                );
                static void ecrire(
                    const std::vector<std::string>& cles,
                    const Protocole::Identite& identite, const std::string mdp,
                    const std::string dossier, const bool utiliser_contexte,
                    const bool creer_chemin
                );

            public:
                /**
                 * @brief Autorisation d'un nouvelle clé publique.
                 * @param cle Clé publique de l'appareil à autoriser.
                 * @param identite Identité locale.
                 * @param mdp Mot de passe de l'identité locale.
                 * @param dossier Dossier de destination.
                 * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
                 * @param creer_chemin Drapeau indiquant si le chemin doit être créé s'il n'existe pas.
                 * @return true La clé publique a été ajouté aux clés autorisées.
                 * @return false L'ajout de la clé a échoué.
                 */
                static const bool autoriser(
                    const Protocole::Cle::Publique& cle,
                    const Protocole::Identite& identite, const std::string mdp,
                    const std::string dossier = BTTP_DOSSIER, 
                    const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT,
                    const bool creer_chemin = BTTP_CREATION_CHEMIN_PAR_DEFAUT
                );

                /**
                 * @brief Révocation d'un autorisation.
                 * @param empreinte Empreinte de la clé publique de l'appareil à révoquer.
                 * @param identite Identité locale.
                 * @param mdp Mot de passe de l'identité locale.
                 * @param dossier Dossier de destination.
                 * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
                 * @return true L'autorisation a été révoqué.
                 * @return false La suppression de l'autorisation a échoué.
                 */
                static const bool revoquer(
                    const std::string empreinte,
                    const Protocole::Identite& identite, const std::string mdp,
                    const std::string dossier = BTTP_DOSSIER, 
                    const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
                );

                /**
                 * @brief Retourne la liste des clés publiques des appareils autorisés.
                 * @param identite Identité locale.
                 * @param mdp Mot de passe de l'identité locale.
                 * @param dossier Dossier de destination.
                 * @param utiliser_contexte Drapeau indiquant si le dossier est relatif au contexte BTTP.
                 * @return const std::vector<Script> Liste des clés publiques des appareils autorisés.
                 */
                inline static const std::vector<std::string> liste(
                    const Protocole::Identite& identite, const std::string mdp,
                    const std::string dossier = BTTP_DOSSIER, 
                    const bool utiliser_contexte = BTTP_UTILISER_CONTEXTE_PAR_DEFAUT
                )
                { return lire(identite, mdp, dossier, utiliser_contexte); }
            };
        }
    }
}

#endif