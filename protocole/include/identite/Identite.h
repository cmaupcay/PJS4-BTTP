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

                /**
                 * @brief Vérification de la signature d'un message déchiffré.
                 * @param message_dechiffre Message OpenPGP précédemment déchiffré.
                 * @param emissaire Emissaire du message.
                 * @return true La signature est valide.
                 * @return false La signature n'a pu être vérifié.
                 */
                static const bool verification_signature(const OpenPGP::Message& message_dechiffre, const Cle::Publique& emissaire);

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
                // TOFIX Obliger le nom a ne pas être une chaîne vide.
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

                class MessageNonVerifie
                {
                private:
                    /** Message déchiffré et traduit en chaîne claire. */
                    std::string _clair;
                    /** Message déchiffré et signature associée. */
                    std::string _complet;
                
                public:
                    /**
                     * @brief Construction d'un nouveau message non vérifié.
                     * @param message Message chiffré.
                     * @param identite Identité du destinataire du message.
                     * @param mdp Mot de passe de l'identité du destinataire.
                     */
                    MessageNonVerifie(const std::string message, const Identite& identite, const std::string mdp);

                    inline const bool verifier(const Cle::Publique emissaire) const
                    { return verification_signature(OpenPGP::Message(this->_complet), emissaire); }

                    /**
                     * @brief Retourne le message déchiffré sous sa forme claire.
                     * @return const std::string& Message en clair.
                     */
                    inline const std::string& clair() const { return this->_clair; }
                };

                /**
                 * @brief Ecrit la clé publique relative à l'identité dans le flux de sortie.
                 * @param os Flux de sortie.
                 * @param id Identité cible.
                 * @return std::ostream& Flux de sortie mis à jour.
                 */
                inline friend std::ostream& operator<<(std::ostream& os, const Identite& id)
                { return (os << id.cle_publique().exporter(BTTP_IDENTITE_ARMOR)); }
        };
    }
}
#endif