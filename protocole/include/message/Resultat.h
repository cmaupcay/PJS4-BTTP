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
                 * @brief Idenifiant numérique de la réponse
                 * @details IL doit être identique à l'id d'exéution
                 */
                uint32_t* _id;

                /**
                 * @brief Message contenu dans le résultat
                 */
                std::string _resultat;

                /**
                 * @brief Retourne à la fois le message en lui même et l'id, l'objet sous forme de string
                 * @return const std::string 
                 */
                const std::string contenu() const override;

                /**
                 * @brief 
                 * @param contenu 
                 */
                void deconstruction(std::string contenu) override;
            
            public : 
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
                 * @brief Retourne l'identifiant numérique du message.
                 * @return const uint32_t& Identifiant du message.
                 */
                inline const uint32_t& id() const { return *this->_id; }

                //TOCOMMENT RETURN
                /**
                 * @brief Retourne le contenu du message
                 * @return const std::string& 
                 */
                inline const std::string& resultat() const { return this->_resultat; }
            };

        } 
    }


}

#endif