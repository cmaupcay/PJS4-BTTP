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
                /**
                 * @brief Les identités chiffre et signe les messages.
                 */
                static const uint8_t PKA = OpenPGP::PKA::ID::RSA_ENCRYPT_OR_SIGN;
                /**
                 * @brief Les clés des identités sont définies sur 4096 bits.
                 */
                static const std::size_t BITS = 4096;
                /**
                 * @brief Le chiffrement symétrique utilise AES-256.
                 */
                static const uint8_t SYM = OpenPGP::Sym::ID::AES256;
                /**
                 * @brief L'algorithme de hash utilisé par les identités est SHA1.
                 */
                static const uint8_t HASH = OpenPGP::Hash::ID::SHA1;
                /**
                 * @brief L'algorithme de compression utilisé par les identités est ZLIB.
                 */
                static const uint8_t COMP = OpenPGP::Compression::ID::ZLIB;

                /**
                 * @brief Création d'une configuration pour la génération d'une nouvelle clé privée.
                 * @param nom Nom du propriétaire de la clé.
                 * @param contact Contact identifiant le propriétaire.
                 * @param mdp Mot de passe de la clé privée.
                 */
                Config(const std::string nom, const std::string contact, const std::string mdp);
            };

            /**
             * @brief Clé publique relative à une identité.
             * @details Cette implémentation est basée sur la bibliothèque OpenPGP de calccrypto.
             * Repos : https://github.com/calccrypto/OpenPGP
             */
            class Publique : public OpenPGP::PublicKey
            {
            public:
                explicit Publique(OpenPGP::PublicKey cle) : OpenPGP::PublicKey(cle) {};
            };
            
            /**
             * @brief Clé privée relative à une identité.
             * @details Cette implémentation est basée sur la bibliothèque OpenPGP de calccrypto.
             * Repos : https://github.com/calccrypto/OpenPGP
             */
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