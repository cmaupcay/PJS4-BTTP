#ifndef H_BTTP_TRANSACTION_DISTANT
#define H_BTTP_TRANSACTION_DISTANT

#include "Client.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            // TODO Ajout du message d'ouverture dans le constructeur + definition de la cle du client et verification à l'ouverture.
            /**
             * @brief Transaction utilisée par les appareils distants.
             */
            class Distant : public Client
            {
            private:
                const std::string& _message_ouverture;

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
                    const Identite* identite, const std::string& message_ouverture,
                    const Cle::Publique& controleur, IConnexion* connexion_controleur
                );
            };
        }
    }
}

#endif