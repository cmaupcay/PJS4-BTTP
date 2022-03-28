#include "../include/CLI.h"

int main(const int argc, const char** argv)
{
    int retour = 0;
    try
    { retour = BTTP::Client::CLI::executer(argc, argv); }
    catch (BTTP::Erreur& err) 
    {
        std::cerr << err << std::endl;
        retour = err.code();
    }

    BTTP::Client::CLI::Console::afficher("Retour : " + std::to_string(retour));
    return retour;
}