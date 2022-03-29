#include "../../include/commandes/Scripts.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                void Scripts::liste() const
                {
                    const std::vector<Client::Serveurs::Serveur> serveurs = Client::Serveurs::liste();
                    if (serveurs.size() == 0) 
                        Console::afficher("> Aucun serveur de contrôle enregistré.");
                    else
                    {
                        for (const Client::Serveurs::Serveur& serveur : serveurs)
                            this->liste(serveur);
                    }
                }
                void Scripts::liste(const std::string serveur) const
                {
                    // TODO Erreur spécifique si le serveur n'existe pas.
                    const Client::Serveurs::Serveur serveur_obj = Client::Serveurs::charger(serveur);
                    this->liste(serveur_obj);
                }
                void Scripts::liste(const Client::Serveurs::Serveur& serveur) const
                {
                    const std::vector<Client::Scripts::Script> scripts = Client::Scripts::liste(serveur);
                    const size_t n = scripts.size();
                    if (n == 0) Console::afficher("> Aucun script enregistré pour \"" + serveur.nom() + "\".");
                    else
                    {
                        Console::afficher("> Liste des scripts pour \"" + serveur.nom() + "\" :");
                        for (const Client::Scripts::Script& script : scripts)
                            Console::afficher("\t#" + std::to_string(script.id()) + " - " + script.nom());
                    }
                }

                void Scripts::ajout(const std::string script) const
                {
                    const std::string fichier_source = Console::demander("> Fichier source : ");
                    Console::afficher("> Lecture du fichier source...");
                    const std::string source = Fichiers::lire(fichier_source, "", false, false);

                    Client::Serveurs::Serveur serveur = Commande::definir_serveur();
                    Console::afficher("> Serveur : " + serveur.informations());
                    Console::afficher("> Connexion au serveur...");
                    serveur.connexion().ouvrir();

                    const std::string mdp = Console::demander("> Mot de passe de l'identité locale : ");
                    Commande::authentification(serveur, mdp);

                    Console::afficher("> Ajout du script \"" + script + "\"...");
                    const Client::Scripts::Script script_obj = Client::Scripts::ajouter(script, source, serveur, Contexte::identite(), mdp);
                    Console::afficher("> Script ajouté ! Fichier local : " + Fichiers::chemin(script_obj.reference(), BTTP_SCRIPT_DOSSIER, false));

                    Console::afficher("> Fermeture de la connexion...");
                    serveur.connexion().fermer();
                }

                const Client::Scripts::Script Scripts::charger(const Client::Serveurs::Serveur& serveur, const std::string script) const
                {
                    const std::vector<Client::Scripts::Script> scripts = Client::Scripts::liste(serveur);
                    for (const Client::Scripts::Script& s : scripts)
                        if (s.nom() == script) return s;
                    // throw // TODO Erreur Scripts::Inexistant
                }

                void Scripts::suppression(const std::string script) const
                {
                    Client::Serveurs::Serveur serveur = Commande::definir_serveur();
                    Console::afficher("> Serveur : " + serveur.informations());
                    Console::afficher("> Connexion au serveur...");
                    serveur.connexion().ouvrir();

                    const std::string mdp = Console::demander("> Mot de passe de l'identité locale : ");
                    Commande::authentification(serveur, mdp);

                    Console::afficher("> Suppression du script \"" + script + "\"...");
                    const Client::Scripts::Script script_obj = this->charger(serveur, script);
                    Client::Scripts::supprimer(script_obj, serveur, Contexte::identite(), mdp);
                    Console::afficher("> Script supprimé.");

                    Console::afficher("> Fermeture de la connexion...");
                    serveur.connexion().fermer();
                }

                void Scripts::exportation(const std::string script) const
                {
                    Client::Serveurs::Serveur serveur = Commande::definir_serveur();
                    Console::afficher("> Serveur : " + serveur.informations());

                    Console::afficher("> Lecture du fichier cible...");
                    const Client::Scripts::Script script_obj = this->charger(serveur, script);
                    const std::string contenu = Fichiers::lire(script_obj.reference(), BTTP_SCRIPT_DOSSIER, true);

                    Console::afficher("> Exportation...");
                    const std::string dossier = Console::demander("\tDossier de destination : ");
                    Fichiers::ecrire(contenu, script, dossier, false, true, false);
                    Console::afficher("> Script exporté.");
                }

                void Scripts::executer(const int argc, const char** argv) const
                {
                    if (argc == 2)      // Format : bttp-cli src            ->      Affichage de la liste des scripts par serveur.
                        this->liste();
                    else if (argc == 3) // Format : bttp-cli src <nom>      ->      Affichage de la liste des scripts pour le serveur cible.
                        this->liste(argv[2]);
                    else if (argc == 4) // Format : bttp-cli src +/- <nom>  ->      Ajout, suppression ou exportation d'un script.
                    {
                        if (strcmp(argv[2], BTTP_COMMANDE_SCRIPTS_AJOUT) == 0)
                            this->ajout(argv[3]);
                        else if (strcmp(argv[2], BTTP_COMMANDE_SCRIPTS_SUPPRESSION) == 0)
                            this->suppression(argv[3]);
                        else if (strcmp(argv[2], BTTP_COMMANDE_SCRIPTS_EXPORT) == 0)
                            this->exportation(argv[3]);
                        else throw Erreur::Commandes::Syntaxe(this);
                    }
                    else throw Erreur::Commandes::Syntaxe(this);

                }

                const std::string Scripts::aide() const
                {
                    std::string aide = "Gestion des scripts locaux.\nUsage : bttp-cli ";
                    aide += BTTP_COMMANDE_SCRIPTS;
                    aide += " [[";
                    aide += BTTP_COMMANDE_SCRIPTS_AJOUT;
                    aide += "|";
                    aide += BTTP_COMMANDE_SCRIPTS_SUPPRESSION;
                    aide += "|";
                    aide += BTTP_COMMANDE_SCRIPTS_EXPORT;
                    aide += "] <nom>]";
                    return aide;
                }
            }
        }
    }
}