#ifndef H_BTTP_CLES
#define H_BTTP_CLES

#include "../Racine.h"

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

                /**
                 * @brief Retourne l'empreinte permettant d'identifier la clé publique.
                 * @return const std::string Empreinte de la clé.
                 */
                inline const std::string empreinte() const { return hexlify(this->fingerprint()); }

                /**
                 * @brief Retourne la clé en un format exportable PGP.
                 * @param armor Drapeau indiquant l'utilisation du mode Armored d'OpenPGP.
                 * @return const std::string Clé au format exportable.
                 */
                inline const std::string exporter(const bool armor) const { return this->write((armor ? OpenPGP::PGP::Armored::YES : OpenPGP::PGP::Armored::NO)); }
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

                /**
                 * @brief Retourne l'empreinte permettant d'identifier la clé privéee.
                 * @return const std::string Empreinte de la clé.
                 */
                inline const std::string empreinte() const { return hexlify(this->fingerprint()); }

                /**
                 * @brief Retourne la clé en un format exportable PGP.
                 * @param armor Drapeau indiquant l'utilisation du mode Armored d'OpenPGP.
                 * @return const std::string Clé au format exportable.
                 */
                inline const std::string exporter(const bool armor) const { return this->write((armor ? OpenPGP::PGP::Armored::YES : OpenPGP::PGP::Armored::NO)); }
                
                static inline Privee generer(Config config)
                { return Privee(OpenPGP::KeyGen::generate_key(config)); }
            };
        }
    }
}

#endif