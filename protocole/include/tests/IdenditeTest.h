#include <gtest/gtest.h>
#include <iostream>
#include "../identite/Identite.h"

namespace BTTP 
{
    namespace Protocole
    {

        namespace Test
        {

            class IdentiteTest : public ::testing::Test {

                public:
                    static BTTP::Protocole::Identite* id;
                    static std::string mdp;

                public:
                    IdentiteTest();
                    static void SetUpTestCase();
                    static void TearDownTestCase();

            };
            

        }

    }
}