#ifndef H_BTTP_TEST_MESSAGE_CLE_PUBLIQUE
#define H_BTTP_TEST_MESSAGE_CLE_PUBLIQUE

#include "../identite/Identite.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            namespace Test
            {
                class ClePublique : public ::testing::Test 
                {
                public:
                    static Identite::ClePublique* cle;
                    static Messages::ClePublique* message;
                    static std::string construction;

                    ClePublique();
                    static void SetUpTestCase();
                    static void TearDownTestCase();
                };
            }
        }
    }
}

#endif