#include "../../include/commandes/Autorisations.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                void Autorisations::liste(const std::string mdp) const
                {
                    const std::vector<std::string> cles = Client::Scripts::Autorisations::liste(
                        *Contexte::client()->identite(), mdp, BTTP_AUTORISATIONS_DOSSIER, Contexte::client().get()
                    );
                    if (cles.size() == 0)
                        Console::afficher("> Aucune autorisation enregistrée.");
                    else
                    {
                        Console::afficher("> Autorisations enregistrées : ");
                        for (const std::string& cle : cles)
                            Console::afficher("\t- " + cle);
                    }
                }

                void Autorisations::ajout(const std::string mdp, const std::string fichier_cible) const
                {
                    Console::afficher("> Importation de la clé publique depuis le fichier cible...");
                    std::ifstream fichier = Fichiers::lecture(fichier_cible, "", true, Contexte::client().get());
                    const Protocole::Cle::Publique cle{ fichier };
                    if (Client::Scripts::Autorisations::autoriser(
                            cle, *Contexte::client()->identite(), mdp, BTTP_AUTORISATIONS_DOSSIER, Contexte::client().get()
                        ))
                        Console::afficher("> Autorisation ajoutée.");
                    else throw Erreur::Commandes::Autorisations::DejaExistante(cle.empreinte());

                }

                void Autorisations::suppression(const std::string mdp, const std::string empreinte) const
                {
                    Console::afficher("> Suppression de l'autorisation pour l'empreinte \"" + empreinte + "\"...");
                    if (Client::Scripts::Autorisations::revoquer(
                        empreinte, *Contexte::client()->identite(), mdp, BTTP_AUTORISATIONS_DOSSIER, Contexte::client().get()
                        ))
                        Console::afficher("> Autorisation révoquée.");
                    else throw Erreur::Commandes::Autorisations::Inexistante(empreinte);
                }

                void Autorisations::executer(const int argc, const char** argv, asio::io_context& contexte) const
                {
                    const std::string mdp = ""; // Console::demander("> Mot de passe de l'identité : ");

                    if (argc == 2)      // Format : bttp-cli auth            ->      Affichage de la liste des clés publiques autorisées.
                        this->liste(mdp);
                    else if (argc == 4) // Format : bttp-cli auth +/- <nom>  ->      Ajout ou suppression d'une autorisation.
                    {
                        if (strcmp(argv[2], BTTP_COMMANDE_AUTORISATIONS_AJOUT) == 0)
                            this->ajout(mdp, argv[3]);
                        else if (strcmp(argv[2], BTTP_COMMANDE_AUTORISATIONS_SUPPRESSION) == 0)
                            this->suppression(mdp, argv[3]);
                        else throw Erreur::Commandes::Syntaxe(this);
                    }
                    else throw Erreur::Commandes::Syntaxe(this);

                }

                const std::string Autorisations::aide() const
                {
                    std::string aide = "Gestion des autorisations d'exécution.\nUsage : bttp-cli ";
                    aide += BTTP_COMMANDE_AUTORISATIONS;
                    aide += " [";
                    aide += BTTP_COMMANDE_AUTORISATIONS_AJOUT;
                    aide += "|";
                    aide += BTTP_COMMANDE_AUTORISATIONS_SUPPRESSION;
                    aide += " <nom>]";
                    return aide;
                }
            }
        }
    }
}