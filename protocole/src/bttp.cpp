#include <iostream>
#include "Identite.h"

// Pour build les cocos : g++ bttp.cpp -o bttp -lOpenPGP 

int main() {

    BTTP::Protocole::Idendite id = BTTP::Protocole::Idendite();
    
    std::cout << "Entrez un message à chiffrer : ";
    std::string message;
    
    char buffer[100];

    std::cin.getline(buffer, 100);

    message = (std::string) buffer;

    OpenPGP::Message message_chiffre = id.chiffrer(message, id.cle_publique());

    std::cout << "Message chiffré et signé : \n" << message_chiffre.write(OpenPGP::PGP::Armored::YES) << std::endl;

    std::cout << "Déchiffrer ?";

    std::cin.get();

    std::cout << "Message déchiffré : " << id.dechiffer(message_chiffre, id.cle_publique());

    
}