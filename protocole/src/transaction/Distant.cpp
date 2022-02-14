#include "../../include/transaction/Distant.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            void Distant::ouverture(const std::string& mdp)
            {
                // const Messages::Ouverture message{ this->_distant }; // TODO Il manque la classe de message Ouverture :(
                // this->envoyer(message, mdp);
            }

            Distant::Distant(const Identite& identite, const Cle::Publique& client, const Cle::Publique& controleur, IConnexion& connexion_controleur)
                : Client(Mode::DISTANT, identite, client, controleur, connexion_controleur)
            {}
        }
    }
}