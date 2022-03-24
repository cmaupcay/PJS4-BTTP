#include "../../include/transaction/Distant.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            void Distant::ouverture(const std::string& mdp)
            {
                // Récupération de la clé publique du client depuis le message d'ouverture.
                const std::string paquet = retirer_entete(
                    this->identite().dechiffrer_sans_verifier(this->_message_ouverture, mdp)
                );
                const Cle::Publique client = Messages::Ouverture(paquet).client();
                // TODO Verifier que la clé appartient à la liste des clés autorisées
                // TODO Verifier signature du paquet avant de definir la clé
                this->definir_cle_client(client);
                // Envoi du message de confirmation.
                const Messages::Pret message;
                this->envoyer(&message, mdp);
            }

            void Distant::fermeture(const std::string& mdp)
            {
                // Envoi du message de confirmation.
                const Messages::Pret message;
                this->envoyer(&message, mdp);
            }

            Distant::Distant(
                const Identite* identite, const std::string& message_ouverture,
                const Cle::Publique& controleur, IConnexion* connexion_controleur
            )
                : Client(identite, controleur, connexion_controleur),
                _message_ouverture{ message_ouverture }
            {}
        }
    }
}