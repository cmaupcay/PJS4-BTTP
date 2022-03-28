#include "../../include/commandes/Serveurs.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                const int Serveurs::liste() const
                {
                    const std::vector<Client::Serveurs::Serveur> serveurs = Client::Serveurs::liste();
                    if (serveurs.size() == 0)
                        Console::afficher("> Aucun serveur de contrôle enregistré.");
                    else
                    {
                        Console::afficher("> Serveurs de contrôle enregistrés : ");
                        for (const Client::Serveurs::Serveur& serveur : serveurs)
                            Console::afficher("\t- " + serveur.informations());
                    }
                    return 0;

                }

                const int Serveurs::ajout(const std::string cible) const
                {
                    Console::afficher("> Ajout du serveur \"" + cible + "\" : ");
                    const std::string adresse = Console::demander("\tAdresse : ");
                    const std::string port = Console::demander(
                        "\tPort de conenxion (" + std::to_string(BTTP_PORT) + " par défaut) : "
                    );
                    Client::Serveurs::Serveur serveur{ cible, adresse, (uint16_t)std::atoi(port.c_str()) };
                    Console::afficher("> Ajout du serveur...");
                    const std::string mdp = Console::demander("\tMot de passe de l'identité : ");
                    Console::afficher("> Connexion au serveur...");
                    if (Client::Serveurs::ajout(serveur, Contexte::identite(), mdp))
                    {
                        Console::afficher("> Serveur de contrôle ajouté avec succès.");
                        return 0;
                    }
                    else return -1;
                }

                const int Serveurs::suppression(const std::string cible) const
                {
                    Console::afficher("> Suppression du serveur \"" + cible + "\"...");
                    const Client::Serveurs::Serveur serveur = Client::Serveurs::charger(cible);
                    if (Client::Serveurs::suppression(serveur))
                    {
                        Console::afficher("> Serveur supprimé avec succès.");
                        return 0;
                    }
                    else return -1;
                }

                void Serveurs::executer(const int argc, const char** argv) const
                {
                    if (argc == 2)      // Format : bttp-cli srv            ->      Affichage de la liste des serveurs.
                        this->liste();
                    else if (argc == 4) // Format : bttp-cli srv +/- <nom>  ->      Ajout ou suppression d'un serveur.
                    {
                        if (strcmp(argv[2], BTTP_COMMANDE_SERVEURS_AJOUT) == 0)
                            this->ajout(argv[3]);
                        else if (strcmp(argv[2], BTTP_COMMANDE_SERVEURS_SUPPRESSION) == 0)
                            this->suppression(argv[3]);
                        else throw Erreur::Commandes::Syntaxe(this);
                    }
                    else throw Erreur::Commandes::Syntaxe(this);
                }

                const std::string Serveurs::aide() const
                {
                    std::string aide = "Usage : bttp-cli ";
                    aide += BTTP_COMMANDE_SERVEURS;
                    aide += " [";
                    aide += BTTP_COMMANDE_SERVEURS_AJOUT;
                    aide += "|";
                    aide += BTTP_COMMANDE_SERVEURS_SUPPRESSION;
                    aide += " <nom>]";
                    return aide;
                }
            }
        }
    }
}