#include "../include/Console.h"

namespace BTTP
{
    namespace Client
    {
        namespace CLI
        {
            const std::string Console::demander(const std::string message)
            {
                std::string sortie;
                std::cout << message;
                std::getline(std::cin, sortie);
                return sortie;
            }
        }
    }
}