#include "../../include/transactions/Distant.h"

namespace BTTP
{
    namespace Client
    {
        namespace Transactions
        {
            void Distant::processus(const std::string mdp, std::string& status) noexcept
            {
                try
                {
                    const Protocole::Messages::IMessage* reception;
                    while (this->connexion().ouverte())
                    {
                        status = "En attente d'un message...";
                        reception = this->recevoir(mdp);
                        const char type = reception->type_c();
                        if (type == static_cast<char>(Protocole::Messages::Type::EXECUTION))
                        {
                            status = "Traitement de la demande d'exécution...";
                            const Protocole::Messages::Execution execution{ reception->construire() };
                            status = "Récupération de la liste des scripts locaux...";
                            const std::vector<Scripts::Script> scripts = Scripts::liste(this->_serveur);
                            for (const Scripts::Script& script : scripts)
                                if (script.id() == execution.id_script())
                                {
                                    status = "Exécution du script...";
                                    const std::string resultat = Scripts::executer(script);
                                    status = "Envoi du résultat...";
                                    const Protocole::Messages::Resultat message_resultat{ execution.id(), resultat };
                                    this->envoyer(message_resultat, mdp);
                                }
                        }
                        else if (type == static_cast<char>(Protocole::Messages::Type::FERMETURE))
                        {
                            status = "Fermeture...";
                            this->fermer(mdp);
                            break;
                        }
                        else throw Protocole::Erreur::Messages::Type::Incoherent(
                                reception->type_c(), reception->construire()
                            );
                    }
                    status = "Transaction fermée.";
                }
                catch (BTTP::Erreur& erreur)
                {
                    status = "Une erreur est survenue dans la transaction.";
                    const Protocole::Messages::Erreur message_erreur{ erreur };
                    this->envoyer(message_erreur, mdp);
                }
            }
        }
    }
}