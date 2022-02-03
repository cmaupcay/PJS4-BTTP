#include "../include/MessageDemo.h"
#include "../include/Outils.h"

int main(const int argc, const char** args)
{
    std::string dossier = dossier_depuis_fichier(args[0]);
    if (!std::filesystem::is_directory(dossier))
        dossier = std::filesystem::current_path();
    BTTP::Protocole::Contexte::initialiser(dossier);
    std::cout << "bttp v" << BTTP_VERSION << " - demo" << std::endl;
    std::cout << "Dossier de travail : " << BTTP::Protocole::Contexte::dossier() << std::endl;
    std::cout << std::endl;

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
        std::cout << std::endl;

        const BTTP::Protocole::Meta meta{ id->cle_publique() };
        std::cout << "Bienvenue " << meta.nom() << " !" << std::endl;

        const std::string contenu = demander("Entrez un message à chiffrer : ");
        MessageDemo msg{ contenu };
        std::cout << std::endl;

        std::string paquet = msg.construire();
        // paquet = "virus" + paquet; // Corruption du paquet
        std::cout << "Paquet : " << paquet << std::endl;
        std::cout << "Longueur : " << paquet.size() << " octets" << std::endl;

        std::string paquet_chiffre = id->chiffrer(paquet, id->cle_publique(), mdp);
        // paquet_chiffre += "virus"; // Corruption du paquet chiffré
        std::cout << "Longueur (chiffré) : " << paquet_chiffre.size() << " octets" << std::endl;
        const float perte = (1.f - ((float)(paquet.size()) / paquet_chiffre.size())) * 100.f;
        std::cout << "Perte : " << std::fixed << std::setprecision(3) << perte << " %" << std::endl;
        std::cout << std::endl;

        const std::string paquet_dechiffre = id->dechiffrer(paquet_chiffre, id->cle_publique(), mdp);
        std::cout << "Paquet déchiffré : " << paquet_dechiffre << std::endl;

        MessageDemo msg_recu{ "" };
        msg_recu.deconstruire(paquet_dechiffre);
        std::cout << "Message déchiffré : " << msg_recu.lire() << std::endl;
    }
    catch (BTTP::Erreur& err) { std::cout << err; }

}