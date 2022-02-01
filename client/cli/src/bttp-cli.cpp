#include "../include/BTTP-CLI.h"

int main(const int argc, const char** argv)
{
    try
    {
        throw BTTP::Protocole::Erreur::Identite_Chiffrement("Ca marche pas.", "lol");
    }
    catch (BTTP::Erreur& err) 
    {
        std::cout << err << std::endl;
        return err.code();
    }

    return 0;
}