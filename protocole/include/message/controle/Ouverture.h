#ifndef BTTP_MESSAGE_CONTROLE_OUVERTURE
#define BTTP_MESSAGE_CONTROLE_OUVERTURE

#include "Message.h"
#include "../Ouverture.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            namespace Controle
            {
                // TOCOMMENT
                class Ouverture : public Message
                {
                private:
                    /**
                     * @brief Retourne l'en-tête du message, qui contient les informations devant être lues par l'appareil de contrôle.
                     * @see BTTP::Protocole::Messages::Controle::TMessage<_Type>::construire()
                     * @return const std::string Ce type de message ne contient aucune information spécifique.
                     */
                    inline const std::string entete() const override { return ""; }
                    /**
                     * @brief Déconstruction de l'en-tête d'un paquet et enregistrement des informations extraites.
                     * @details Ce type de message ne contient aucune information spécifique.
                     * @see BTTP::Protocole::Messages::Controle::TMessage<_Type>::deconstruction()
                     * @param entete En-tête extraite d'un paquet.
                     */
                    inline void lire_entete(const std::string entete) override {}

                public:
                    /**
                     * @brief Construction d'un nouveau message de contrôle à partir d'un message BTTP.
                     * @see BTTP::Protocole::Messages::Controle::TMessage<_Type>::initialiser()
                     * @param message Message à linéariser, chiffrer et signer.
                     * @param destinataire Destinataire du message contenu.
                     * @param signataire Signataire du message contenu.
                     * @param mdp Mot de passe du signataire.
                     */
                    Ouverture(
                        const IMessage* message, const Cle::Publique destinataire,
                        const Identite* signataire, const std::string mdp
                    ) : Message(Type::OUVERTURE, message, destinataire, signataire, mdp)
                    {}

                    /**
                     * @brief Construction d'un nouveau message de contrôle à partir d'un paquet.
                     * @param paquet Paquet à déconstruire.
                     */
                    Ouverture(const std::string paquet)
                        : Message(Type::OUVERTURE, paquet)
                    {}
                };
            }
        }
    }
}

#endif