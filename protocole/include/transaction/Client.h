#ifndef H_BTTP_TRANSACTION_CLIENT
#define H_BTTP_TRANSACTION_CLIENT

#include "Transaction.h"

#include "erreur/Ouverture.h"
#include "erreur/Fermeture.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            /**
             * @brief Transaction utilisée par les appareils clients.
             */
            class Client : public _Transaction
            {
            private:
                /** Clé publique de l'appareil distant. */
                const Cle::Publique* _distant;
                /** Clé publique de l'appareil de contrôle. */
                const Cle::Publique& _controleur;

                // TOTEST
                /**
                 * @brief Préparation d'un message avant son envoi sur la connexion réseau. 
                 * Le message est chiffré à destination de l'appareil distant, signé et encapsulé dans un message de contrôle.
                 * @param message Message à chiffrer, signer et encapsuler.
                 * @param mdp Mot de passe de l'identité locale.
                 * @return const std::string Paquet à envoyer.
                 */
                const std::string preparer(const Messages::IMessage* message, const std::string& mdp) const;

            protected:
                /**
                 * @brief Construction d'une nouvelle transaction cliente sans spécification de la clé publique de l'appareil distant.
                 * @warning Ce constructeur foit être utilisé par les transactions distantes uniquement.
                 * @param identite Identité locale à utiliser.
                 * @param controleur Clé publique de l'appareil de contrôle.
                 * @param connexion_controleur Connexion réseau avec l'appareil de contrôle.
                 */
                Client(
                    const Identite* identite,
                    const Cle::Publique& controleur, IConnexion* connexion_controleur
                );

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
                 * 
                 * @throws BTTP::Erreur::Transaction::Fermeture La fermeture de la transaction a entrainé une erreur.
                 */
                void fermeture(const std::string& mdp) override;

                /**
                 * @brief Définition de la clé publique du client.
                 * @warning Cette fonction doit uniquement être utilisé par la transaction de type Distant lors de son ouverture.
                 * @param client Clé publique du client.
                 */
                inline void definir_cle_client(const Cle::Publique& client) { this->_distant = &client; }
            
            protected:
                /**
                 * @brief Vérification d'une entête de vérification ajouté à un message de contrôle par l'appareil de contrôle.
                 * @param entete Entête à vérifier.
                 * @return true L'entête est valide.
                 * @return false L'entête n'est pas valide.
                 */
                virtual const bool verifier_entete(const std::string& entete) = 0;

            public:
                // TOTEST
                /**
                 * @brief Construction d'une nouvelle transaction cliente.
                 * @param identite Identité locale à utiliser.
                 * @param distant Clé publique de l'appareil distant cible.
                 * @param controleur Clé publique de l'appareil de contrôle.
                 * @param connexion_controleur Connexion réseau avec l'appareil de contrôle.
                 */
                Client(
                    const Identite* identite, const Cle::Publique& distant, 
                    const Cle::Publique& controleur, IConnexion* connexion_controleur
                );

                // TOTEST Envoi de message
                /**
                 * @brief Envoi d'un message sur la transaction.
                 * @param message Message à envoyer.
                 * @param mdp Mot de passe de l'identité locale.
                 * 
                 * @throws BTTP::Erreur::Transaction::Fermee La transaction n'est pas ouverte.
                 */
                void envoyer(const Messages::IMessage* message, const std::string mdp);

                // TOTEST Réception de message
                /**
                 * @brief Lecture d'un message sur la transaction.
                 * @param mdp Mot de passe de l'identité locale.
                 * @return const Messages::IMessage* Message lu.
                 * 
                 * @throws BTTP::Erreur::Transaction::Fermee La transaction n'est pas ouverte.
                 * @throws BTTP::Erreur::Transaction::EnteteInvalide L'entête de vérification du message est invalide.
                 */
                const Messages::IMessage* recevoir(const std::string mdp);
            };
        }
    }
}

#endif