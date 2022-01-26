#include "../include/BTTP.h"
#include <iostream>

// Build : g++ src/identite/Identite.cpp src/message/Message.cpp src/BTTP.cpp tests/bttp.cpp -o bin/bttp -lOpenPGP -lsegvcatch
// TODO Utiliser cmake

const std::string demander(const std::string message)
{
    std::string sortie;
    std::cout << message;
    std::getline(std::cin, sortie);
    return sortie;
}

int main()
{
    BTTP::Protocole::initialiser();
    std::cout << "bttp v" << BTTP_VERSION << " - dev" << std::endl;

    try 
    { 
        BTTP::Protocole::Identite* id = nullptr;
        std::string mdp;
    
        try
        {
            id = new BTTP::Protocole::Identite();
            mdp = demander("Mot de passe : ");
        }
        catch (BTTP::Protocole::Erreur::Identite_Importation& e)
        {
            const std::string nom = demander("Nom : ");
            const std::string email = demander("E-mail : ");
            mdp = demander("Mot de passe : ");
            id = new BTTP::Protocole::Identite(nom, email, mdp);
        } 
        
        const std::string message = demander("Entrez un message à chiffrer : ");

        std::string message_chiffre = id->chiffrer(message, id->cle_publique(), mdp);

        // std::cout << "Message chiffré et signé : \n" << message_chiffre << std::endl;
        // std::cout << "Déchiffrer ?";
        // std::cin.get();

        // Corruption du message
        // message_chiffre += "ok";

        const std::string message_dechiffre = id->dechiffrer(message_chiffre, id->cle_publique(), mdp);
        std::cout << "Message déchiffré : " << message_dechiffre; 

        // remove(BTTP_IDENTITE_FICHIER);
    }
    catch (BTTP::Erreur& err) { std::cout << err; }

}