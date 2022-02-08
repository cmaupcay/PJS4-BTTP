#include "../../include/message/Message.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Test
        {
            namespace Messages
            {
                const std::string Message::elements_x3[3] = {"entete", "contenu", "pied"};
                const std::string Message::elements_x6[6] = {"sara", "luca", "clément p.", "robin", "clément m.", "hemmbouk"};
                const std::string Message::elements_x12[12] = {"un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix", "onze", "douze"};

                Message::Message() {}

                void Message::SetUpTestCase()
                {
                }

                void Message::TearDownTestCase()
                {
                }

                const bool Message::decoupage_correct(
                    const std::string paquet, const std::string separateur,
                    const std::string elements[], const size_t n_elements
                )
                {
                    const std::vector<std::string> resultat = Protocole::Messages::decouper(paquet, separateur);
                    EXPECT_TRUE(resultat.size() == n_elements);
                    for (int p = 0; p < n_elements; p++)
                        EXPECT_TRUE(resultat[p] == elements[p]);
                    return true;
                }
                const bool Message::decoupage_correct(
                    const std::string paquet, const char separateur,
                    const std::string elements[], const size_t n_elements
                )
                {
                    const std::vector<std::string> resultat = Protocole::Messages::decouper(paquet, separateur);
                    EXPECT_TRUE(resultat.size() == n_elements);
                    for (int p = 0; p < n_elements; p++)
                        EXPECT_TRUE(resultat[p] == elements[p]);
                    return true;
                }

                // UTILITAIRES
                TEST(Message, DecoupagePaquet)
                {
                    EXPECT_TRUE(Message::decoupage_correct("entete-contenu-pied", '-', Message::elements_x3, 3));
                    EXPECT_TRUE(Message::decoupage_correct("entete°sep°contenu°sep°pied", "°sep°", Message::elements_x3, 3));
                    EXPECT_TRUE(Message::decoupage_correct(
                        "sara@luca@clément p.@robin@clément m.@hemmbouk",
                        '@', Message::elements_x6, 6
                    ));
                    EXPECT_TRUE(Message::decoupage_correct(
                        "saraøkaylucaøkayclément p.økayrobinøkayclément m.økayhemmbouk",
                        "økay", Message::elements_x6, 6
                    ));
                    EXPECT_TRUE(Message::decoupage_correct(
                        "un\\deux\\trois\\quatre\\cinq\\six\\sept\\huit\\neuf\\dix\\onze\\douze",
                        '\\', Message::elements_x12, 12
                    ));
                    EXPECT_TRUE(Message::decoupage_correct(
                        "un£$£$deux£$£$trois£$£$quatre£$£$cinq£$£$six£$£$sept£$£$huit£$£$neuf£$£$dix£$£$onze£$£$douze",
                        "£$£$", Message::elements_x12, 12
                    ));
                }
                TEST(Message, JointurePaquet)
                {
                    
                }
            }
        }
    }
}