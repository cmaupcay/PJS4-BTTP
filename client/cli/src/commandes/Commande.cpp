#include "../../include/commandes/Commande.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                const Client::Serveurs::Serveur Commande::definir_serveur()
                {
                    const std::vector<Client::Serveurs::Serveur> serveurs = Client::Serveurs::liste();
                    const size_t n = serveurs.size();
                    if (n == 0) throw Erreur::Commandes::AucunServeur();
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

                void Commande::authentification(Client::Serveurs::Serveur& serveur, const std::string mdp)
                {
                    Console::afficher("> Authentification de l'identité...");
                    bool authentification = false;
                    try {  authentification = serveur.authentification(Contexte::identite(), mdp); }
                    catch (const BTTP::Erreur& erreur) {}
                    if (!authentification)
                    {
                        Console::afficher("> L'authentification de l'identité a échoué.\n> Tentative d'authentification par compte : ");
                        const std::string utilisateur = Console::demander("\tUtilisateur : "); 
                        const std::string mdp_utilisateur = Console::demander("\tMot de passe : ");
                        Console::afficher("\t> Authentification du compte...");
                        if (!serveur.authentification(Contexte::identite(), mdp, utilisateur, mdp_utilisateur))
                            Console::afficher("\t> L'authentification a échoué.");
                    }
                }
            }
        }
    }
}