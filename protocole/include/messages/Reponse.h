#ifndef H_BTTP_MESSAGE_REPONSE
#define H_BTTP_MESSAGE_REPONSE

#include "Message.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            class Reponse : public Message
            {
            private:
                /**
                 * @brief Champs demandé dans le message DEMANDE original.
                 * @details Le client peut ainsi vérifier à quelle demande répond ce message.
                 */
                std::string _champs;

                /**
                 * @brief Données sérialisées relatives au champs demandé.
                 */
                std::string _data;

                /**
                 * @brief Retourne le contenu du message.
                 * @return const std::string Nom du champs demandé et données associées.
                 */
                const std::string contenu() const override;

                /**
                 * @brief Enregistrement du contenu d'un message similaire.
                 * @param contenu Nom du champs demandé et données associées.
                 */
                void deconstruction(const std::string contenu) override;

            public:
                /**
                 * @brief Construction du message à partir du nom du champs et des données associées.
                 * @param champs Champs demandé dans la demande à laquelle répond ce message.
                 * @param data Données sérialisées associées au champs demandé.
                 */
                Reponse(const std::string champs, const std::string data);
                /**
                 * @brief Construction d'un message vide.
                 */
                Reponse();
                /**
                 * @brief Construction d'un message vide, déconstruction d'un paquet et enregistrement du champs et des données contenus.
                 * @param paquet Paquet à déconstruire.
                 */
                Reponse(const std::string paquet);

                /**
                 * @brief Retourne le champs demandé dans la demande originale.
                 * @return const std::string& Nom du champs demandé.
                 */
                inline const std::string& champs() const { return this->_champs; }
                /**
                 * @brief Retourne les données sérialisées issues du champs demandé.
                 * @return const std::string& Données demandées.
                 */
                inline const std::string& data() const { return this->_data; }
            };
        }
    }
}

#endif