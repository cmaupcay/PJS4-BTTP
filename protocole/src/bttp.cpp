#include <iostream>
#include "OpenPGP.h"
#include <fstream>
#include <assert.h>

// Pour build les cocos : g++ bttp.cpp -o bttp -lOpenPGP 

int generate_key(std::string user, std::string email);
OpenPGP::Message encrypt_and_sign (std::string message, OpenPGP::PublicKey public_key, OpenPGP::SecretKey private_key);
std::string decrypt_and_verify(OpenPGP::Message encrypted, OpenPGP::SecretKey private_key, OpenPGP::PublicKey public_key);
bool verify(OpenPGP::Message decrypted, OpenPGP::PublicKey public_key);

int main() {

    generate_key("test", "test@test.com");

    std::ifstream pri_in("private_key", std::ios::binary);

    if(!pri_in)
        return -1;

    OpenPGP::SecretKey pri = OpenPGP::SecretKey(pri_in);
    OpenPGP::PublicKey pub = pri.get_public();

    
    std::cout << "Entrez un message à chiffrer : ";
    std::string message;

    char buffer[100];

    std::cin.getline(buffer, 100);

    message = (std::string) buffer;

    OpenPGP::Message encrypted = encrypt_and_sign(message, pub, pri);

    std::cout << "Message chiffré et signé : \n" << encrypted.write(OpenPGP::PGP::Armored::YES) << std::endl;

    std::cout << "Déchiffrer ?";

    std::cin.get();

    std::cout << "Message déchiffré : " << decrypt_and_verify(encrypted, pri, pub);

    
}

int generate_key(std::string user, std::string email){

        OpenPGP::KeyGen::Config config;
        
        config.passphrase = "";
        config.pka        = OpenPGP::PKA::NUMBER.at("RSA_ENCRYPT_OR_SIGN");
        config.bits       = 2048;
        config.sym        = OpenPGP::Sym::NUMBER.at("AES256");
        config.hash       = OpenPGP::Hash::NUMBER.at("SHA1");


        OpenPGP::KeyGen::Config::UserID uid;
        uid.user          = user;
        uid.comment       = "";
        uid.email         = email;
        uid.sig           = OpenPGP::Hash::NUMBER.at("SHA1");
        config.uids.push_back(uid);


        OpenPGP::KeyGen::Config::SubkeyGen subkey;
        subkey.pka        = OpenPGP::PKA::NUMBER.at("RSA_ENCRYPT_OR_SIGN");
        subkey.bits       = 2048;
        subkey.sym        = OpenPGP::Sym::NUMBER.at("AES256");
        subkey.hash       = OpenPGP::Hash::NUMBER.at("SHA1");
        subkey.sig        = OpenPGP::Hash::NUMBER.at("SHA1");
        
        config.subkeys.push_back(subkey);

        const OpenPGP::SecretKey pri = OpenPGP::KeyGen::generate_key(config);

        const OpenPGP::PublicKey pub = pri.get_public();

        const std::string pub_name = "public_key";
        const std::string pri_name = "private_key";

        std::ofstream pub_out(pub_name, std::ios::binary);
        if(!pub_out)
            return -1;

        std::ofstream pri_out(pri_name, std::ios::binary);
        if(!pri_out)
            return -2;

        pub_out << pub.write(OpenPGP::PGP::Armored::YES) << std::flush;
        pri_out << pri.write(OpenPGP::PGP::Armored::YES) << std::flush;

        return 0;

}

OpenPGP::Message encrypt_and_sign (std::string message, OpenPGP::PublicKey pub_key, OpenPGP::SecretKey pri_key){

    OpenPGP::SecretKey::Ptr signer = std::make_shared <OpenPGP::SecretKey>(pri_key);

    const OpenPGP::Encrypt::Args encryptargs("", 
                                        message,
                                        OpenPGP::Sym::NUMBER.at("AES256"),
                                        OpenPGP::Compression::NUMBER.at("ZLIB"),
                                        true,
                                        signer,
                                        "",
                                        OpenPGP::Hash::NUMBER.at("SHA1")
    );


    const OpenPGP::Message encrypted = OpenPGP::Encrypt::pka(encryptargs, pub_key);

    assert (encrypted.meaningful());

    return encrypted;

}

bool verify(OpenPGP::Message decrypted, OpenPGP::PublicKey pub_key){

    OpenPGP::Key::Ptr signer = std::make_shared <OpenPGP::Key> (pub_key);

    const int verified = OpenPGP::Verify::binary(*signer, decrypted);

    return verified;

}


std::string decrypt_and_verify(OpenPGP::Message encrypted, OpenPGP::SecretKey pri_key, OpenPGP::PublicKey pub_key){

    const OpenPGP::Message decrypted = OpenPGP::Decrypt::pka(pri_key, "", encrypted);

    if(!decrypted.meaningful())
        return "";

    std::string message = "";

    for(OpenPGP::Packet::Tag::Ptr const & p : decrypted.get_packets()){

        switch(p -> get_tag()){

            case OpenPGP::Packet::LITERAL_DATA:
                message += std::static_pointer_cast <OpenPGP::Packet::Tag11> (p) -> out(false);
                break;
            default:
                continue;

        }

        message += "\n";


    }
  

    message += "\n" + std::string((verify(decrypted, pub_key) == 1) ? "Signature vérifiée !" : "Signature invalide !") + "\n";

    return message;


}
