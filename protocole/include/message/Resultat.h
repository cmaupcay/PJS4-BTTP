#ifndef H_BTTP_MESSAGE_RESULTAT
#define H_BTTP_MESSAGE_RESULTAT

#include "Message.h"
#include "erreur/deconstruction/Incomplet.h"


namespace BTTP 
{
    namespace Protocole 
    {
        namespace Messages 
        {
            class Resultat : public Message
            {
            private :

                /**
                 * @brief Idenifiant numérique d'exécution.
                 * @details Il doit être identique à l'identifiant du message d'exécution auquel répond ce message.
                 */
                uint32_t* _id;

                /**
                 * @brief Contenu du résultat.
                 */
                std::string _resultat;

                /**
                 * @brief Retourne à la fois le message en lui même et l'id, l'objet sous forme de string.
                 * @return const std::string Contenu sérialisé du message.
                 */
                const std::string contenu() const override;

                /**
                 * @brief Déconstruction du contenu d'un paquet et enregistrement des informations extraites.
                 * @param contenu Contenu extrait d'un paquet de type RESULTAT.
                 */
                void deconstruction(std::string contenu) override;
            
            public : 
                /**
                 * @brief Construction d'un nouveau message à partir de l'identifiant du message d'exécution auquel répond ce message. 
                 * @param id Identifiant numérique d'exécution.
                 * @param data Données à ajouter au message.
                 */
                Resultat(const uint32_t id, const std::string data = "");
                /**
                 * @brief Construction d'un message vide.
                 * @details L'identifiant numérique n'est pas généré.
                 */
                Resultat();
                /**
                 * @brief Construction d'un message vide, déconstruction d'un paquet et enregistrement des informations extraites.
                 * @param paquet Paquet à déconstruire.
                 */
                Resultat(const std::string paquet);
            
                /**
                 * @brief Retourne l'identifiant numérique d'exécution associé au message.
                 * @return const uint32_t& Identifiant d'exécution.
                 */
                inline const uint32_t& id() const { return *this->_id; }

                /**
                 * @brief Retourne le contenu du résultat.
                 * @return const std::string& Résultat d'exécution d'un script.
                 */
                inline const std::string& resultat() const { return this->_resultat; }
                inline void ajouter_donnees(const std::string data) { this->_resultat += data; }
            };
        } 
    }
}

#endif