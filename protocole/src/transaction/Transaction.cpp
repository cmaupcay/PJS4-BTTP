#include "../../include/transaction/Transaction.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            _Transaction::_Transaction(const Mode mode, IConnexion& connexion, const Identite& identite)
                : _mode{ mode }, _connexion{ connexion }, _identite{ identite }, _ouverte{ false }
            {}

            void _Transaction::ouvrir(const std::string mdp)
            {
                if (this->_ouverte) throw Erreur::Transaction::DejaOuverte();
                if (!this->_connexion.ouverte()) this->_connexion.ouvrir();
                this->ouverture(mdp);
                this->_ouverte = true;
            }

            void _Transaction::fermer(const std::string mdp)
            {
                if (!this->_ouverte) throw Erreur::Transaction::DejaFermee();
                this->fermeture(mdp);
                this->_connexion.fermer();
                this->_ouverte = false;
            }

            void _Transaction::envoyer(const Messages::IMessage& message, const std::string mdp)
            {
                if (!this->_ouverte) throw Erreur::Transaction::Fermee(true);
                this->_connexion.envoyer(this->preparer(message, mdp));
            }

            const Messages::IMessage* _Transaction::recevoir(const std::string mdp)
            {
                if (!this->_ouverte) throw Erreur::Transaction::Fermee(false);
                return this->resoudre(this->_connexion.recevoir(), mdp);
            }
        }
    }
}