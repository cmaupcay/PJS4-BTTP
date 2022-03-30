#include "../../include/commandes/Serveurs.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                const int Serveurs::liste(asio::io_context& contexte) const
                {
                    const std::vector<Client::Serveurs::Serveur> serveurs = Client::Serveurs::liste(contexte, BTTP_SERVEUR_DOSSIER, Contexte::client().get());
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

                void Serveurs::ajout(asio::io_context& contexte, const std::string cible) const
                {
                    Console::afficher("> Ajout du serveur \"" + cible + "\" : ");
                    const std::string adresse = Console::demander("\tAdresse : ");
                    const std::string port_par_defaut = std::to_string(BTTP_PORT);
                    std::string port = Console::demander(
                        "\tPort de connexion (" + port_par_defaut + " par défaut) : "
                    );
                    if (port.size() == 0) port = port_par_defaut;
                    Client::Serveurs::Serveur serveur{ cible, adresse, (uint16_t)std::atoi(port.c_str()), contexte };
                    Console::afficher("> Ajout du serveur...");
                    const std::string mdp = Console::demander("\tMot de passe de l'identité : ");
                    Console::afficher("> Connexion au serveur...");
                    Client::Serveurs::ajout(serveur, *Contexte::client()->identite(), mdp, BTTP_SERVEUR_DOSSIER, Contexte::client().get());
                    Console::afficher("> Serveur de contrôle ajouté avec succès.");

                }

                void Serveurs::suppression(asio::io_context& contexte, const std::string cible) const
                {
                    Console::afficher("> Suppression du serveur \"" + cible + "\"...");
                    const Client::Serveurs::Serveur serveur = Client::Serveurs::charger(cible, contexte, BTTP_SERVEUR_DOSSIER, Contexte::client().get());
                    Client::Serveurs::suppression(serveur, BTTP_SERVEUR_DOSSIER, Contexte::client().get());
                    Console::afficher("> Serveur supprimé avec succès.");
                }

                void Serveurs::executer(const int argc, const char** argv, asio::io_context& contexte) const
                {
                    if (argc == 2)      // Format : bttp-cli srv            ->      Affichage de la liste des serveurs.
                        this->liste(contexte);
                    else if (argc == 4) // Format : bttp-cli srv +/- <nom>  ->      Ajout ou suppression d'un serveur.
                    {
                        if (strcmp(argv[2], BTTP_COMMANDE_SERVEURS_AJOUT) == 0)
                            this->ajout(contexte, argv[3]);
                        else if (strcmp(argv[2], BTTP_COMMANDE_SERVEURS_SUPPRESSION) == 0)
                            this->suppression(contexte, argv[3]);
                        else throw Erreur::Commandes::Syntaxe(this);
                    }
                    else throw Erreur::Commandes::Syntaxe(this);
                }

                const std::string Serveurs::aide() const
                {
                    std::string aide = "Gestion des serveurs de contrôle.\nUsage : bttp-cli ";
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