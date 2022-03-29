#include "../include/Console.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            namespace Console
            {
                void afficher(const std::string message, const bool retour)
                {
                    std::cout << message;
                    if (retour) std::cout << std::endl;
                    std::cout << std::flush;
                }

                const std::string demander(const std::string message)
                {
                    std::string sortie;
                    std::cout << message;
                    std::getline(std::cin, sortie);
                    return sortie;
                }

                const std::string creationMdp() 
                {

                    std::string mdp = demander("\tMot de passe : ");
                    std::string confMdp = demander("\tConfirmation mot de passe : ");

                    if(mdp == confMdp)
                        return mdp;
                    
                    throw Erreur::ConfirmationMdp();

                }

            }
        }
    }
}