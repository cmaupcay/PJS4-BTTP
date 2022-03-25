#ifndef H_BTTP_MESSAGE_DEMANDE
#define H_BTTP_MESSAGE_DEMANDE

#include "Message.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            class Demande : public Message
            {
            private:
                /**
                 * @brief Champs à demander.
                 */
                std::string _champs;
                /**
                 * @brief Arguments d'exécution à ajouter au script, sous forme de paire nom/valeur.
                 */
                std::vector<Argument> _args;

                /**
                 * @brief Retourne le contenu du message.
                 * @return const std::string Champs à demander.
                 */
                const std::string contenu() const override;

                /**
                 * @brief Enregistrement du contenu d'un message similaire.
                 * @param contenu Caractère correspondant au champs à demander.
                 */
                void deconstruction(const std::string contenu) override;

            public:
                /**
                 * @brief Construction du message à partir d'un champs.
                 * @param champs Champs à demander.
                 */
                Demande(const std::string champs, const std::vector<Argument> args);
                /**
                 * @brief Construction d'un message vide.
                 */
                Demande();
                /**
                 * @brief Construction d'un message vide, déconstruction d'un paquet et enregistrement du champs demandé.
                 * @param paquet Paquet à déconstruire.
                 */
                Demande(const std::string paquet);

                /**
                 * @brief Retourne le champs demandé.
                 * @return const std::string& Champs demandé.
                 */
                inline const std::string& champs() const { return this->_champs; }
                /**
                 * @brief Retourne les arguments ajoutés à la demande.
                 * @return const std::vector<Argument>& Arguments.
                 */
                inline const std::vector<Argument>& args() const { return this->_args; }

                /**
                 * @brief Ajoute un argument dans la demande.
                 * @param nom Nom de l'argument à ajouter.
                 * @param valeur Valeur de l'argument.
                 */
                inline void ajouter_argument(const std::string nom, const std::string valeur) 
                { this->_args.push_back(Argument(nom, valeur)); }
                /**
                 * @brief Supprime le dernier éléments ajouter.
                 */
                inline void supprimer_dernier_argument() { this->_args.pop_back(); }
            };
        }
    }
}

#endif