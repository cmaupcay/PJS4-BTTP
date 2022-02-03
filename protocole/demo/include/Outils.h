#ifndef H_BTTP_DEMO_OUTILS
#define H_BTTP_DEMO_OUTILS

#include <iostream>

const std::string demander(const std::string message)
{
    std::string sortie;
    std::cout << message;
    std::getline(std::cin, sortie);
    return sortie;
}

const std::string dossier_depuis_fichier(const std::string fichier)
{ return fichier.substr(0, fichier.find_last_of('/')); }

#endif