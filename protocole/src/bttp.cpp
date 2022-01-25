#include <iostream>
#include "Identite.h"

// Pour build les cocos : g++ bttp.cpp -o bttp -lOpenPGP 

int main()
{
    BTTP::Protocole::Identite* id = nullptr;  

    std::cout << "Entrez le mot de passe de la clé : ";
    std::string mdp;

    std::cin >> mdp;

    id = new BTTP::Protocole::Identite("nom", "nom@email.com", mdp);
    // id = new BTTP::Protocole::Identite();

    std::cin.ignore();
    
    std::cout << "Entrez un message à chiffrer : ";
    std::string message;
    
    char buffer[100];

    std::cin.getline(buffer, 100);

    message = (std::string) buffer;

    const std::string message_chiffre = id->chiffrer(message, id->cle_publique(), mdp);

    std::cout << "Message chiffré et signé : \n" << message_chiffre << std::endl;

    std::cout << "Déchiffrer ?";

    std::cin.get();

    std::cout << "Message déchiffré : " << id->dechiffer(message_chiffre, id->cle_publique(), mdp);

    
}