#include "../../include/identite/Meta.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Test
        {
            BTTP::Protocole::Meta* Meta::meta = nullptr;
            std::string Meta::contact = "";

            Meta::Meta() {}

            void Meta::SetUpTestCase()
            {
                Identite::destinataire = new BTTP::Protocole::Identite(Identite::nom_destinataire, Identite::nom_destinataire + Identite::suffixe_contact, Identite::mdp_destinataire);
                contact = Identite::nom_destinataire + Identite::suffixe_contact;
            }

            void Meta::TearDownTestCase()
            {
                delete meta;
                delete Identite::destinataire;
                contact = "";

                meta = nullptr;
                Identite::destinataire = nullptr;

            }

            // CREATION
            TEST_F(Meta, Creation)
            {
                meta = new BTTP::Protocole::Meta(Identite::nom_destinataire, contact, BTTP_IDENTITE_COMMENTAIRE);
                EXPECT_EQ(meta->nom(), Identite::nom_destinataire);
                EXPECT_EQ(meta->contact(), contact);
                EXPECT_EQ(meta->commentaire(), BTTP_IDENTITE_COMMENTAIRE);
            }
            TEST_F(Meta, CreationDepuisClePublique)
            {
                if (Identite::destinataire == nullptr) GTEST_SKIP();
                if (meta != nullptr) delete meta;
                meta = new BTTP::Protocole::Meta(Identite::destinataire->cle_publique());
                EXPECT_EQ(meta->nom(), Identite::nom_destinataire);
                EXPECT_EQ(meta->contact(), contact);
                EXPECT_EQ(meta->commentaire(), BTTP_IDENTITE_COMMENTAIRE);
            }
        }
    }
}