#ifndef H_BTTP_TEST_MESSAGE_EXECUTION
#define H_BTTP_TEST_MESSAGE_EXECUTION

#include "../identite/Identite.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Test
        {
            namespace Messages
            {
                class Execution : public ::testing::Test 
                {
                public:
                    Execution();
                    static void SetUpTestCase();
                    static void TearDownTestCase();
                };
            }
        }
    }
}

#endif