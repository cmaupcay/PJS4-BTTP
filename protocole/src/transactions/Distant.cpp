#include "../../include/transactions/Distant.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transactions
        {
            void Distant::ouverture(const std::string& mdp)
            {
                const Identite::MessageNonVerifie message_ouverture{
                    this->_message_ouverture, this->identite(), mdp
                };
                // Récupération de la clé publique du client depuis le message d'ouverture.
                const Messages::Ouverture message_ouverture_clair{ 
                    retirer_entete(message_ouverture.clair())
                };
                const Cle::Publique client = message_ouverture_clair.client();
                Messages::IMessage* reponse = nullptr;
                // Vérification de l'autorisation pour la clé publique.
                if (this->verifier_autorisation(client))
                {
                    // Vérification de la signature du paquet d'ouverture.
                    if (message_ouverture.verifier(client))
                    {
                        this->definir_cle_client(client);
                        // Envoi du message de confirmation.
                        reponse = new Messages::Pret();
                    }
                    else reponse = new Messages::Erreur(
                        new Erreur::Identite::Dechiffrement(
                            "La signature du message d'ouverture n'est pas valide.",
                            message_ouverture.clair()
                        )
                    );
                }
                else reponse = new Messages::Erreur(
                    new Erreur::Transactions::OuvertureNonAutorisee(&message_ouverture_clair)
                );
                this->envoyer(reponse, mdp);
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