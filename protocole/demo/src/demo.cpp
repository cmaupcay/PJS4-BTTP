#include "../../include/BTTP.h"
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