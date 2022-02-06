#include "../../include/message/ClePublique.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            namespace Test
            {
                Cle::Publique* ClePublique::cle = nullptr;
                Messages::ClePublique* ClePublique::message = nullptr;
                std::string ClePublique::construction = "";

                ClePublique::ClePublique() {};

                void ClePublique::SetUpTestCase()
                {
    
                    if (BTTP::Protocole::Test::Identite::destinataire == nullptr)
                        BTTP::Protocole::Test::Identite::destinataire = new Identite(
                            BTTP::Protocole::Test::Identite::nom_destinataire,
                            BTTP::Protocole::Test::Identite::nom_destinataire + BTTP::Protocole::Test::Identite::suffixe_contact,
                            BTTP::Protocole::Test::Identite::mdp_destinataire
                        );

                    cle = new Cle::Publique(BTTP::Protocole::Test::Identite::destinataire->cle_publique());
                }
                
                void ClePublique::TearDownTestCase()
                {
                    delete BTTP::Protocole::Test::Identite::destinataire;
                    delete cle;
                    if (message != nullptr) delete message;
                    construction = "";
                    BTTP::Protocole::Test::Identite::destinataire = nullptr;
                    cle = nullptr;
                }

                // CREATION
                TEST_F(ClePublique, CreationVide)
                {
                    if (message != nullptr) delete message;
                    message = new BTTP::Protocole::Messages::ClePublique();
                    EXPECT_THROW({ message->cle(); }, BTTP::Protocole::Erreur::Messages::ClePublique::Vide);
                    EXPECT_EQ(message->type(), BTTP::Protocole::Messages::Type::CLE_PUBLIQUE);
                }
        
                TEST_F(ClePublique, CreationDepuisClePublique)
                {
                    message = new BTTP::Protocole::Messages::ClePublique(*cle);
                    EXPECT_TRUE(message->cle() == *cle);
                    EXPECT_EQ(message->type(), BTTP::Protocole::Messages::Type::CLE_PUBLIQUE);
                }

                // CONSTRUCTION / DECONSTRUCTION
                TEST_F(ClePublique, Construction)
                {
                    if (message == nullptr) GTEST_SKIP();
                    construction = message->construire();
                    EXPECT_EQ(construction, message->type_c() + cle->write(OpenPGP::PGP::Armored::NO));
                }
                TEST_F(ClePublique, Deconstruction)
                {
                    if (construction == "") GTEST_SKIP();
                    if (message != nullptr) delete message;
                    message = new BTTP::Protocole::Messages::ClePublique();
                    message->deconstruire(construction);
                    EXPECT_EQ(message->cle(), *cle);
                }

                
            }
        }
    }
}