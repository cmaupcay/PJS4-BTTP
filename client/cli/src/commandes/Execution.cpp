#include "../../include/commandes/Execution.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                const Appareil& Execution::definir_appareil(const Client::Serveurs::Serveur& serveur, const std::string mdp) const
                {
                    Console::afficher("> Récupération de la liste des appareils...");
                    const std::vector<Appareil> appareils = Client::Serveurs::appareils(serveur, *Contexte::client()->identite(), mdp);
                    const size_t n = appareils.size();
                    if (n == 0) throw Erreur::Commandes::Execution::AucunAppareil();
                    else if (n == 1) return appareils[0];
                    else
                    {
                        size_t i = n;
                        while (i >= n || i < 0)
                        {
                            Console::saut();
                            Console::afficher("> Sélection de l'appareil distant : ");
                            for (size_t s = 0; s < n; s++)
                                Console::afficher("\t#" + std::to_string(s) + " - " + appareils[s].informations());
                            Console::saut();
                            // Sélection dans la liste.
                            i = std::atol(Console::demander("Appareil cible : ").c_str());
                        }
                        return appareils[i];
                    }
                }

                const Client::Serveurs::Script* Execution::definir_script(const Client::Serveurs::Serveur& serveur, const Appareil& appareil, const std::string mdp) const
                {
                    Console::afficher("> Récupération de la liste des scripts...");
                    const std::vector<Client::Serveurs::Script> scripts = Client::Serveurs::scripts(appareil, serveur, *Contexte::client()->identite(), mdp);
                    const size_t n = scripts.size();
                    if (n == 0)
                    {
                        Console::afficher("> Aucun script disponible.");
                        return nullptr;
                    }
                    else if (n == 1) return &scripts[0];
                    else
                    {
                        size_t i = n;
                        std::string reponse;
                        while (i >= n || i < 0)
                        {
                            Console::saut();
                            Console::afficher("> Sélection du script distant : ");
                            for (size_t s = 0; s < n; s++)
                                Console::afficher("\t#" + std::to_string(s) + " - " + scripts[s].nom());
                            Console::saut();
                            // Sélection dans la liste.
                            reponse = Console::demander("Script cible : ");
                            if (reponse == "") return nullptr;
                            i = std::atol(reponse.c_str());
                        }
                        return &scripts[i];
                    }
                }

                void Execution::executer(const int argc, const char** argv, asio::io_context& contexte) const
                {
                    if (argc == 2)
                    {
                        Client::Serveurs::Serveur serveur = Commande::definir_serveur(contexte);
                        Console::afficher("> Serveur : " + serveur.informations());
                        Console::afficher("> Connexion au serveur...");
                        serveur.connexion().ouvrir();

                        const std::string mdp = Console::demander("> Mot de passe de l'identité locale : ");
                        Commande::authentification(serveur, mdp);

                        if (serveur.authentifie())
                        {
                            const Appareil& appareil = this->definir_appareil(serveur, mdp);
                            Console::afficher("> Appareil : " + appareil.informations());

                            Console::afficher("> Ouverture de la transaction...");
                            Transactions::Client transaction{ *Contexte::client()->identite(), appareil, serveur };
                            transaction.ouvrir(mdp);
                            if (transaction.ouverte())
                            {
                                Console::afficher("> Transaction ouverte avec succès.");
                                const Client::Serveurs::Script* script = nullptr;
                                while ((script = this->definir_script(serveur, appareil, mdp)) != nullptr)
                                { 
                                    Console::saut();
                                    Console::afficher("> Execution du script \"" + script->nom() + "\"...");
                                    const Protocole::Messages::Resultat resultat = transaction.executer(*script, mdp);
                                    Console::afficher("> Résultat d'exécution #" + std::to_string(resultat.id()) + " : ");
                                    Console::afficher("\t" + resultat.resultat());
                                    Console::saut();
                                }
                            }
                            else throw Erreur::Commandes::Execution::OuvertureTransaction(transaction);
                        }

                        Console::afficher("> Fermeture de la connexion...");
                        serveur.connexion().fermer();
                    }  
                    else
                    {
                        Console::saut();
                        throw Erreur::Commandes::Syntaxe(this);
                    }      

                }

                const std::string Execution::aide() const
                {
                    std::string aide = "Lancement d'une procédure d'exécution.\nUsage : bttp-cli ";
                    aide += BTTP_COMMANDE_EXECUTION;
                    return aide;
                }
            }
        }
    }
}