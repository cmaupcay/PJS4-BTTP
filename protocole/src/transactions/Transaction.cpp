#include "../../include/transactions/Transaction.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transactions
        {
            _Transaction::_Transaction(IConnexion* connexion, const Identite* identite)
                : _connexion{ connexion }, _identite{ identite }, _ouverte{ false }
            {}

            void _Transaction::ouvrir(const std::string mdp)
            {
                if (this->_ouverte) throw Erreur::Transactions::DejaOuverte();
                if (!this->_connexion->ouverte()) this->_connexion->ouvrir();
                this->ouverture(mdp);
                this->_ouverte = true;
            }

            void _Transaction::fermer(const std::string mdp)
            {
                if (!this->_ouverte) throw Erreur::Transactions::DejaFermee();
                this->fermeture(mdp);
                this->_ouverte = false;
            }
        }
    }
}