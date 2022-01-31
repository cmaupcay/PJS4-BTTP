#include "../include/MessageDemo.h"
#include <iostream>

const std::string demander(const std::string message)
{
    std::string sortie;
    std::cout << message;
    std::getline(std::cin, sortie);
    return sortie;
}

const std::string dossier_depuis_fichier(const std::string fichier)
{ return fichier.substr(0, fichier.length() - fichier.find_last_of('/') + 1); }

int main(const int argc, const char** args)
{
    std::string dossier = dossier_depuis_fichier(args[0]);
    if (!std::filesystem::is_directory(dossier))
        dossier = std::filesystem::current_path();
    BTTP::Protocole::Contexte::initialiser(dossier);
    std::cout << "bttp v" << BTTP_VERSION << " - dev" << std::endl;
    std::cout << "Dossier de travail : " << BTTP::Protocole::Contexte::dossier() << std::endl;

    try 
    { 
        BTTP::Protocole::Identite* id = nullptr;
        std::string mdp;
        const std::string nom = demander("Nom : ");
    
        try
        {
            id = new BTTP::Protocole::Identite(nom);
            mdp = demander("Mot de passe : ");
        }
        catch (BTTP::Protocole::Erreur::Identite_Importation& e)
        {
            const std::string email = demander("E-mail : ");
            mdp = demander("Mot de passe : ");
            id = new BTTP::Protocole::Identite(nom, email, mdp);
        } 
        
        const std::string contenu = demander("Entrez un message à chiffrer : ");
        MessageDemo msg{ contenu };

        std::string paquet = msg.construire();
        // paquet = "virus" + paquet; // Corruption du paquet
        std::cout << "Paquet : " << paquet << std::endl;

        std::string paquet_chiffrer = id->chiffrer(paquet, id->cle_publique(), mdp);
        // paquet_chiffrer += "virus"; // Corruption du paquet chiffré

        const std::string paquet_dechiffrer = id->dechiffrer(paquet_chiffrer, id->cle_publique(), mdp);
        std::cout << "Paquet déchiffré : " << paquet_dechiffrer;

        MessageDemo msg_recu{ "" };
        msg_recu.deconstruire(paquet_dechiffrer);
        std::cout << "Message déchiffré : " << msg_recu.lire();
    }
    catch (BTTP::Erreur& err) { std::cout << err; }

}