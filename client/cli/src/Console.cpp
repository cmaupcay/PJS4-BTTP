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
            }
        }
    }
}