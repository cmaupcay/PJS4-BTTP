#ifndef H_BTTP_CLES
#define H_BTTP_CLES

#include "../Racine.h"

#ifndef BTTP_IDENTITE_COMMENTAIRE
    #define BTTP_IDENTITE_COMMENTAIRE "BTTP version " BTTP_VERSION " via calccrypto/OpenPGP"
#endif

#include <OpenPGP.h>

namespace BTTP
{
    namespace Protocole
    {
        namespace Cle
        {
            /**
             * @brief Configuration de la génération de clé.
             * @details Cette implémentation est basée sur la bibliothèque OpenPGP de calccrypto.
             * Repos : https://github.com/calccrypto/OpenPGP
             */
            class Config : public OpenPGP::KeyGen::Config
            {
            public:
                static const uint8_t PKA = OpenPGP::PKA::ID::RSA_ENCRYPT_OR_SIGN;
                static const std::size_t BITS = 4096;
                static const uint8_t SYM = OpenPGP::Sym::ID::AES256;
                static const uint8_t HASH = OpenPGP::Hash::ID::SHA1;
                static const uint8_t COMP = OpenPGP::Compression::ID::ZLIB;

                Config(const std::string nom, const std::string contact, const std::string mdp);
            };

            class Publique : public OpenPGP::PublicKey
            {
            public:
                explicit Publique(OpenPGP::PublicKey cle) : OpenPGP::PublicKey(cle) {};
            };
            
            class Privee : public OpenPGP::SecretKey
            {
            public:
                explicit Privee() : OpenPGP::SecretKey() {};
                explicit Privee(OpenPGP::SecretKey cle) : OpenPGP::SecretKey(cle) {};

                static inline Privee generer(Config config)
                { return Privee(OpenPGP::KeyGen::generate_key(config)); }
            };
        }
    }
}

#endif