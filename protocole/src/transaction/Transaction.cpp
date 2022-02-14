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
                // if (this->_ouverte) throw Erreur:: // TODO Classe d'erreur DejaOuverte
                if (!this->_connexion.ouvert()) this->_connexion.ouvrir();
                this->ouverture(mdp);
                this->_ouverte = true;
            }

            void _Transaction::fermer(const std::string mdp)
            {
                // if (!this->_ouverte) throw Erreur:: // TODO Classe d'erreur DejaFermee
                this->fermeture(mdp);
                this->_connexion.fermer();
                this->_ouverte = false;
            }

            void _Transaction::envoyer(const Messages::IMessage& message, const std::string mdp)
            {
                // if (!this->_ouverte) throw Erreur:: // TODO Classe d'erreur Fermee
                this->_connexion.envoyer(this->preparer(message, mdp));
            }

            const Messages::IMessage* _Transaction::recevoir(const std::string mdp)
            {
                // if (!this->_ouverte) throw Erreur:: // TODO Classe d'erreur Fermee
                return this->resoudre(this->_connexion.recevoir(), mdp);
            }
        }
    }
}