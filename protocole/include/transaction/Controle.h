#ifndef H_BTTP_TRANSACTION_CONTROLE
#define H_BTTP_TRANSACTION_CONTROLE

#include "Transaction.h"

#define BTTP_TRANSACTION_MESSAGE_NUL ""

#include "erreur/Ouverture.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            // TOCOMMENT
            /**
             * @brief Transaction utilisé par l'appareil de contrôle.
             */
            class Controle : public _Transaction
            {
            private:
                /** Clé publique de l'appareil client ayant ouvert la transaction. */
                const Cle::Publique& _client;

                /** Message à relayer à l'appareil client. */
                std::string _message_a_relayer_a_client;

                /** Clé publique de l'appareil distant. */
                const Cle::Publique& _distant;
                
                /** Connexion réseau avec l'appareil distant. */
                IConnexion* _connexion_distant;
                
                /** Message à relayer à l'appareil distant. */
                std::string _message_a_relayer_a_distant;

                // TOTEST
                /**
                 * @brief Procédure d'ouverture de la transaction.
                 * @param mdp Mot de passe de l'identité locale.
                 * 
                 * @throws BTTP::Erreur::Transaction::Ouverture L'ouverture de la transaction a échoué.
                 */
                void ouverture(const std::string& mdp) override;

                // TOTEST
                /**
                 * @brief Procédure de fermeture de la transaction.
                 * @param mdp Mot de passe de l'identité locale.
                 */
                void fermeture(const std::string& mdp) override;

                // TOTEST
                /**
                 * @brief Lit et enregistre un nouveau message sur la connexion cible.
                 * @note Le contenu de 'var' est effacé.
                 * @param stockage_message Variable de stockage du message.
                 * @param connexion Connexion réseau cible.
                 * @return true Un message a été lu et enregistré.
                 * @return false Aucun message n'a été lu.
                 */
                const bool prochain_message(std::string& stockage_message, IConnexion* connexion);

                // TOTEST
                /**
                 * @brief Extraction, déchiffrement et vérification de la signature de l'entête de contrôle d'un message.
                 * @param message Message cible.
                 * @param signataire Signataire du message cible.
                 * @param mdp Mot de passe de l'identité locale.
                 * @return const std::string Entête de contrôle extraite et déchiffrée.
                 */
                const std::string lire_entete(
                    const std::string& message, const Cle::Publique& signataire,
                    const std::string& mdp
                ) const;

                // TOTEST
                /**
                 * @brief Relais d'un message sur une connexion.
                 * @param destinataire Clé publique du destinataire.
                 * @param connexion Connexion réseau cible.
                 * @param message Message à relayer.
                 * @param mdp Mot de passe de l'identité locale.
                 * @return true Le message a été relayé.
                 * @return false Le message est vide et n'a pas été relayé.
                 */
                const bool relayer(const Cle::Publique& destinataire, IConnexion* connexion, std::string& message, const std::string mdp);

            protected:
                /**
                 * @brief Génération d'une entête de vérification.
                 * @return const std::string Entête de vérification générée.
                 */
                virtual const std::string generer_entete() = 0;

            public:
                // TOTEST
                /**
                 * @brief Construction d'une nouvelle transaction de contrôle.
                 * @note Ne relais pas le message d'ouverture. Utiliser Controle::ouverture() pour ouvrir proprement la transaction.
                 * @param identite Identité locale à utiliser.
                 * @param message_ouverture Message d'ouverture reçu de l'appareil client.
                 * @param client Clé publique de l'appareil client.
                 * @param connexion_client Connexion réseau avec l'appareil client.
                 * @param distant Clé publique de l'appareil distant.
                 * @param connexion_distant Connexion réseau avce l'appareil distant.
                 */
                Controle(
                    const Identite* identite, const std::string& message_ouverture,
                    const Cle::Publique& client, IConnexion* connexion_client, 
                    const Cle::Publique& distant, IConnexion* connexion_distant
                );

                /**
                 * @brief Lit et enregistre un nouveau message sur la connexion avec l'appareil client.
                 * @return true Un message a été lu et enregistré.
                 * @return false Aucun message n'a été lu.
                 */
                inline const bool prochain_message_client()
                { return this->prochain_message(this->_message_a_relayer_a_distant, &this->connexion()); }
                /**
                 * @brief Lit l'entête du dernier message reçu de la part de l'appareil client.
                 * @param mdp Mot de passe de l'identité locale.
                 * @return const std::string Entête du message.
                 */
                inline const std::string lire_entete_client(const std::string mdp) const
                { return this->lire_entete(this->_message_a_relayer_a_distant, this->_client, mdp); }
                /**
                 * @brief Relais à l'appareil distant le dernier message reçu de la part de l'appareil client.
                 * @param mdp Mot de passe de l'identité locale.
                 * @return true Un message a été relayé.
                 * @return false Le message cible est vide.
                 */
                inline const bool relayer_a_distant(const std::string mdp)
                { return this->relayer(this->_distant, this->_connexion_distant, this->_message_a_relayer_a_distant, mdp); }

                /**
                 * @brief Lit et enregistre un nouveau message sur la connexion avec l'appareil distant.
                 * @return true Un message a été lu et enregistré.
                 * @return false Aucun message n'a été lu.
                 */
                inline const bool prochain_message_distant()
                { return this->prochain_message(this->_message_a_relayer_a_client, this->_connexion_distant); }
                /**
                 * @brief Lit l'entête du dernier message reçu de la part de l'appareil distant.
                 * @param mdp Mot de passe de l'identité locale.
                 * @return const std::string Entête du message.
                 */
                inline const std::string lire_entete_distant(const std::string mdp) const
                { return this->lire_entete(this->_message_a_relayer_a_client, this->_distant, mdp); }
                /**
                 * @brief Relais à l'appareil client le dernier message reçu de la part de l'appareil distant.
                 * @param mdp Mot de passe de l'identité locale.
                 * @return true Un message a été relayé.
                 * @return false Le message cible est vide.
                 */
                inline const bool relayer_a_client(const std::string mdp)
                { return this->relayer(this->_client, &this->connexion(), this->_message_a_relayer_a_client, mdp); }

            };
        }
    }
}

#endif