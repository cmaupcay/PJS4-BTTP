#include "Identite.h"

namespace BTTP
{
    namespace Protocole
    {
        Config Identite::config(const std::string nom, const std::string email, const std::string mdp)
        {
            OpenPGP::KeyGen::Config config;
            config.passphrase = mdp;
            config.pka        = PKA;
            config.bits       = BITS;
            config.sym        = SYM;
            config.hash       = HASH;

            OpenPGP::KeyGen::Config::UserID uid;
            uid.user          = nom;
            uid.comment       = "BTTP";
            uid.email         = email;
            uid.sig           = HASH;
            config.uids.push_back(uid);

            OpenPGP::KeyGen::Config::SubkeyGen subkey;
            subkey.pka        = PKA;
            subkey.bits       = BITS;
            subkey.sym        = SYM;
            subkey.hash       = HASH;
            subkey.sig        = HASH;
            config.subkeys.push_back(subkey);

            return config;
        }

        void Identite::genererClePrivee(std::string nom, std::string email, std::string mdp)
        {
            Config config = Identite::config(nom, email, mdp);
            this->_cle_privee = OpenPGP::KeyGen::generate_key(config);
        }

        void Identite::exporterClePrivee(const std::string fichier) const
        {
            std::ofstream fichier_ex(fichier, std::ios::binary);
            
            assert(fichier_ex); // TODO

            fichier_ex << this->_cle_privee.write(OpenPGP::PGP::Armored::YES) << std::flush;
            fichier_ex.close();
        }

        void Identite::importerClePrivee(const std::string fichier)
        {
            std::ifstream fichier_im(fichier, std::ios::binary);

            assert(fichier_im); // TODO

            this->_cle_privee = OpenPGP::SecretKey(fichier_im);
            fichier_im.close();
        }

        Identite::Identite(const std::string nom, const std::string email, const std::string mdp)
        {
            this->genererClePrivee(nom, email, mdp);
            this->exporterClePrivee();
            this->definirClePublique();
        }

        Identite::Identite() 
        {
            this->importerClePrivee();
            this->definirClePublique();
        }

        const std::string Identite::traduireMessage(const OpenPGP::Message message_pgp)
        {
            std::string message = "";
            for(OpenPGP::Packet::Tag::Ptr const & p : message_pgp.get_packets())
            {
                if (p->get_tag() == OpenPGP::Packet::LITERAL_DATA)
                    message += std::static_pointer_cast <OpenPGP::Packet::Tag11> (p) -> out(false);
                else message += "\n";
            }
            return message;
        }

        const std::string Identite::chiffrer(const std::string message, const ClePublique cle_publique, const std::string mdp)
        {
            OpenPGP::SecretKey::Ptr signataire = std::make_shared<OpenPGP::SecretKey>(_cle_privee);
            const OpenPGP::Encrypt::Args args("", message, SYM, COMP, true, signataire, mdp, HASH);
            const OpenPGP::Message message_chiffre = OpenPGP::Encrypt::pka(args, cle_publique);

            assert (message_chiffre.meaningful()); // TODO Exception

            return message_chiffre.raw();

        }

        const std::string Identite::dechiffer(const std::string message, const ClePublique cle_publique, const std::string mdp)
        {
            const OpenPGP::Message message_dechiffre = OpenPGP::Decrypt::pka(this->_cle_privee, mdp, message);

            if(!message_dechiffre.meaningful()) return ""; // TODO Exception

            OpenPGP::Key::Ptr signataire = std::make_shared<OpenPGP::Key>(cle_publique);
            const int verifie = OpenPGP::Verify::binary(*signataire, message_dechiffre);

            assert(verifie); // TODO Exception

            return traduireMessage(message_dechiffre);

        }
    }
}