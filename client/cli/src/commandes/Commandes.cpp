#include "../../include/commandes/Commandes.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Commandes
            {
                const std::vector<Commande*> commandes()
                {
                    std::vector<Commande*> c;
                    c.push_back(new Autorisations());
                    c.push_back(new Distant());
                    c.push_back(new Execution());
                    c.push_back(new Identites());
                    c.push_back(new Scripts());
                    c.push_back(new Serveurs());
                    return c;
                }

                const int resoudre(const int argc, const char** argv)
                {
                    if (argc > 1)
                    {
                        const std::vector<Commande*> com = commandes();
                        for (const Commande* c : com)
                            if (argv[1] == c->nom())
                            {
                                try 
                                { 
                                    c->executer(argc, argv);
                                    return EXIT_SUCCESS; 
                                }
                                catch (Erreur::Commandes::Syntaxe& err)
                                {
                                    Console::afficher(c->aide());
                                    return err.code();
                                }
                            }
                        throw Erreur::Commandes::Inconnue(argv[1]);
                    }
                    Console::afficher(aide());
                    return EXIT_FAILURE;
                }

                const std::string aide()
                {
                    std::string aide = "Usage : bttp-cli <commande> [options]\nCommandes : ";
                    const std::vector<Commande*> com = commandes();
                    const size_t n_com = commandes().size();
                    for (size_t c = 0; c < n_com; c++)
                    {
                        aide += com[c]->nom();
                        if (c < n_com - 1) aide += ", ";
                    }
                    return aide;
                }
            }
        }
    }
}