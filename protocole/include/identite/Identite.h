#ifndef H_BTTP_IDENTITE
#define H_BTTP_IDENTITE

#include "../Racine.h"

#ifndef BTTP_IDENTITE_FICHIER
    #define BTTP_IDENTITE_FICHIER "cle.bttp.asc"
#endif
#ifndef BTTP_IDENTITE_COMMENTAIRE
    #define BTTP_IDENTITE_COMMENTAIRE "BTTP version " BTTP_VERSION " via calccrypto/OpenPGP"
#endif

#include <OpenPGP.h>
#include <fstream>

#include "erreur/Importation.h"
#include "erreur/Exportation.h"
#include "erreur/Chiffrement.h"
#include "erreur/Dechiffrement.h"

namespace BTTP 
{
    namespace Protocole 
    {
        class Identite 
        {
            public:
                typedef OpenPGP::KeyGen::Config Config;
                typedef OpenPGP::PublicKey ClePublique;
                typedef OpenPGP::SecretKey ClePrivee;

            private:
                static const uint8_t PKA = OpenPGP::PKA::ID::RSA_ENCRYPT_OR_SIGN;
                static const std::size_t BITS = 4096;
                static const uint8_t SYM = OpenPGP::Sym::ID::AES256;
                static const uint8_t HASH = OpenPGP::Hash::ID::SHA1;
                static const uint8_t COMP = OpenPGP::Compression::ID::ZLIB;

                ClePrivee _cle_privee;

                static const std::string traduireMessage(const OpenPGP::Message message_pgp);

            protected:
                static Config config(const std::string nom, const std::string email, const std::string mdp);
                void genererClePrivee(const std::string nom, const std::string email, const std::string mdp);
                void exporterClePrivee(const std::string fichier = BTTP_IDENTITE_FICHIER, const bool armor = true) const;
                void importerClePrivee(const std::string fichier = BTTP_IDENTITE_FICHIER);
            
            public:
                Identite();
                Identite(const std::string nom, const std::string email, const std::string mdp);
                inline const ClePublique cle_publique() const { return this->_cle_privee.get_public(); }

                const std::string chiffrer(const std::string message, const ClePublique cle_publique, const std::string mdp);
                const std::string dechiffrer(const std::string message, const ClePublique cle_publique, const std::string mdp);
        };
    }
}
#endif