#include "../../include/commandes/Identites.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                const int Identites::liste() const
                {
                    const std::vector<Protocole::Identite> identites = Client::Identites::liste();
                    if (identites.size() == 0)
                        Console::afficher("> Aucune identité locale enregistrée.");
                    else
                    {
                        Console::afficher("> Identités locales enregistrées : ");
                        for (const Protocole::Identite& identite : identites)
                            Console::afficher("\t- " + Protocole::Meta(identite.cle_publique()).afficher());
                    }
                    return 0;

                }

                const int Identites::ajout(const std::string cible) const
                {
                    if (Client::Identites::existe(cible)) throw Erreur::Commandes::Identites::DejaExistante(cible);
                    Console::afficher("> Nouvelle identité nommée \"" + cible + "\" : ");
                    const std::string contact = Console::demander("\tContact associé : ");
                    // TODO Créer une fonction permettant de taper un mot de passe dans le terminal et demander confirmation du mot de passe.
                    const std::string mdp = Console::demander("\tMot de passe : ");
                    Console::afficher("> Génération de votre identité...");
                    const Protocole::Identite identite{ cible, contact, mdp };
                    Console::afficher("> Exportation de la nouvelle identité...");
                    Client::Identites::exporter(identite);
                    Console::afficher("> Identité créée avec succès.");
                    return 0;
                }

                void Identites::suppression(const std::string cible) const
                {
                    Console::afficher("> Suppression de l'identité \"" + cible + "\"...");
                    // TODO Demander mot de passe de l'identité ?
                    try { Client::Identites::supprimer(cible);}
                    catch (BTTP::Client::Erreur::Fichiers::Inexistant& e) { throw Erreur::Commandes::Identites::Inexistante(cible);}
                    Console::afficher("> Identité supprimée.");
                }

                const int Identites::exportation(const std::string cible) const
                {
                    // TODO Demander mot de passe de l'identité ?
                    Protocole::Identite identite = Client::Identites::importer(cible);
                    Console::afficher("> Identité importée.");
                    Console::afficher("> Exportation de l'identité \"" + cible + "\"...");
                    std::string destination = Console::demander("\tDossier de destination : ");
                    if (destination.size() == 0) destination = ".";
                    Fichiers::ecrire(identite.cle_publique().exporter(false), cible, destination, false, true, false, true);
                    Console::afficher("> Identité exportée.");
                    return 0;
                }

                void Identites::executer(const int argc, const char** argv) const
                {
                    if (argc == 2)      // Format : bttp-cli id            ->      Affichage de la liste des identités locales.
                        this->liste();
                    else if (argc == 4) // Format : bttp-cli id +/- <nom>  ->      Ajout ou suppression d'une identité locale.
                    {
                        if (strcmp(argv[2], BTTP_COMMANDE_IDENTITES_AJOUT) == 0)
                            this->ajout(argv[3]);
                        else if (strcmp(argv[2], BTTP_COMMANDE_IDENTITES_SUPPRESSION) == 0)
                            this->suppression(argv[3]);
                        else if (strcmp(argv[2], BTTP_COMMANDE_IDENTITES_EXPORT) == 0)
                            this->exportation(argv[3]);
                        else throw Erreur::Commandes::Syntaxe(this);
                    }
                    else throw Erreur::Commandes::Syntaxe(this);
                }

                const std::string Identites::aide() const
                {
                    std::string aide = "Usage : bttp-cli ";
                    aide += BTTP_COMMANDE_IDENTITES;
                    aide += " [";
                    aide += BTTP_COMMANDE_IDENTITES_AJOUT;
                    aide += "|";
                    aide += BTTP_COMMANDE_IDENTITES_SUPPRESSION;
                    aide += "|";
                    aide += BTTP_COMMANDE_IDENTITES_EXPORT;
                    aide += " <nom>]";
                    return aide;
                }
            }
        }
    }
}