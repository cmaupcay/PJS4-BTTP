#ifndef H_BTTP_MESSAGE_CONTROLE
#define H_BTTP_MESSAGE_CONTROLE

#include "../Message.h"
#include "../../identite/Identite.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            namespace Controle
            {
                // TOTEST Voir les fonctions implémentées.
                /**
                 * @brief Classe de base des messages de contrôle manipulé par le protocole.
                 * @tparam _Type Enumération des types de message.
                 */
                template<class _Type>
                class TMessage : public Protocole::Messages::TMessage<_Type>
                {
                private:
                    /**
                     * @brief Contenu chiffré du message à l'attention du destinataire.
                     */
                    std::string _message;
                    /**
                     * @brief Empreinte du destinataire. Permet à l'appareil de contrôle de reconnaître le destinataire.
                     * @details Le client peut ainsi envoyer des messages à différents appareils distants sur une même
                     * connexion avec l'appareil de contrôle.
                     */
                    std::string _destinataire;

                    /**
                     * @brief Retourne le contenu du message à ajouter au paquet.
                     * @return const std::string Contenu chiffré à l'attention du destinataire.
                     */
                    inline const std::string contenu() const override { return this->_message; }

                protected:
                    /**
                     * @brief Construction d'un nouveau message de contrôle à partir d'un message BTTP.
                     * @param type Type du message de contrôle.
                     * @param message Message à linéariser, chiffrer et signer.
                     * @param destinataire Destinataire du message contenu.
                     * @param signataire Signataire du message contenu.
                     * @param mdp Mot de passe du signataire.
                     */
                    TMessage(
                        const _Type type, 
                        const IMessage& message, const Cle::Publique destinataire,
                        const Identite& signataire, const std::string mdp
                    );
                    /**
                     * @brief Construction d'un nouveau message de contrôle à partir d'un paquet.
                     * @param type Type du message de contrôle.
                     * @param paquet Paquet à déconstruire.
                     */
                    TMessage(const _Type type, const std::string paquet);

                    /**
                     * @brief Retourne l'en-tête du message, qui contient les informations devant être lues par l'appareil de contrôle.
                     * @see BTTP::Protocole::Messages::Controle::TMessage<_Type>::construire()
                     * @return const std::string En-tête linéarisée.
                     */
                    virtual const std::string entete() const = 0;
                    /**
                     * @brief Déconstruction de l'en-tête d'un paquet et enregistrement des informations extraites.
                     * @see BTTP::Protocole::Messages::Controle::TMessage<_Type>::deconstruction()
                     * @param entete En-tête extraite d'un paquet.
                     */
                    virtual void lire_entete(const std::string entete) = 0;

                    /**
                     * @brief Déconstruction du contenu d'un paquet et enregistrement des informations extraites.
                     * @see BTTP::Protocole::Messages::TMessage<_Type>::deconstruire()
                     * @param contenu Contenu d'un paquet (sans le préfix du type).
                     */
                    void deconstruction(const std::string contenu) override;

                public:
                    /**
                     * @brief Construction d'un paquet à partir des informations du message.
                     * @return const std::string Paquet construit.
                     */
                    const std::string construire() const override;

                    /**
                     * @brief Retourne le contenu du message, à l'attention du destinataire.
                     * @return const std::string& Contenu chiffré et signé.
                     */
                    inline const std::string& message() const { return this->_message; }
                    /**
                     * @brief Retourne l'empreinte du destinataire du contenu.
                     * @return const std::string& Chaîne identifiant le destinataire.
                     */
                    inline const std::string& destinataire() const { return this->_destinataire; }
                };

                /**
                 * @brief Enumération des types standards de messages de contrôle BTTP.
                 */
                enum class Type
                {
                    /**
                     * @brief Ouverture d'une transaction. Encapsule toujours un message de type OUVERTURE.
                     * @details Vérification de l'état du terminal distant.
                     * @see ./Ouverture.h
                     */
                    OUVERTURE = '*',
                    /**
                     * @brief Relais d'un message sans contrôle spécifique.
                     * @see ./Relais.h
                     */
                    RELAIS = '=',
                    /**
                     * @brief Contrôle relatif à une execution. Encapsule toujours un message de type EXECUTION.
                     * @details Vérification du script demandé.
                     * @see ./Execution.h
                     */
                    EXECUTION = '>'
                };

                /**
                 * @brief Classe de base des messages de contrôle BTTP.
                 */
                class Message : public TMessage<Type>
                {
                protected:
                    /**
                     * @brief Construction d'un nouveau message de contrôle à partir d'un message BTTP.
                     * @see BTTP::Protocole::Messages::Controle::TMessage<_Type>::initialiser()
                     * @param type Type du message de contrôle.
                     * @param message Message à linéariser, chiffrer et signer.
                     * @param destinataire Destinataire du message contenu.
                     * @param signataire Signataire du message contenu.
                     * @param mdp Mot de passe du signataire.
                     */
                    Message(
                        const Type type, 
                        const IMessage& message, const Cle::Publique destinataire,
                        const Identite& signataire, const std::string mdp
                    ) : TMessage<Type>(type, message, destinataire, signataire, mdp)
                    {}

                    /**
                     * @brief Construction d'un nouveau message de contrôle à partir d'un paquet.
                     * @param type Type du message de contrôle.
                     * @param paquet Paquet à déconstruire.
                     */
                    Message(const Type type, const std::string paquet)
                        : TMessage<Type>(type, paquet)
                    {}
                };
            }
        }
    }
}

#endif