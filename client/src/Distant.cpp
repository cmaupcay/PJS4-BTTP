#include "../include/Distant.h"

namespace BTTP
{
    namespace Client
    {
        void Distant::processus(const std::string mdp) noexcept
        {
            std::string paquet, entete, contenu;
            while (this->_serveur.connexion().ouverte())
            {
                try
                {
                    paquet = this->_serveur.connexion().recevoir();
                    entete = this->_identite.dechiffrer(
                        Protocole::Transactions::extraire_entete(paquet), this->_serveur.cle(), mdp
                    );
                    if (entete[0] == static_cast<char>(Protocole::Messages::Controle::Type::OUVERTURE)
                    &&  Transactions::verifier_entete_controle(entete))
                    {
                        contenu = Protocole::Transactions::retirer_entete(paquet);
                        Transactions::Distant transaction{
                            this->_identite, contenu, this->_serveur, this->_cles_autorisees
                        };
                        transaction.ouvrir(mdp);
                        transaction.lancer(mdp);
                    }
                }
                catch (BTTP::Erreur& erreur)
                {
                    const Protocole::Messages::Erreur message_erreur{ erreur };
                    paquet = this->_identite.chiffrer(  
                        message_erreur.construire(), this->_serveur.cle(), mdp
                    );
                    this->_serveur.connexion().envoyer(paquet);
                }
            }
        }
    }
}