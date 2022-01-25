#ifndef H_IDENTITE
#define H_IDENTITE

#include "OpenPGP.h"
#include <fstream>
#include <assert.h>

namespace BTTP 
{
    namespace Protocole 
    {

        class Idendite 
        {

            private:
                OpenPGP::PublicKey _cle_publique;
                OpenPGP::SecretKey _cle_privee;
                OpenPGP::SecretKey genererCles(std::string nom, std::string email, std::string mdp);
                static OpenPGP::KeyGen::Config config(std::string nom, std::string email, std::string mdp);
            
            public:
                OpenPGP::PublicKey cle_publique();
                Idendite();
                Idendite(std::string nom, std::string email, std::string mdp);
                OpenPGP::Message chiffrer(std::string message, OpenPGP::PublicKey pub, std::string mdp);
                std::string dechiffer(OpenPGP::Message message_chiffre, OpenPGP::PublicKey pub, std::string mdp);
    
        };
        

    }



}

#endif