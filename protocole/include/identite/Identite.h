#ifndef H_BTTP_IDENTITE
#define H_BTTP_IDENTITE

#include "Cles.h"

#ifndef BTTP_IDENTITE_CHEMIN_DEFAUT
    #define BTTP_IDENTITE_CHEMIN_DEFAUT BTTP_DOSSIER "/id"
#endif
#ifndef BTTP_IDENTITE_CHEMIN_BTTP_DEFAUT
    #define BTTP_IDENTITE_CHEMIN_BTTP_DEFAUT true
#endif
#ifndef BTTP_IDENTITE_CHEMIN_CREER
    #define BTTP_IDENTITE_CHEMIN_CREER true
#endif
#ifndef BTTP_IDENTITE_ARMOR
    #define BTTP_IDENTITE_ARMOR false
#endif
#ifndef BTTP_IDENTITE_EXT
    #define BTTP_IDENTITE_EXT "asc"
#endif

#include <fstream>
#include <filesystem>
#include <iostream>

#include "erreur/Chiffrement.h"
#include "erreur/Dechiffrement.h"
#include "erreur/Importation.h"
#include "erreur/Exportation.h"
#include "erreur/Doublon.h"

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
                static const std::string traduireMessage(const OpenPGP::Message message_pgp);

            protected:
                void genererClePrivee(const std::string nom, const std::string contact, const std::string mdp);
                // TODO Le protocole doit-il s'occuper des fichiers ?
                void exporterClePrivee(
                    const std::string nom, const bool armor = BTTP_IDENTITE_ARMOR,
                    const std::string chemin = BTTP_IDENTITE_CHEMIN_DEFAUT, const bool creer_chemin = BTTP_IDENTITE_CHEMIN_CREER,
                    const bool dossier_contexte = BTTP_IDENTITE_CHEMIN_BTTP_DEFAUT
                ) const;
                void importerClePrivee(
                    const std::string nom, const std::string chemin = BTTP_IDENTITE_CHEMIN_DEFAUT,
                    const bool dossier_contexte = BTTP_IDENTITE_CHEMIN_BTTP_DEFAUT
                );

                static inline const std::string fichier(
                    const std::string nom, const std::string chemin, const bool dossier_contexte
                );
            
            public:
                Identite(
                    const std::string nom, const std::string chemin = BTTP_IDENTITE_CHEMIN_DEFAUT,
                    const bool dossier_contexte = BTTP_IDENTITE_CHEMIN_BTTP_DEFAUT
                );
                Identite(
                    const std::string nom, const std::string contact, const std::string mdp,
                    const std::string chemin = BTTP_IDENTITE_CHEMIN_DEFAUT,
                    const bool dossier_contexte = BTTP_IDENTITE_CHEMIN_BTTP_DEFAUT
                );
                
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