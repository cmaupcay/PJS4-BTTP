#include "Identite.h"

OpenPGP::SecretKey BTTP::Protocole::Idendite::genererCles(std::string nom, std::string email){
    
    OpenPGP::KeyGen::Config config;
    
    config.passphrase = "";
    config.pka        = OpenPGP::PKA::NUMBER.at("RSA_ENCRYPT_OR_SIGN");
    config.bits       = 4096;
    config.sym        = OpenPGP::Sym::NUMBER.at("AES256");
    config.hash       = OpenPGP::Hash::NUMBER.at("SHA1");


    OpenPGP::KeyGen::Config::UserID uid;
    uid.user          = nom;
    uid.comment       = "";
    uid.email         = email;
    uid.sig           = OpenPGP::Hash::NUMBER.at("SHA1");
    config.uids.push_back(uid);


    OpenPGP::KeyGen::Config::SubkeyGen subkey;
    subkey.pka        = OpenPGP::PKA::NUMBER.at("RSA_ENCRYPT_OR_SIGN");
    subkey.bits       = 4096;
    subkey.sym        = OpenPGP::Sym::NUMBER.at("AES256");
    subkey.hash       = OpenPGP::Hash::NUMBER.at("SHA1");
    subkey.sig        = OpenPGP::Hash::NUMBER.at("SHA1");
    
    config.subkeys.push_back(subkey);

    const OpenPGP::SecretKey privee = OpenPGP::KeyGen::generate_key(config);

    return privee;


}




BTTP::Protocole::Idendite::Idendite() {

    OpenPGP::SecretKey privee;

    std::ifstream pri_in("private_key", std::ios::binary);

    if(!pri_in){

        privee = genererCles("test", "test@test.com");

        const std::string fichier_privee = "cle_privee.asc";

        std::ofstream pri_out(fichier_privee, std::ios::binary);
        
        assert(pri_out);

        pri_out << privee.write(OpenPGP::PGP::Armored::YES) << std::flush;


    }
    else {

        privee = OpenPGP::SecretKey(pri_in);

    }

    _cle_publique = privee.get_public();
    _cle_privee = privee;
        
}

OpenPGP::Message BTTP::Protocole::Idendite::chiffrer(std::string message, OpenPGP::PublicKey pub){

    OpenPGP::SecretKey::Ptr signataire = std::make_shared <OpenPGP::SecretKey>(_cle_privee);

    const OpenPGP::Encrypt::Args args("", 
                                        message,
                                        OpenPGP::Sym::NUMBER.at("AES256"),
                                        OpenPGP::Compression::NUMBER.at("ZLIB"),
                                        true,
                                        signataire,
                                        "",
                                        OpenPGP::Hash::NUMBER.at("SHA1")
    );


    const OpenPGP::Message message_chiffre = OpenPGP::Encrypt::pka(args, pub);

    assert (message_chiffre.meaningful());

    return message_chiffre;

}

std::string BTTP::Protocole::Idendite::dechiffer(OpenPGP::Message message_chiffre, OpenPGP::PublicKey pub){

   const OpenPGP::Message message_dechiffre = OpenPGP::Decrypt::pka(_cle_privee, "", message_chiffre);

    if(!message_dechiffre.meaningful())
        return "";

    OpenPGP::Key::Ptr signataire = std::make_shared <OpenPGP::Key> (pub);

    const int verifie = OpenPGP::Verify::binary(*signataire, message_dechiffre);

    assert(verifie);

    std::string message = "";

    for(OpenPGP::Packet::Tag::Ptr const & p : message_dechiffre.get_packets()){

        switch(p -> get_tag()){

            case OpenPGP::Packet::LITERAL_DATA:
                message += std::static_pointer_cast <OpenPGP::Packet::Tag11> (p) -> out(false);
                break;
            default:
                continue;

        }

        message += "\n";


    }

    return message;



}

OpenPGP::PublicKey BTTP::Protocole::Idendite::cle_publique() {

    return _cle_publique;

}