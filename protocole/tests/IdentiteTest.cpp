#include "../include/tests/IdenditeTest.h"

namespace BTTP 
{

    namespace Protocole 
    {

        namespace Test 
        {

            BTTP::Protocole::Identite* IdentiteTest::id = NULL;
            std::string IdentiteTest::mdp = "";

            IdentiteTest::IdentiteTest() {}

            void IdentiteTest::SetUpTestCase() {
            
                mdp = "mdpTest";

                id = new Identite("test", "test@test.com", mdp);

            }

            void IdentiteTest::TearDownTestCase() {


                delete id;

                id = NULL;

                mdp = "";


            }

            TEST_F(IdentiteTest, ChiffrerDechiffrer){

                std::string mdpDest = "mdpDestinataire";

                Identite *destinataire = new Identite("destinataireTest", "destinataire@test.com", mdpDest);

                std::string message = "message";

                std::string chiffre = id->chiffrer(message, destinataire->cle_publique(), mdp);

                std::string dechiffre = destinataire->dechiffrer(chiffre, id->cle_publique(), mdpDest);

                ASSERT_EQ(message + "\n", dechiffre);

            }


        }


    }


}

int main(int argc, char* argv[])
{

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();

}

