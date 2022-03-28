#ifndef H_BTTP_TRANSACTION_DISTANT
#define H_BTTP_TRANSACTION_DISTANT

#include "Client.h"

#include "erreur/OuvertureNonAutorisee.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transactions
        {
            /**
             * @brief Transaction utilisée par les appareils distants.
             */
            class Distant : public Client
            {
            private:
                /** Paquet d'ouverture de la transaction reçu de la part du client. */
                const std::string& _message_ouverture;
                /** Liste des clés publiques des appareils clients autorisés. */
                const std::vector<Cle::Publique> _cles_autorisees;

                // TOTEST
                /**
                 * @brief Procédure d'ouverture de la transaction.
                 * @param mdp Mot de passe de l'identité locale.
                 */
                void ouverture(const std::string& mdp) override;

                // TOTEST
                /**
                 * @brief Procédure de fermeture de la transaction.
                 * @param mdp Mot de passe de l'identité locale.
                 */
                void fermeture(const std::string& mdp) override;

                /**
                 * @brief Vérifie qu'une clé publique est dans la liste des clés publiques autorisées.
                 * @param cle Clé publique à vérifier.
                 * @return true La clé publique est autorisée.
                 * @return false La clé publique n'est pas autorisée.
                 */
                const bool verifier_autorisation(const Cle::Publique cle) const;
            
            public:
                // TOTEST
                /**
                 * @brief Construction d'une nouvelle transaction distante.
                 * @param identite Identité locale à utiliser.
                 * @param client Clé publique de l'appareil client.
                 * @param controleur Clé publique de l'appareil de contrôle.
                 * @param connexion_controleur Connexion réseau avec l'appareil de contrôle.
                 */
                Distant(
                    const Identite& identite, const std::string& message_ouverture,
                    const Cle::Publique& controleur, IConnexion& connexion_controleur
                );

                /**
                 * @brief Retourne la liste des clés publiques autorisées à ouvrir une transaction.
                 * @return const std::vector<Cle::Publique>& Liste des clés autorisées.
                 */
                inline const std::vector<Cle::Publique>& cles_autorisees() const { return this->_cles_autorisees; }
                /**
                 * @brief Ajout d'une nouvelle clé publique à la liste des clés autorisées.
                 * @param cle Clé publique de l'appareil à autoriser.
                 * @return true La clé publique a été ajouté à la liste.
                 * @return false La clé publique est déjà dans la liste.
                 */
                const bool autoriser(const Cle::Publique cle);
                /**
                 * @brief Révocation de l'autorisation d'une clé publique. Supprime la clé publique de la liste
                 * des clés publiques autorisées.
                 * @param cle Clé publique à révoquer.
                 * @return true L'autorisation de la clé a été révoquée.
                 * @return false La clé publique n'est pas dans la liste des clés autorisées.
                 */
                const bool revoquer(const Cle::Publique cle);
            };
        }
    }
}

#endif