#include "../../include/transactions/Client.h"

namespace BTTP
{
    namespace Client
    {
        namespace Transactions
        {
            const Protocole::Messages::Resultat Client::executer(const Serveurs::Script& script, const std::string mdp)
            {
                const Protocole::Messages::Execution demande{ script.id() };
                this->envoyer(demande, mdp);
                const std::string reponse = this->recevoir_brut(mdp);
                const char type = reponse[0];
                if (type == static_cast<char>(Protocole::Messages::Type::RESULTAT))
                    return Protocole::Messages::Resultat(reponse);
                else if (type == static_cast<char>(Protocole::Messages::Type::ERREUR))
                {
                    const Protocole::Messages::Erreur erreur{ reponse };
                    throw BTTP::Erreur(erreur.nom(), erreur.message(), erreur.code());
                }
                else throw Protocole::Erreur::Messages::Type::Incoherent(type, reponse);
            }
        }
    }
}