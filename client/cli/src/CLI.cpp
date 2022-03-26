#include "../include/CLI.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            const Protocole::Identite definir_identite()
            {

                std::vector<Protocole::Identite> identites = Client::Identites::liste();
                size_t n_identites = identites.size();
                if (n_identites == 0) // Génération
                {
                    Console::saut();
                    Console::afficher("> Génération de l'identité");
        
                    // Génération
                    const std::string nom = Console::demander("Identité : ");
                    const std::string contact = Console::demander("Contact : ");
                    // TODO Créer une fonction permettant de taper un mot de passe dans le terminal.
                    const std::string mdp = Console::demander("Mot de passe : ");
                    Console::afficher("> Génération...");
                    const Protocole::Identite id{ nom, contact, mdp };
                    // Exportation
                    Console::afficher("> Exportation...");
                    Identites::exporter(id);
                    return id;
                }
                else if (n_identites == 1) return identites[0];
                else
                {
                    // Affichage des identités locales.
                    size_t i_identite = n_identites;
                    while (i_identite >= n_identites || i_identite < 0)
                    {
                        Console::saut();
                        Console::afficher("> Sélection de l'identité");
                        for (size_t i = 0; i < n_identites; i++)
                            std::cout << "\t#" << i << " - " << Protocole::Meta(identites[i].cle_publique()) << std::endl;
                        Console::saut();
                        // Sélection dans la liste.
                        i_identite = std::atol(Console::demander("Identite à utiliser : ").c_str());
                    }
                    return identites[i_identite];
                }
            }

            const int executer(const int& argc, const char** argv)
            {
                // Détermination du dossier de travail...
                Contexte::initialiser(
                    // On prend le dossier où est situé l'exécutable.
                    std::filesystem::canonical(Fichiers::dossier(argv[0])).string()
                );

                // Affichage introductif
                Console::afficher(BTTP_CLIENT_CLI_INTRO);
                Console::afficher("Dossier : " + Contexte::dossier());

                // Définition de l'identité
                const Protocole::Identite id = definir_identite();
                // Affichage de l'identité courante.
                Console::saut();
                Console::afficher("Identité : " + Protocole::Meta(id.cle_publique()).afficher());
                
                Console::saut();
                const int code = Commandes::resoudre(argc, argv);
                Console::saut();

                return code;
            }
        }
    }
}