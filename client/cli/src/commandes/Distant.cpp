#include "../../include/commandes/Distant.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                void Distant::executer(const int argc, const char** argv) const
                {
                    if (argc == 2)
                    {
                        const std::string mdp = Console::demander("> Mot de passe de l'identité locale : ");
                        Console::afficher("> Récupération des autorisations...");
                        const std::vector<std::string> autorisations = Client::Scripts::Autorisations::liste(Contexte::identite(), mdp);

                        Client::Serveurs::Serveur serveur = Commande::definir_serveur();
                        Console::afficher("> Serveur : " + serveur.informations());

                        Console::afficher("> Connexion au serveur...");
                        serveur.connexion().ouvrir();
                        Commande::authentification(serveur, mdp);

                        Console::afficher("> Lancement du processus...");
                        Client::Distant distant{ Contexte::identite(), serveur, autorisations };
                        distant.processus(mdp); // TODO Lancement dans un daemon.

                        Console::afficher("> Fermeture de la connexion...");
                        serveur.connexion().fermer();
                    }  
                    else throw Erreur::Commandes::Syntaxe(this);
                }

                const std::string Distant::aide() const
                {
                    std::string aide = "Lancement du mode distant.\nUsage : bttp-cli ";
                    aide += BTTP_COMMANDE_DISTANT;
                    return aide;
                }
            }
        }
    }
}