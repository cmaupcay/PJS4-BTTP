#include "../../include/commandes/Distant.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                const Client::Serveurs::Serveur& Distant::definir_serveur() const
                {
                    const std::vector<Client::Serveurs::Serveur> serveurs = Client::Serveurs::liste();
                    const size_t n = serveurs.size();
                    if (n == 0) throw BTTP::Erreur("BTTP/Client/CLI/Commandes/Execution", "Aucun serveur disponible."); // TODO Erreur dédiée.
                    else if (n == 1) return serveurs[0];
                    else
                    {
                        size_t i = n;
                        while (i >= n || i < 0)
                        {
                            Console::saut();
                            Console::afficher("> Sélection du serveur de contrôle : ");
                            for (size_t s = 0; s < n; s++)
                                Console::afficher("\t#" + std::to_string(s) + " - " + serveurs[s].informations());
                            Console::saut();
                            // Sélection dans la liste.
                            i = std::atol(Console::demander("Serveur à utiliser : ").c_str());
                        }
                        return serveurs[i];
                    }
                }

                void Distant::executer(const int argc, const char** argv) const
                {
                    if (argc == 2)
                    {
                        const Client::Serveurs::Serveur& serveur = this->definir_serveur();
                        Console::afficher("> Serveur : " + serveur.informations());
                        Console::saut();

                        const std::string mdp = Console::demander("> Mot de passe de l'identité locale : ");

                        Console::afficher("> Récupération des autorisations...");
                        const std::vector<std::string> autorisations = Client::Scripts::Autorisations::liste(Contexte::identite(), mdp);

                        Console::afficher("> Lancement du processus...");
                        Client::Distant distant{ Contexte::identite(), serveur, autorisations };
                        distant.processus(mdp); // TODO Lancement dans un daemon.
                    }  
                    else throw Erreur::Commandes::Syntaxe(this);
                }

                const std::string Distant::aide() const
                {
                    std::string aide = "Usage : bttp-cli ";
                    aide += BTTP_COMMANDE_DISTANT;
                    return aide;
                }
            }
        }
    }
}