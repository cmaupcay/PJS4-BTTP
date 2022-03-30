#ifndef H_BTTP_MESSAGE
#define H_BTTP_MESSAGE

#include "../Racine.h"

#include <iomanip>
#include <vector>

#include "erreur/deconstruction/Incomplet.h"
#include "erreur/type/Incoherent.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            /**
             * @brief Interface des messages du protocole.
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
                 * @param paquet Paquet à déconstruire.
                 */
                IMessage(const std::string paquet) {}

                /**
                 * @brief Construction d'un paquet à partir des informations du message.
                 * @return const std::string Paquet construit.
                 */
                virtual const std::string construire() const = 0;
                /**
                 * @brief Déconstruction d'un paquet et enregistrement des informations extraites.
                 * @param paquet Paquet à déconstruire.
                 * @throws Erreur::Deconstruction::Impossibe Le paquet ne peut pas être interprété.
                 */
                virtual void deconstruire(const std::string paquet) = 0;
                /**
                 * @brief Type du message pouvant être sérialiser.
                 * @return const char Type du message.
                 */
                virtual const char type_c() const = 0;

                inline friend std::ostream& operator<<(std::ostream& os, const IMessage& msg) { return (os << msg.construire()); }
            };

            // TOTEST Voir les fonctions implémentées.
            /**
             * @brief Classe de base des messages manipulés par le protocole.
             * @tparam _Type Enumération de type des messages.
             */
            template <class _Type>
            class TMessage : public IMessage
            {
            private:
                /**
                 * @brief Type du message.
                 */
                const _Type _type;
            protected:
                /**
                 * @brief Construction du message.
                 * @param type Type du message.
                 */
                TMessage(const _Type type) : _type{ type } {}

                /**
                 * @brief Retourne le contenu du message à ajouter au paquet.
                 * @return const std::string Contenu du message linéarisé.
                 */
                virtual const std::string contenu() const = 0;
                /**
                 * @brief Déconstruction du contenu d'un paquet et enregistrement des informations extraites.
                 * @see BTTP::Protocole::Messages::TMessage<_Type>::deconstruire()
                 * @param contenu Contenu d'un paquet (sans le préfix du type).
                 */
                virtual void deconstruction(const std::string contenu) = 0;

            public:
                /**
                 * @brief Retourne le type du message.
                 * @return const _Type& Type du message.
                 */
                inline const _Type& type() const { return this->_type; }
                /**
                 * @brief Type du message pouvant être sérialiser.
                 * @return const char Type du message.
                 */
                inline const char type_c() const override { return static_cast<char>(this->_type); }

                /**
                 * @brief Construction d'un paquet à partir des informations du message.
                 * @return const std::string Paquet construit.
                 */
                inline const std::string construire() const override
                { return this->type_c() + this->contenu(); }

                /**
                 * @brief Déconstruction d'un paquet et enregistrement des informations extraites.
                 * @param paquet Paquet à déconstruire.
                 * @throws Erreur::Deconstruction::Incoherent Le type du paquet n'est pas celui du message.
                 * @throws Erreur::Deconstruction::Impossibe Le paquet ne peut pas être interprété.
                 */
                void deconstruire(const std::string paquet) override;
            };

            /**
             * @brief Enumération des types standards de messages BTTP.
             */
            enum class Type
            {
                /**
                 * @brief Demande de données.
                 * @see ./Demande.h
                 */
                DEMANDE = '?',
                /**
                 * @brief Données en réponse à une demande.
                 * @pre DEMANDE
                 * @see ./Reponse.h
                 */
                REPONSE = ':',
                /**
                 * @brief Indication de réussite d'une action.
                 * @see ./Pret.h
                 */
                PRET = 'o',
                /**
                 * @brief Indication d'une erreur suite à une action.
                 * @see ./Erreur.h
                 */
                ERREUR = 'n',
                /**
                 * @brief Ouverture d'une transaction.
                 * @see ./Ouverture.h
                 */
                OUVERTURE = '*',
                /**
                 * @brief Demande d'exécution d'un script.
                 * @see ./Execution.h
                 */
                EXECUTION = '>',
                /**
                 * @brief Résultat(s) d'exécution d'un script.
                 * @pre EXECUTION
                 * @see ./Resultat.h
                 */
                RESULTAT = '<',
                /**
                 * @brief Fermeture d'une transaction.
                 * @pre OUVERTURE
                 * @see ./Fermeture.h
                 */
                FERMETURE = '/'
            };

            /**
             * @brief Classe de base des messages BTTP.
             */
            class Message : public TMessage<Type>
            {
            protected:
                /**
                 * @brief Construction du message.
                 * @param type Type du message.
                 */
                Message(const Type type) : TMessage(type) {}
            };

            // TOTEST
            /**
             * @brief Découpe une chaîne de caractère selon un séparateur donné.
             * @param contenu Chaîne de caractère à découper.
             * @param separateur Séparateur à rechercher.
             * @return const std::vector<std::string> Vecteur des parties découpées.
             */
            const std::vector<std::string> decouper(const std::string contenu, const std::string separateur);
            inline const std::vector<std::string> decouper(const std::string contenu, const char separateur)
            { return decouper(contenu, std::string(1, separateur)); }

            // TOTEST
            /**
             * @brief Joins les éléments d'un vecteur de chaîne de caractère en une chaîne de caractère
             * et selon un élément de jointure donné.
             * @param vecteur Vecteur des chaînes de caratère à joindre.
             * @param jointure Jointure à rajouter entre les chaînes.
             * @return const std::string Chaîne de caractère construite.
             */
            const std::string joindre(const std::vector<std::string>& vecteur, const std::string jointure);
            inline const std::string joindre(const std::vector<std::string>& vecteur, const char jointure)
            { return joindre(vecteur, std::string(1, jointure)); }

            /**
             * @brief Paire nom d'argument et valeur.
             */
            struct Argument
            {
                std::string nom;
                std::string valeur;
                Argument(const std::string nom = "", const std::string valeur = "")
                    : nom{ nom }, valeur{ valeur }
                {}
            };

            /**
             * @brief Transformation d'une liste d'arguments en vetceur de paires (nom, valeur).
             * @param args Liste des arguments sous la forme "nom=valeur".
             * @return const std::vector<Argument> Vetceur de paires (nom, valeur).
             */
            const std::vector<Argument> decouper_args(const std::vector<std::string>& args);
            /**
             * @brief Transformation une liste d'arguments en liste des arguments sous la forme "nom=valeur".
             * @return const std::vector<std::string> Liste des arguments sous la forme "nom=valeur".
             */
            const std::vector<std::string> joindre_args(const std::vector<Argument> args);
        }
    }
}

#endif