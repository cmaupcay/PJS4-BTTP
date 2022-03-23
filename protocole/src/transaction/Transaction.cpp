#include "../../include/transaction/Transaction.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            _Transaction::_Transaction(IConnexion* connexion, const Identite* identite)
                : _connexion{ connexion }, _identite{ identite }, _ouverte{ false }
            {}

            void _Transaction::ouvrir(const std::string mdp)
            {
                if (this->_ouverte) throw Erreur::Transaction::DejaOuverte();
                if (!this->_connexion->ouverte()) this->_connexion->ouvrir();
                this->ouverture(mdp);
                this->_ouverte = true;
            }

            void _Transaction::fermer(const std::string mdp)
            {
                if (!this->_ouverte) throw Erreur::Transaction::DejaFermee();
                this->fermeture(mdp);
                this->_ouverte = false;
            }
        }
    }
}