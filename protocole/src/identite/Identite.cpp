#include "../../include/identite/Identite.h"
#include <sstream>

namespace BTTP
{
    namespace Protocole
    {
        
        void Identite::generer(std::string nom, std::string email, std::string mdp)
        {
            Cle::Config config{ nom, email, mdp };
            this->_cle_privee = Cle::Privee::generer(config);
        }

        std::string Identite::exporter(const bool armor) const
        { 
            try { return this->_cle_privee.write((armor ? OpenPGP::PGP::Armored::YES : OpenPGP::PGP::Armored::NO)); }
            catch (std::exception& err) { throw Erreur::Identite::Exportation(err.what()); }
        }

        void Identite::importer(const std::string cle_privee)
        { 
            try { this->_cle_privee = Cle::Privee(cle_privee); }
            catch (std::exception& err) { throw Erreur::Identite::Importation(err.what()); }
        }
        void Identite::importer(std::istream& cle_privee)
        {
            try { this->_cle_privee = Cle::Privee(cle_privee); }
            catch (std::exception& err) { throw Erreur::Identite::Importation(err.what()); }
        }

        Identite::Identite(const std::string nom, const std::string email, const std::string mdp)
        { this->generer(nom, email, mdp); }

        Identite::Identite(const std::string cle_privee) 
        { this->importer(cle_privee); }
        Identite::Identite(std::istream& cle_privee) 
        { this->importer(cle_privee); }

        // TOCOMMENT Retrouver l'exemple original.
        const std::string Identite::traduire_message(const OpenPGP::Message message_pgp)
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

        const OpenPGP::Message Identite::dechiffrement(const std::string message, const std::string mdp) const
        {
            OpenPGP::Message message_dechiffre;
            try { message_dechiffre = OpenPGP::Decrypt::pka(this->_cle_privee, mdp, message); }
            catch (std::exception& err) { throw Erreur::Identite::Dechiffrement(err.what(), message); }
            if (!message_dechiffre.meaningful()) throw Erreur::Identite::Dechiffrement("L'intégrité du message n'a pu être vérifiée.", message);
            return message_dechiffre;
        }

        const bool Identite::verification_signature(const OpenPGP::Message& message_dechiffre, const Cle::Publique& emissaire)
        {
            OpenPGP::Key::Ptr signataire = std::make_shared<OpenPGP::Key>(emissaire);
            if (!signataire->meaningful()) throw Erreur::Identite::Dechiffrement("La clé publique est incohérente.", "non affichable.");
            return OpenPGP::Verify::binary(*signataire, message_dechiffre);
        }

        const std::string Identite::dechiffrer(const std::string message, const Cle::Publique emissaire, const std::string mdp) const
        {
            // Déchiffrement du message
            OpenPGP::Message message_dechiffre = this->dechiffrement(message, mdp);
            // Vérification de la signature
            if (verification_signature(message_dechiffre, emissaire))
                // Traduction en chaine de caractère (voir Identite::traduire_message)
                return traduire_message(message_dechiffre);
            throw Erreur::Identite::Dechiffrement("La vérification de la signature a échoué.", message);
        }

        Identite::MessageNonVerifie::MessageNonVerifie(const std::string message, const Identite& identite, const std::string mdp)
        {
            const OpenPGP::Message msg = identite.dechiffrement(message, mdp);
            this->_complet = msg.write();
            this->_clair = Identite::traduire_message(msg);
        }
    }
}