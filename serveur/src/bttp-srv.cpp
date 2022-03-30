#include "../include/BTTP-Serveur.h"

int main(const int argc, const char** argv)
{
    try
    {
        // Définition du mot de passe // TODO Externaliser dans un fichier ?
        std::cout << "Mot de passe de l'identité du serveur : ";
        std::string mdp;
        std::getline(std::cin, mdp);

        return BTTP::Serveur::executer(argc, argv, mdp);
    }
    catch (BTTP::Erreur& err) 
    {
        BTTP::Serveur::Journal::ecrire(err);
        return err.code();
    }
}