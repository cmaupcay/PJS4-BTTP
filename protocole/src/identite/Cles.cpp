#include "../../include/identite/Cles.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Cle
        {
            Config::Config(const std::string nom, const std::string email, const std::string mdp)
            {
                this->passphrase = mdp;
                this->pka        = PKA;
                this->bits       = BITS;
                this->sym        = SYM;
                this->hash       = HASH;
                
                OpenPGP::KeyGen::Config::UserID uid;
                uid.user          = nom;
                uid.comment       = BTTP_IDENTITE_COMMENTAIRE;
                uid.email         = email;
                uid.sig           = HASH;
                this->uids.push_back(uid);

                OpenPGP::KeyGen::Config::SubkeyGen subkey;
                subkey.pka        = PKA;
                subkey.bits       = BITS;
                subkey.sym        = SYM;
                subkey.hash       = HASH;
                subkey.sig        = HASH;
                this->subkeys.push_back(subkey);
            }
        }
    }
}