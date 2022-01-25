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
                OpenPGP::SecretKey genererCles(std::string nom, std::string email);
            
            public:
                OpenPGP::PublicKey cle_publique();
                Idendite();
                OpenPGP::Message chiffrer(std::string message, OpenPGP::PublicKey pub);
                std::string dechiffer(OpenPGP::Message message_chiffre, OpenPGP::PublicKey pub);
    
        };
        

    }



}

#endif