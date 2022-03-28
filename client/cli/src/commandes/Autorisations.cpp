#include "../../include/commandes/Autorisations.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                const int Autorisations::liste(const std::string mdp) const
                {
                    const std::vector<std::string> cles = Client::Scripts::Autorisations::liste(Contexte::identite(), mdp);
                    if (cles.size() == 0)
                        Console::afficher("> Aucune autorisation enregistrée.");
                    else
                    {
                        Console::afficher("> Autorisations enregistrées : ");
                        for (const std::string& cle : cles)
                            Console::afficher("\t- " + cle);
                    }
                    return 0;

                }

                const int Autorisations::ajout(const std::string mdp, const std::string fichier_cible) const
                {
                    Console::afficher("> Importation de la clé publique depuis le fichier cible...");
                    std::ifstream fichier = Fichiers::lecture(fichier_cible, "", true, false);
                    const Protocole::Cle::Publique cle{ fichier };
                    if (Client::Scripts::Autorisations::autoriser(cle, Contexte::identite(), mdp))
                    {
                        Console::afficher("> Autorisation ajoutée.");
                        return 0;
                    }
                    return -1; // throw Erreur::Commandes::Autorisations::; // TODO Erreur dédiée.
                }

                const int Autorisations::suppression(const std::string mdp, const std::string empreinte) const
                {
                    Console::afficher("> Suppression de l'autorisation pour l'empreinte \"" + empreinte + "\"...");
                    if (Client::Scripts::Autorisations::revoquer(empreinte, Contexte::identite(), mdp))
                    {
                        Console::afficher("> Autorisation révoquée.");
                        return 0;
                    }
                    else return -1; // throw Erreur::Commandes::Autorisations::Inexistante(empreinte); // TODO Erreur dédiée.
                }

                const int Autorisations::executer(const int argc, const char** argv) const
                {
                    const std::string mdp = ""; // Console::demander("> Mot de passe de l'identité : ");

                    if (argc == 2)      // Format : bttp-cli auth            ->      Affichage de la liste des clés publiques autorisées.
                        return this->liste(mdp);
                    else if (argc == 4) // Format : bttp-cli auth +/- <nom>  ->      Ajout ou suppression d'une autorisation.
                    {
                        if (strcmp(argv[2], BTTP_COMMANDE_AUTORISATIONS_AJOUT) == 0)
                            return this->ajout(mdp, argv[3]);
                        else if (strcmp(argv[2], BTTP_COMMANDE_AUTORISATIONS_SUPPRESSION) == 0)
                            return this->suppression(mdp, argv[3]);
                    }

                    Console::saut();
                    throw Erreur::Commandes::Syntaxe(this);
                }

                const std::string Autorisations::aide() const
                {
                    std::string aide = "Usage : bttp-cli ";
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