#include "../../include/identite/Identite.h"

namespace BTTP
{
    namespace Protocole
    {
        Identite::Config Identite::config(const std::string nom, const std::string email, const std::string mdp)
        {
            OpenPGP::KeyGen::Config config;
            config.passphrase = mdp;
            config.pka        = PKA;
            config.bits       = BITS;
            config.sym        = SYM;
            config.hash       = HASH;
            
            OpenPGP::KeyGen::Config::UserID uid;
            uid.user          = nom;
            uid.comment       = BTTP_IDENTITE_COMMENTAIRE;
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

        const std::string Identite::fichier(const std::string nom, const std::string chemin, const bool dossier_contexte)
        { return (dossier_contexte ? Contexte::dossier() + '/' : "") + (chemin != "" ? chemin + '/' : "") + nom + '.' + BTTP_IDENTITE_EXT; }

        void Identite::genererClePrivee(std::string nom, std::string email, std::string mdp)
        {
            Config config = Identite::config(nom, email, mdp);
            this->_cle_privee = OpenPGP::KeyGen::generate_key(config);
        }

        void Identite::exporterClePrivee(
            const std::string nom, const bool armor, const std::string chemin, const bool creer_chemin, const bool dossier_contexte
        ) const
        {
            const std::string fichier = Identite::fichier(nom, chemin, dossier_contexte);
            if (std::filesystem::exists(fichier)) throw Erreur::Identite::Doublon(fichier);
            const std::string dossier = fichier.substr(0, fichier.find_last_of('/'));
            if (!std::filesystem::is_directory(dossier))
            {
                if (creer_chemin) std::filesystem::create_directories(dossier);
                else throw Erreur::Identite::Exportation(fichier);
            }
            std::ofstream fichier_ex(fichier, std::ios::binary);
            if (!fichier_ex) throw Erreur::Identite::Exportation(fichier);
            fichier_ex << this->_cle_privee.write((armor ? OpenPGP::PGP::Armored::YES : OpenPGP::PGP::Armored::NO)) << std::flush;
            fichier_ex.close();
        }

        void Identite::importerClePrivee(const std::string nom, const std::string chemin, const bool dossier_contexte)
        {
            const std::string fichier = Identite::fichier(nom, chemin, dossier_contexte);
            std::ifstream fichier_im(fichier, std::ios::binary);
            if (!fichier_im) throw Erreur::Identite::Importation(fichier);
            this->_cle_privee = OpenPGP::SecretKey(fichier_im);
            fichier_im.close();
        }

        Identite::Identite(
            const std::string nom, const std::string email, const std::string mdp, const std::string chemin, const bool dossier_contexte
        )
        {
            this->genererClePrivee(nom, email, mdp);
            this->exporterClePrivee(nom, BTTP_IDENTITE_ARMOR, chemin, dossier_contexte);
        }

        Identite::Identite(const std::string nom, const std::string chemin, const bool dossier_contexte) 
        {
            this->importerClePrivee(nom, chemin, dossier_contexte);
        }

        // TOCOMMENT
        const std::string Identite::traduireMessage(const OpenPGP::Message message_pgp)
        {
            std::string message = "";
            bool saut = false; // On retire le premier saut à la ligne
            for(OpenPGP::Packet::Tag::Ptr const & p : message_pgp.get_packets())
            {
                if (p->get_tag() == OpenPGP::Packet::LITERAL_DATA)
                    message += std::static_pointer_cast<OpenPGP::Packet::Tag11>(p)->out(false);
                else if (saut) message += "\n";
                else saut = true;
            }
            message.pop_back(); // On retire le dernier saut à la ligne
            return message;
        }

        const std::string Identite::chiffrer(const std::string message, const ClePublique destinataire, const std::string mdp) const
        {
            // Configuration du chiffrement
            OpenPGP::SecretKey::Ptr signataire = std::make_shared<OpenPGP::SecretKey>(_cle_privee);
            if (!signataire->meaningful()) throw Erreur::Identite::Chiffrement("La clé privée est incohérente.", message);
            const OpenPGP::Encrypt::Args args("", message, SYM, COMP, true, signataire, mdp, HASH);
            if (!args.valid()) throw Erreur::Identite::Chiffrement("Les arguments de chiffrement sont invalides.", message);
            // Chiffrement et signature du message
            OpenPGP::Message message_chiffre;
            try { message_chiffre = OpenPGP::Encrypt::pka(args, destinataire); }
            catch (std::exception& e) { throw Erreur::Identite::Chiffrement(e.what(), message); }
            if (!message_chiffre.meaningful()) throw Erreur::Identite::Chiffrement("L'intégrité du message n'a pu être vérifiée.", message);
            // Retour au format brut
            return message_chiffre.raw();
        }

        const std::string Identite::dechiffrer(const std::string message, const ClePublique emissaire, const std::string mdp) const
        {
            // Déchiffrement du message
            OpenPGP::Message message_dechiffre;
            try { message_dechiffre = OpenPGP::Decrypt::pka(this->_cle_privee, mdp, message); }
            catch (std::exception& err) { throw Erreur::Identite::Dechiffrement(err.what()); }
            if (!message_dechiffre.meaningful()) throw Erreur::Identite::Dechiffrement("L'intégrité du message n'a pu être vérifiée.");
            // Vérification de la signature
            OpenPGP::Key::Ptr signataire = std::make_shared<OpenPGP::Key>(emissaire);
            if (!signataire->meaningful()) throw Erreur::Identite::Dechiffrement("La clé publique est incohérente.");
            if (!OpenPGP::Verify::binary(*signataire, message_dechiffre))
                throw Erreur::Identite::Dechiffrement("La vérification de la signature a échoué.");
            // Traduction en chaine de caractère (voir Identite::traduireMessage)
            return traduireMessage(message_dechiffre);
        }
    }
}