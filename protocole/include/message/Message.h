#ifndef H_BTTP_MESSAGE
#define H_BTTP_MESSAGE

#include "../Racine.h"

#include <iomanip>
#include <vector>

#include "erreur/deconstruction/Incomplet.h"
#include "erreur/type/Incoherent.h"

#ifndef BTTP_MESSAGE_SEP
    #define BTTP_MESSAGE_SEP '|'
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            /**
             * @brief Interface des messages du protocole.
             * 
             */
            class IMessage
            {
            public:
                /**
                 * @brief Construction d'un message vide.
                 */
                IMessage() {}
                /**
                 * @brief Construction d'un message depuis un paquet.
                 * 
                 * @param paquet Paquet à déconstruire.
                 */
                IMessage(const std::string paquet) {}

                /**
                 * @brief Construction d'un paquet à partir des informations du message.
                 * 
                 * @return const std::string Paquet construit.
                 */
                virtual const std::string construire() const = 0;
                /**
                 * @brief Déconstruction d'un paquet et enregistrement des informations extraites.
                 * 
                 * @param paquet Paquet à déconstruire.
                 * 
                 * @throws Erreur::Deconstruction::Impossibe Le paquet ne peut pas être interprété.
                 */
                virtual void deconstruire(const std::string paquet) = 0;
                /**
                 * @brief Type du message pouvant être sérialiser.
                 * 
                 * @return const char Type du message.
                 */
                virtual const char type_c() const = 0;

                inline friend std::ostream& operator<<(std::ostream& os, const IMessage& msg) { return (os << msg.construire()); }
            };

            /**
             * @brief Classe de base des messages manipulés par le protocole.
             * 
             * @tparam _Type Classe de type des messages.
             */
            // TOCOMMENT (attributs et méthodes)
            template <class _Type>
            class TMessage : public IMessage
            {
            private:
                const _Type _type;
            protected:
                TMessage(const _Type type) : _type{ type } {}
                TMessage(const _Type type, const std::string paquet)
                    : IMessage(paquet), _type{ type }
                {}

                virtual const std::string contenu() const = 0;
                virtual void construction(const std::string contenu) = 0;

            public:
                inline const _Type& type() const { return this->_type; }
                inline const char type_c() const override { return static_cast<char>(this->_type); }

                inline const std::string construire() const override
                { return this->type_c() + this->contenu(); }
                void deconstruire(const std::string paquet) override
                {
                    if (paquet.length() > 0 && paquet[0] == this->type_c())
                        this->construction(paquet.substr(1));
                    else throw Erreur::Messages::Type::Incoherent(this->type_c(), paquet);
                }
            };

            /**
             * @brief Classe des types de messages BTTP.
             */
            enum class Type
            {
                /**
                 * @brief Annoncement d'une clé publique.
                 * @see ./ClePublique.h
                 */
                CLE_PUBLIQUE = '!',
                /**
                 * @brief Demande d'exécution d'un script.
                 * @see ./Execution.h
                 */
                EXECUTION = '>',
                /**
                 * @brief Résultat(s) d'exécution d'un script.
                 * @pre EXECUTION
                 */
                // TODO Classe du type de message Resultat
                RESULTAT = '<',
                /**
                 * @brief Ouverture d'une transaction.
                 */
                // TODO Classe du type de message Ouverture
                OUVERTURE = '*',
                /**
                 * @brief Fermeture d'une transaction.
                 */
                // TODO Classe du type de message Fermeture
                FERMETURE = '/'
                // TODO Réfléchir aux types manquants
            };

            /**
             * @brief Classe de base des messages BTTP.
             */
            class Message : public TMessage<Type>
            {
            protected:
                Message(const Type type) : TMessage(type) {}
                Message(const Type type, const std::string paquet)
                    : TMessage(type, paquet)
                {}
            };

            // TOTEST
            // TOCOMMENT
            const std::vector<std::string> decouper(const std::string contenu, const std::string pattern);
            inline const std::vector<std::string> decouper(const std::string contenu, const char pattern)
            { return decouper(contenu, std::string(1, pattern)); }

            // TOTEST
            // TOCOMMENT
            const std::string joindre(const std::vector<std::string>& vecteur, const std::string jointure);
            inline const std::string joindre(const std::vector<std::string>& vecteur, const char jointure)
            { return joindre(vecteur, std::string(1, jointure)); }
        }
    }
}

#endif