#ifndef BTTP_MESSAGE_CONTROLE_EXECUTION
#define BTTP_MESSAGE_CONTROLE_EXECUTION

#include "Message.h"
#include "../Execution.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            namespace Controle
            {
                // TOCOMMENT
                class Execution : public Message
                {
                private:
                    /**
                     * @brief Identifiant numérique du script à exécuter.
                     */
                    uint32_t* _id_script;

                    /**
                     * @brief Retourne l'en-tête du message, qui contient les informations devant être lues par l'appareil de contrôle.
                     * @see BTTP::Protocole::Messages::Controle::TMessage<_Type>::construire()
                     * @return const std::string Identifiant du script.
                     */
                    inline const std::string entete() const override { return std::to_string(*this->_id_script); }
                    /**
                     * @brief Déconstruction de l'en-tête d'un paquet et enregistrement des informations extraites.
                     * @see BTTP::Protocole::Messages::Controle::TMessage<_Type>::deconstruction()
                     * @param entete En-tête extraite d'un paquet.
                     */
                    inline void lire_entete(const std::string entete) override 
                    { this->_id_script = new uint32_t(std::atoi(entete.c_str())); }

                public:
                    /**
                     * @brief Construction d'un nouveau message de contrôle à partir d'un message BTTP.
                     * @see BTTP::Protocole::Messages::Controle::TMessage<_Type>::initialiser()
                     * @param message Message à linéariser, chiffrer et signer.
                     * @param destinataire Destinataire du message contenu.
                     * @param signataire Signataire du message contenu.
                     * @param mdp Mot de passe du signataire.
                     */
                    Execution(
                        const IMessage* message, const Cle::Publique destinataire,
                        const Identite* signataire, const std::string mdp
                    );
                    /**
                     * @brief Construction d'un nouveau message de contrôle à partir d'un paquet.
                     * @param paquet Paquet à déconstruire.
                     */
                    Execution(const std::string paquet)
                        : Message(Type::EXECUTION, paquet)
                    {}
                };
            }
        }
    }
}

#endif