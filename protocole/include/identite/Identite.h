#ifndef H_BTTP_IDENTITE
#define H_BTTP_IDENTITE

#include "Cles.h"

#include <fstream>
#include <filesystem>
#include <iostream>

#include "erreur/Chiffrement.h"
#include "erreur/Dechiffrement.h"
#include "erreur/Importation.h"
#include "erreur/Exportation.h"

namespace BTTP 
{
    namespace Protocole 
    {
        /**
         * @brief Représentation d'un appareil et de ses clés privé et publique.
         * Elle est capable de chiffrer, signer, déchiffrer et vérifier des messages.
         * @details Cette implémentation est basée sur la bibliothèque OpenPGP de calccrypto.
         * Repos : https://github.com/calccrypto/OpenPGP
         */
        class Identite 
        {
            private:
                /**
                 * @brief Clé privée relative à l'identité.
                 */
                Cle::Privee _cle_privee;

                /**
                 * @brief Conversion d'un OpenPGP::Message en chaîne de caractère.
                 * @param message_pgp Message de la bibliothèque calccrypto/OpenPGP.
                 * @return const std::string Message reconstruit.
                 */
                static const std::string traduire_message(const OpenPGP::Message message_pgp);

                /**
                 * @brief Déchiffrement d'une chaîne de caractère.
                 * @param message Message chiffré.
                 * @param mdp Mot de passe de la clé privée.
                 * @return const OpenPGP::Message 
                 */
                const OpenPGP::Message dechiffrement(const std::string message, const std::string mdp) const;

            protected:
                /**
                 * @brief Génération d'une nouvelle identité (clé privée).
                 * @warning L'identité précédente est effacée.
                 * @param nom Nom du propriétaire de la clé.
                 * @param contact Contact identifiant le propriétaire.
                 * @param mdp Mot de passe de la clé privée.
                 */
                void generer(const std::string nom, const std::string contact, const std::string mdp);
                
                /**
                 * @brief Importation d'une nouvelle identité (clé privée).
                 * @warning L'identité précédente est effacée.
                 * @param cle_privee Clé privée.
                 */
                void importer(const std::string cle_privee);
                /**
                 * @brief Importation d'une nouvelle identité (clé privée) à partir d'un flux.
                 * @warning L'identité précédente est effacée.
                 * @param cle_privee Flux de la clé privée.
                 */
                void importer(std::istream& cle_privee);
            
            public:
                /**
                 * @brief Construction d'une nouvelle identité et importation d'une clé privée.
                 * @see BTTP::Protocole::Identite::importer()
                 * @param cle_privee Clé privée à importer.
                 */
                Identite(const std::string cle_privee);
                /**
                 * @brief Construction d'une nouvelle identité et importation d'une clé privée depuis un flux.
                 * @see BTTP::Protocole::Identite::importer()
                 * @param cle_privee Flux de la clé privée à importer.
                 */
                Identite(std::istream& cle_privee);
                /**
                 * @brief Construction et génération d'une nouvelle identité.
                 * @see BTTP::Protocole::Identite::generer()
                 * @param nom Nom du propriétaire de la clé à générer.
                 * @param contact Contact identifiant le propriétaire.
                 * @param mdp Mot de passe de la clé privée à générer.
                 */
                Identite(const std::string nom, const std::string contact, const std::string mdp);

                /**
                 * @brief Exportation de la clé privée relative à l'identité.
                 * @param armor Mode structuré.
                 * @return std::string Clé privée.
                 */
                std::string exporter(const bool armor = BTTP_IDENTITE_ARMOR) const;
                
                /**
                 * @brief Retourne la clé publique de l'identité.
                 * @return const Cle::Publique Clé publique associée à l'identité.
                 */
                inline const Cle::Publique cle_publique() const { return Cle::Publique(this->_cle_privee.get_public()); }

                /**
                 * @brief Chiffrement et signature d'une chaîne de caractère à destination d'une identité.
                 * @param message Message à chiffrer.
                 * @param destinataire Clé publique relative à l'identité du destinataire.
                 * @param mdp Mot de passe de la clé privée du signataire du message.
                 * @return const std::string Chaîne de caractère chiffrée et signée.
                 */
                const std::string chiffrer(const std::string message, const Cle::Publique destinataire, const std::string mdp) const;
                /**
                 * @brief Déchiffrement et vérification de la signature d'une chaîne de caractère chiffrée et signée a destination de l'identité.
                 * @param message Message chiffré et signé par l'émissaire.
                 * @param emissaire Signataire du message.
                 * @param mdp Mot de passe de la clé privée du destinataire.
                 * @return const std::string Chaîne de caractère déchiffrée.
                 */
                const std::string dechiffrer(const std::string message, const Cle::Publique emissaire, const std::string mdp) const;

                /**
                 * @brief Déchiffrement sans vérification de la signature d'une chaîne de caractère chiffrée a destination de l'identité.
                 * @warning L'usage de cette fonction doit être strictement limité aux situations dans lesquelles l'idenité de l'emissaire
                 * du message n'est pas connue du destinataire (ex: ouverture d'une transaction).
                 * @param message Message chiffré.
                 * @param mdp Mot de passe de la clé privée du destinataire.
                 * @return const std::string Chaîne de caractère déchiffrée.
                 */
                inline const std::string dechiffrer_sans_verifier(const std::string message, const std::string mdp) const
                { return traduire_message(this->dechiffrement(message, mdp)); }

                /**
                 * @brief Ecrit la clé publique relative à l'identité dans le flux de sortie.
                 * @param os Flux de sortie.
                 * @param id Identité cible.
                 * @return std::ostream& Flux de sortie mis à jour.
                 */
                inline friend std::ostream& operator<<(std::ostream& os, const Identite& id)
                { return (os << id.cle_publique().write()); }
        };
    }
}
#endif