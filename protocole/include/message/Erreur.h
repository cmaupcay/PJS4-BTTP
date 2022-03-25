#ifndef H_BTTP_MESSAGE_ERREUR
#define H_BTTP_MESSAGE_ERREUR

#include "Message.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            class Erreur : public Message
            {
            private :
                /**
                 * @brief Nom de l'erreur.
                 */
                std::string _nom;

                /**
                 * @brief Message associé à l'erreur.
                 */
                std::string _message;

                /**
                 * @brief Code numérique associé à l'erreur.
                 */
                int* _code;

                /**
                 * @brief Retourne le contenu du message.
                 * @return const std::string Contenu sérialisé du message (code, nom et message d'erreur).
                 */
                const std::string contenu() const override;

                /**
                 * @brief Déconstruction du contenu d'un paquet et enregistrement des informations extraites.
                 * @param contenu Contenu extrait d'un paquet de type ERREUR.
                 */
                void deconstruction(std::string contenu) override;
            
            public : 
                /**
                 * @brief Construction d'un nouveau message à partir de l'identifiant du message d'exécution auquel répond ce message. 
                 * @param erreur Erreur à sérialiser.
                 */
                Erreur(const BTTP::Erreur* erreur);
                /**
                 * @brief Construction d'un message vide.
                 */
                Erreur();
                /**
                 * @brief Construction d'un message vide, déconstruction d'un paquet et enregistrement des informations extraites.
                 * @param paquet Paquet à déconstruire.
                 */
                Erreur(const std::string paquet);
            
                /**
                 * @brief Retourne le nom de l'erreur.
                 * @return const std::string& Nom de l'erreur associée au message.
                 */
                inline const std::string& nom() const { return this->_nom; }

                /**
                 * @brief Retourne le message associé à l'erreur.
                 * @return const std::string& Message associé à l'erreur.
                 */
                inline const std::string& message() const { return this->_message; }

                /**
                 * @brief Retourne le code numérique de l'erreur.
                 * @return const int& Code numérique associé à l'erreur.
                 */
                inline const int& code() const { return *this->_code; }
            };
        }
    }
}

#endif