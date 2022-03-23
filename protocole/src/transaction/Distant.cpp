#include "../../include/transaction/Distant.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            void Distant::ouverture(const std::string& mdp)
            {
                const Messages::Pret message;
                this->envoyer(&message, mdp);
            }

            void Distant::fermeture(const std::string& mdp)
            {
                const Messages::Pret message;
                this->envoyer(&message, mdp);
            }

            Distant::Distant(
                const Identite* identite, const Cle::Publique& client,
                const Cle::Publique& controleur, IConnexion* connexion_controleur
            )
                : Client(identite, client, controleur, connexion_controleur)
            {}
        }
    }
}