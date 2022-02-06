#include "../../include/identite/Identite.h"

namespace BTTP 
{
    namespace Protocole 
    {
        namespace Test 
        {
            const std::string Identite::message = "message de la plus haute importance";
            const std::string Identite::suffixe_contact = "@test.fr";

            BTTP::Protocole::Identite* Identite::emissaire = nullptr;
            const std::string Identite::nom_emissaire = "emissaire";
            const std::string Identite::mdp_emissaire = "p@ssw0rd";
         
            BTTP::Protocole::Identite* Identite::destinataire = nullptr;
            const std::string Identite::nom_destinataire = "destinataire";
            const std::string Identite::mdp_destinataire = "123fourfivesix";

            Identite::Identite() {}

            void Identite::SetUpTestCase() 
            {
                destinataire = new BTTP::Protocole::Identite(nom_destinataire, nom_destinataire + suffixe_contact, mdp_destinataire);
                emissaire = new BTTP::Protocole::Identite(nom_emissaire, nom_emissaire + suffixe_contact, mdp_emissaire);
            }

            void Identite::TearDownTestCase() 
            {
                delete emissaire;
                delete destinataire;

                emissaire = nullptr;
                destinataire = nullptr;
            }

            // CHIFFREMENT / DECHIFFREMENT
            TEST_F(Identite, ChiffrementDechiffrement)
            {
                if (emissaire == nullptr || destinataire == nullptr) GTEST_SKIP();
                const std::string message_chiffre = emissaire->chiffrer(message, destinataire->cle_publique(), mdp_emissaire);
                const std::string message_dechiffre = destinataire->dechiffrer(message_chiffre, emissaire->cle_publique(), mdp_destinataire);
                EXPECT_EQ(message, message_dechiffre);
            }
            
            TEST_F(Identite, MauvaisMotDePasse)
            {
                if (emissaire == nullptr || destinataire == nullptr) GTEST_SKIP();
                EXPECT_THROW({
                    emissaire->chiffrer(message, destinataire->cle_publique(), mdp_destinataire);
                }, BTTP::Protocole::Erreur::Identite::Chiffrement);

                const std::string message_chiffre = destinataire->chiffrer(message, emissaire->cle_publique(), mdp_destinataire);
                EXPECT_THROW({
                    emissaire->dechiffrer(message_chiffre, destinataire->cle_publique(), mdp_destinataire);
                }, BTTP::Protocole::Erreur::Identite::Dechiffrement);
            }
            
            TEST_F(Identite, MauvaiseClePublique)
            {
                if (emissaire == nullptr || destinataire == nullptr) GTEST_SKIP();
                const std::string message_chiffre = emissaire->chiffrer(message, destinataire->cle_publique(), mdp_emissaire);
                EXPECT_THROW({
                    destinataire->dechiffrer(message_chiffre, destinataire->cle_publique(), mdp_destinataire);
                }, BTTP::Protocole::Erreur::Identite::Dechiffrement);
            }
            TEST_F(Identite, ChiffrementCorrompu)
            {
                if (emissaire == nullptr || destinataire == nullptr) GTEST_SKIP();
                const std::string message_chiffre = emissaire->chiffrer(message, destinataire->cle_publique(), mdp_emissaire);
                EXPECT_THROW({ // Avant
                    destinataire->dechiffrer("virus" + message_chiffre, emissaire->cle_publique(), mdp_destinataire);
                }, BTTP::Protocole::Erreur::Identite::Dechiffrement);
                const std::string message_corrompu = message_chiffre.substr(0, message_chiffre.size() / 2) + "virus" + message_chiffre.substr(message_chiffre.size() / 2 + 1);
                EXPECT_THROW({ // Dedans
                    destinataire->dechiffrer(message_corrompu, emissaire->cle_publique(), mdp_destinataire);
                }, BTTP::Protocole::Erreur::Identite::Dechiffrement);
                EXPECT_THROW({ // Après
                    destinataire->dechiffrer(message_chiffre + "virus", emissaire->cle_publique(), mdp_destinataire);
                }, BTTP::Protocole::Erreur::Identite::Dechiffrement);
            }
        }
    }
}