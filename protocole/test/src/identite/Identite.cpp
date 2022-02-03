#include "../../include/identite/Identite.h"

namespace BTTP 
{
    namespace Protocole 
    {
        namespace Test 
        {
            std::string Identite::dossier = "";
            const std::string Identite::message = "message de la plus haute importance";
            const std::string Identite::suffixe_contact = "@test.fr";

            BTTP::Protocole::Identite* Identite::emissaire = nullptr;
            std::string Identite::nom_emissaire = "emissaire";
            std::string Identite::mdp_emissaire = "";
         
            BTTP::Protocole::Identite* Identite::destinataire = nullptr;
            std::string Identite::nom_destinataire = "destinataire";
            std::string Identite::mdp_destinataire = "";

            Identite::Identite() {}

            void Identite::SetUpTestCase() 
            {
                mdp_emissaire = "p@ssw0rd";
                mdp_destinataire = "123fourfivesix";

                destinataire = new BTTP::Protocole::Identite(nom_destinataire, nom_destinataire + suffixe_contact, mdp_destinataire, BTTP_TEST_DOSSIER_ID, true);
            }

            void Identite::TearDownTestCase() 
            {
                delete emissaire, destinataire;
                mdp_emissaire = "";
                mdp_destinataire = "";
            }

            // CREATION
            TEST_F(Identite, CreationDansContexte)
            {
                emissaire = new BTTP::Protocole::Identite(nom_emissaire, nom_emissaire + suffixe_contact, mdp_emissaire, BTTP_TEST_DOSSIER_ID, true);
                ASSERT_TRUE(std::filesystem::exists(dossier + '/' + BTTP_TEST_DOSSIER_ID + '/' + nom_emissaire + '.' + BTTP_IDENTITE_EXT));
            }
            TEST_F(Identite, CreationDoublon)
            {
                if (!std::filesystem::exists(dossier + '/' + BTTP_TEST_DOSSIER_ID + '/' + nom_emissaire + '.' + BTTP_IDENTITE_EXT)) GTEST_SKIP();
                EXPECT_THROW({ // Création en double
                    new BTTP::Protocole::Identite(nom_emissaire, "autre" + suffixe_contact, mdp_emissaire, BTTP_TEST_DOSSIER_ID, true);
                }, BTTP::Protocole::Erreur::Identite_Doublon);
            }

            // IMPORTATION
            TEST_F(Identite, ImportationDepuisContexte)
            {
                if (!std::filesystem::exists(dossier + '/' + BTTP_TEST_DOSSIER_ID + '/' + nom_emissaire + '.' + BTTP_IDENTITE_EXT)) GTEST_SKIP();
                delete emissaire;
                emissaire = new BTTP::Protocole::Identite(nom_emissaire, BTTP_TEST_DOSSIER_ID, true);
            }
            TEST_F(Identite, ImportationImpossible)
            {
                if (std::filesystem::exists(dossier + '/' + BTTP_TEST_DOSSIER_ID + "/autre" + '.' + BTTP_IDENTITE_EXT)) GTEST_SKIP();
                EXPECT_THROW({ // Importation impossible
                    new BTTP::Protocole::Identite("autre", BTTP_TEST_DOSSIER_ID, true);
                }, BTTP::Protocole::Erreur::Identite_Importation);
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
                }, BTTP::Protocole::Erreur::Identite_Chiffrement);

                const std::string message_chiffre = destinataire->chiffrer(message, emissaire->cle_publique(), mdp_destinataire);
                EXPECT_THROW({
                    emissaire->dechiffrer(message_chiffre, destinataire->cle_publique(), mdp_destinataire);
                }, BTTP::Protocole::Erreur::Identite_Dechiffrement);
            }
            TEST_F(Identite, MauvaiseClePublique)
            {
                if (emissaire == nullptr || destinataire == nullptr) GTEST_SKIP();
                const std::string message_chiffre = emissaire->chiffrer(message, destinataire->cle_publique(), mdp_emissaire);
                EXPECT_THROW({
                    destinataire->dechiffrer(message_chiffre, destinataire->cle_publique(), mdp_destinataire);
                }, BTTP::Protocole::Erreur::Identite_Dechiffrement);
            }
            TEST_F(Identite, ChiffrementCorrompu)
            {
                if (emissaire == nullptr || destinataire == nullptr) GTEST_SKIP();
                const std::string message_chiffre = emissaire->chiffrer(message, destinataire->cle_publique(), mdp_emissaire);
                EXPECT_THROW({ // Avant
                    destinataire->dechiffrer("virus" + message_chiffre, emissaire->cle_publique(), mdp_destinataire);
                }, BTTP::Protocole::Erreur::Identite_Dechiffrement);
                const std::string message_corrompu = message_chiffre.substr(0, message_chiffre.size() / 2) + "virus" + message_chiffre.substr(message_chiffre.size() / 2 + 1);
                EXPECT_THROW({ // Dedans
                    destinataire->dechiffrer(message_corrompu, emissaire->cle_publique(), mdp_destinataire);
                }, BTTP::Protocole::Erreur::Identite_Dechiffrement);
                EXPECT_THROW({ // Après
                    destinataire->dechiffrer(message_chiffre + "virus", emissaire->cle_publique(), mdp_destinataire);
                }, BTTP::Protocole::Erreur::Identite_Dechiffrement);
            }
        }
    }
}