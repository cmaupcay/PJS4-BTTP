#ifndef H_BTTP_TEST_IDENTITE
#define H_BTTP_TEST_IDENTITE

#include "../Racine.h"

#define BTTP_TEST_DOSSIER_ID BTTP_TEST_DOSSIER "/id"

namespace BTTP 
{
    namespace Protocole
    {
        namespace Test
        {
            class Identite : public ::testing::Test 
            {
            public:
                static std::string dossier;
                static const std::string message;
                static const std::string suffixe_contact;

                static BTTP::Protocole::Identite* emissaire;
                static std::string nom_emissaire;
                static std::string mdp_emissaire;
                
                static BTTP::Protocole::Identite* destinataire;
                static std::string nom_destinataire;
                static std::string mdp_destinataire;

                Identite();
                static void SetUpTestCase();
                static void TearDownTestCase();
            };
        }
    }
}

#endif