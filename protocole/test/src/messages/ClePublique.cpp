#include "../../include/messages/ClePublique.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Test
        {
            namespace Messages
            {
                Cle::Publique* ClePublique::cle = nullptr;
                Protocole::Messages::ClePublique* ClePublique::message = nullptr;
                std::string ClePublique::construction = "";

                ClePublique::ClePublique() {};

                void ClePublique::SetUpTestCase()
                {
    
                    if (Identite::destinataire == nullptr)
                        Identite::destinataire = new Protocole::Identite(
                            Identite::nom_destinataire,
                            Identite::nom_destinataire + Identite::suffixe_contact,
                            Identite::mdp_destinataire
                        );

                    cle = new Cle::Publique(Identite::destinataire->cle_publique());
                }
                
                void ClePublique::TearDownTestCase()
                {
                    delete Identite::destinataire;
                    delete cle;
                    if (message != nullptr) delete message;
                    construction = "";
                    Identite::destinataire = nullptr;
                    cle = nullptr;
                }

                // CREATION
                TEST_F(ClePublique, CreationVide)
                {
                    if (message != nullptr) delete message;
                    message = new BTTP::Protocole::Messages::ClePublique();
                    EXPECT_THROW({ message->cle(); }, BTTP::Protocole::Erreur::Messages::Vide);
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