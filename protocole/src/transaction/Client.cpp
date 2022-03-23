#include "../../include/transaction/Client.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Transaction
        {
            const std::string Client::preparer(const Messages::IMessage* message, const std::string& mdp) const
            {
                // Génération du message de contrôle adapté au message passé en paramètre
                const std::string message_controle = (Messages::Controle::generer(message, *this->_distant, &this->identite(), mdp))->construire();
                // Chiffrement de l'entete du message
                return this->identite().chiffrer(extraire_entete(message_controle), this->_controleur, mdp)
                       + BTTP_MESSAGE_CONTROLE_SEP + retirer_entete(message_controle);
            }

            void Client::ouverture(const std::string& mdp)
            {
                // Envoi du message d'ouverture.
                const Messages::Ouverture message{ *this->_distant, this->identite().cle_publique() };
                this->envoyer(&message, mdp);
                // Attente de la réponse du terminal distant.
                const Messages::IMessage* reponse = this->recevoir(mdp);
                // Si le message reçu n'est pas de type PRET, on lève une erreur.
                if (reponse->type_c() != static_cast<char>(Messages::Type::PRET)) 
                    throw Erreur::Transaction::Ouverture(reponse);
            }

            void Client::fermeture(const std::string& mdp)
            {
                // Envoi du message de fermeture.
                const Messages::Fermeture message;
                this->envoyer(&message, mdp);
                // Attente de la réponse du terminal distant.
                const Messages::IMessage* reponse = this->recevoir(mdp);
                // Si le message reçu n'est pas de type PRET, on lève une erreur.
                if (reponse->type_c() != static_cast<char>(Messages::Type::PRET)) 
                    throw Erreur::Transaction::Fermeture(reponse);
            }

            Client::Client(
                const Identite* identite,
                const Cle::Publique& controleur, IConnexion* connexion_controleur
            )
                : _Transaction(connexion_controleur, identite), 
                _distant{ nullptr }, _controleur{ controleur }
            {}

            Client::Client(
                const Identite* identite, const Cle::Publique& distant,
                const Cle::Publique& controleur, IConnexion* connexion_controleur
            )
                : _Transaction(connexion_controleur, identite), 
                _distant{ &distant }, _controleur{ controleur }
            {}

            void Client::envoyer(const Messages::IMessage* message, const std::string mdp)
            {
                if (!this->ouverte()) throw Erreur::Transaction::Fermee(true);
                this->connexion().envoyer(this->preparer(message, mdp));
            }

            const Messages::IMessage* Client::recevoir(const std::string mdp)
            {
                if (!this->ouverte()) throw Erreur::Transaction::Fermee(false);
                const std::string paquet = this->connexion().recevoir();
                const std::string entete = this->identite().dechiffrer(
                    extraire_entete(paquet), this->_controleur, mdp
                );
                if (this->verifier_entete(entete))
                {
                    const std::string contenu = this->identite().dechiffrer(
                        retirer_entete(paquet), *this->_distant, mdp
                    );
                    return Messages::resoudre(contenu);
                }
                else throw new Erreur::Transaction::EnteteInvalide(entete);
            }
        }
    }
}