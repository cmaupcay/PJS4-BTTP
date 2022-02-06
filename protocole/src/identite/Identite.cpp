#include "../../include/identite/Identite.h"
#include <sstream>

namespace BTTP
{
    namespace Protocole
    {

        void Identite::genererClePrivee(std::string nom, std::string email, std::string mdp)
        {
            Cle::Config config{ nom, email, mdp };
            this->_cle_privee = Cle::Privee::generer(config);
        }

        std::string Identite::exporterClePrivee(const bool armor) const
        {
            std::ostringstream cle_privee;
            cle_privee << this->_cle_privee.write((armor ? OpenPGP::PGP::Armored::YES : OpenPGP::PGP::Armored::NO)) << std::flush;

            return cle_privee.str();
        }

        void Identite::importerClePrivee(const std::string cle_privee)
        {
            
            this->_cle_privee = Cle::Privee(_cle_privee);

        }

        Identite::Identite(const std::string nom, const std::string email, const std::string mdp)
        {
            this->genererClePrivee(nom, email, mdp);
        }

        Identite::Identite(const std::string cle_privee) 
        {
            this->importerClePrivee(cle_privee);
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

        const std::string Identite::chiffrer(const std::string message, const Cle::Publique destinataire, const std::string mdp) const
        {
            // Configuration du chiffrement
            Cle::Privee::Ptr signataire = std::make_shared<Cle::Privee>(_cle_privee);
            if (!signataire->meaningful()) throw Erreur::Identite::Chiffrement("La clé privée est incohérente.", message);
            const OpenPGP::Encrypt::Args args("", message, Cle::Config::SYM, Cle::Config::COMP, true, signataire, mdp, Cle::Config::HASH);
            if (!args.valid()) throw Erreur::Identite::Chiffrement("Les arguments de chiffrement sont invalides.", message);
            // Chiffrement et signature du message
            OpenPGP::Message message_chiffre;
            try { message_chiffre = OpenPGP::Encrypt::pka(args, destinataire); }
            catch (std::exception& e) { throw Erreur::Identite::Chiffrement(e.what(), message); }
            if (!message_chiffre.meaningful()) throw Erreur::Identite::Chiffrement("L'intégrité du message n'a pu être vérifiée.", message);
            // Retour au format brut
            return message_chiffre.raw();
        }

        const std::string Identite::dechiffrer(const std::string message, const Cle::Publique emissaire, const std::string mdp) const
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