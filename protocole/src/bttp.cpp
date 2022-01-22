#include <iostream>
#include "OpenPGP.h"
#include <fstream>

// Pour build les cocos : g++ -Wall -g -std=c++11 bttp.cpp -o bttp -L'CHEMIN BUILD OPENPGP' -lOpenPGP

int generate_key(std::string user, std::string email);
OpenPGP::Message encrypt (std::string message, OpenPGP::PublicKey public_key);
std::string decrypt(OpenPGP::Message encrypted, OpenPGP::SecretKey private_key);

int main() {

    generate_key("test", "test@test.com");

    std::ifstream pub_in("public_key", std::ios::binary);
    if(!pub_in)
        return -1;

    std::ifstream pri_in("private_key", std::ios::binary);
    if(!pri_in)
        return -1;


    OpenPGP::PublicKey pub = OpenPGP::PublicKey(pub_in);
    OpenPGP::SecretKey pri = OpenPGP::SecretKey(pri_in);

    std::cout << "Entrez un message à chiffrer : ";
    std::string message;

    char buffer[100];

    std::cin.getline(buffer, 100);

    message = (std::string) buffer;

    OpenPGP::Message encrypted = encrypt(message, pub);

    std::cout << "Message chiffré : \n" << encrypted.write(OpenPGP::PGP::Armored::YES) << std::endl;

    std::cout << "Déchiffrer ?";

    std::cin.get();


    std::cout << "Message déchiffré : " << decrypt(encrypted, pri);


    
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

OpenPGP::Message encrypt (std::string message, OpenPGP::PublicKey pub_key){

    const OpenPGP::Encrypt::Args encryptargs("", 
                                        message,
                                        OpenPGP::Sym::NUMBER.at("AES256"),
                                        OpenPGP::Compression::NUMBER.at("ZLIB"),
                                        true,
                                        nullptr,
                                        "",
                                        OpenPGP::Hash::NUMBER.at("SHA1")
    );


    const OpenPGP::Message encrypted = OpenPGP::Encrypt::pka(encryptargs, pub_key);

    /*

    if(!encrypted.meaningful())
        return -1;

    */

    return encrypted;

}

std::string decrypt(OpenPGP::Message encrypted, OpenPGP::SecretKey pri_key){

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

    return message;


}