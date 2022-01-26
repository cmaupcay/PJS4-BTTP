#include <iostream>
#include "../include/BTTP.h"

// Pour build les cocos : g++ identite/Identite.cpp bttp.cpp -o ../bin/bttp -lOpenPGP
// TODO Utiliser cmake

const std::string demander(const std::string message)
{
    std::string sortie;
    std::cout << message;
    std::cin >> sortie;
    std::cin.ignore();
    return sortie;
}

int main()
{
    std::cout << "bttp v" << BTTP_VERSION << " - dev" << std::endl;
    BTTP::Protocole::Identite* id = nullptr;
    std::string mdp;
  
    try
    {
        id = new BTTP::Protocole::Identite();
        mdp = demander("Mot de passe : ");
    }
    catch (BTTP::Protocole::Erreur::Identite_Importation* e)
    {
        const std::string nom = demander("Nom : ");
        const std::string email = demander("E-mail : ");
        mdp = demander("Mot de passe : ");
        id = new BTTP::Protocole::Identite(nom, email, mdp);
    } 
    
    std::cout << "Entrez un message à chiffrer : ";
    std::string message;
    
    char buffer[100];

    std::cin.getline(buffer, 100);

    message = (std::string) buffer;

        const std::string message_chiffre = id->chiffrer(message, id->cle_publique(), mdp);

        // std::cout << "Message chiffré et signé : \n" << message_chiffre << std::endl;
        // std::cout << "Déchiffrer ?";
        // std::cin.get();

        // const std::string message_errone = message_chiffre + "ok";

        std::cout << "Message déchiffré : " << id->dechiffer(message_chiffre, id->cle_publique(), mdp);

    // remove(BTTP_IDENTITE_FICHIER);
}