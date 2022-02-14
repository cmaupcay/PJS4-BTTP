#ifndef H_BTTP_MESSAGES_CONTROLE
#define H_BTTP_MESSAGES_CONTROLE

#include "Message.h"

#include "../erreur/type/Inconnu.h"
#include "erreur/Inconnu.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            namespace Controle
            {
                // TOTEST
                /**
                 * @brief Résout le type d'un paquet et créé une instance de la classe du message associé au type.
                 * @param paquet Paquet à résoudre.
                 * @return BTTP::Protocole::Controle::Message* Instance de la classe associé au type résolu.
                 * 
                 * @throws Erreur::Messages::Type::Inconnu Le type du paquet n'est pas connu.
                 */
                Message* resoudre(const std::string paquet);

                /**
                 * @brief Génère une instance d'un message de contrôle du type associé au type du message en entrée.
                 * @param message Message BTTP standard à encapsuler.
                 * @param destinataire Destinataire du message encapsulé.
                 * @param signataire Signataire du message encapsulé.
                 * @param mdp Mot de passe du signataire.
                 * @return Message* Message contruit.

                 * @throws Erreur::Messages::Controle::Inconnu Le type du message ne correspond à aucun type de message de controle.
                 */
                Message* generer(
                    const Messages::IMessage& message, const Cle::Publique destinataire,
                    const Identite& signataire, const std::string mdp
                );
            }
        }
    }
}

#endif