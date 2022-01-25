#ifndef H_IDENTITE
#define H_IDENTITE

#ifndef IDENTITE_FICHIER
    #define IDENTITE_FICHIER "cle_privee.asc"
#endif

#include "OpenPGP.h"
#include <fstream>
#include <assert.h>

namespace BTTP 
{
    namespace Protocole 
    {
        typedef OpenPGP::KeyGen::Config Config;
        typedef OpenPGP::PublicKey ClePublique;
        typedef OpenPGP::SecretKey ClePrivee;

        class Identite 
        {
            private:
                static const uint8_t PKA = OpenPGP::PKA::ID::RSA_ENCRYPT_OR_SIGN;
                static const std::size_t BITS = 4096;
                static const uint8_t SYM = OpenPGP::Sym::ID::AES256;
                static const uint8_t HASH = OpenPGP::Hash::ID::SHA1;
                static const uint8_t COMP = OpenPGP::Compression::ID::ZLIB;

                ClePublique _cle_publique;
                ClePrivee _cle_privee;

                static const std::string traduireMessage(const OpenPGP::Message message_pgp);

            protected:
                static Config config(const std::string nom, const std::string email, const std::string mdp);
                void genererClePrivee(const std::string nom, const std::string email, const std::string mdp);
                void exporterClePrivee(const std::string fichier = IDENTITE_FICHIER) const;
                void importerClePrivee(const std::string fichier = IDENTITE_FICHIER);
                inline void definirClePublique() { this->_cle_publique = this->_cle_privee.get_public(); }
            
            public:
                Identite();
                Identite(const std::string nom, const std::string email, const std::string mdp);
                inline const ClePublique cle_publique() const { return this->_cle_publique; }

                const std::string chiffrer(const std::string message, const ClePublique cle_publique, const std::string mdp);
                const std::string dechiffer(const std::string message, const ClePublique cle_publique, const std::string mdp);
        };
    }
}
#endif