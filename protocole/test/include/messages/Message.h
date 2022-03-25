#ifndef H_BTTP_TEST_MESSAGE
#define H_BTTP_TEST_MESSAGE

#include "../identite/Identite.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Test
        {
            namespace Messages
            {
                class Message : public ::testing::Test 
                {
                public:
                    static const std::string elements_x3[3];
                    static const std::string elements_x6[6];
                    static const std::string elements_x12[12];

                    Message();
                    static void SetUpTestCase();
                    static void TearDownTestCase();

                    static void decoupage_correct(
                        const std::string paquet, const std::string separateur,
                        const std::string elements[], const size_t n_elements
                    );
                    static void decoupage_correct(
                        const std::string paquet, const char separateur,
                        const std::string elements[], const size_t n_elements
                    );

                    static void jointure_correcte(
                        const std::string attendu, const std::string separateur,
                        const std::string elements[], const size_t n_elements
                    );
                    static void jointure_correcte(
                        const std::string attendu, const char separateur,
                        const std::string elements[], const size_t n_elements
                    );
                };
            }
        }
    }
}

#endif