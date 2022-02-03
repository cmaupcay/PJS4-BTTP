#ifndef H_BTTP_TEST_META
#define H_BTTP_TEST_META

#include "Identite.h"

namespace BTTP 
{
    namespace Protocole
    {
        namespace Test
        {
            class Meta : public ::testing::Test 
            {
            public:
                static BTTP::Protocole::Meta* meta;
                static std::string contact;

                Meta();
                static void SetUpTestCase();
                static void TearDownTestCase();
            };
        }
    }
}

#endif