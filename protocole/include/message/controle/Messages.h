#ifndef H_BTTP_MESSAGES_CONTROLE
#define H_BTTP_MESSAGES_CONTROLE

#include "Message.h"

#include "../erreur/type/Inconnu.h"

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
                 * @brief Résout le type d'un paquet et créé une instance de la classe du message.
                 * 
                 * @param paquet Paquet à résoudre.
                 * @return Message* Instance de la classe associé au type résolu.
                 * 
                 * @throws Erreur::Messages::Type::Inconnu Le type du paquet n'est pas connu.
                 */
                Message* resoudre(const std::string paquet);

                // TODO Reprendre la fonction d'initialisation (switch) avec une initialisation du message à la fin.
                // TODO Créer la classe d'erreur Erreur::Messages::Controle::Inconnu
                /**
                 * @brief Génère une instance d'un message de contrôle du type associé au type du message en entrée.
                 * 
                 * @param message Message simple à encapsuler.
                 * @param destinataire Destinataire du message encapsulé.
                 * @param signataire Signataire du message encapsulé.
                 * @param mdp Mot de passe du signataire.
                 * @return Message* 
                 * 
                 * @throws Erreur::Messages::Controle::Inconnu Le type du message ne correspond à aucun type de message de controle.
                 */
                Message* generer(
                    const Messages::Message& message, const Identite::ClePublique destinataire,
                    const Identite* signataire, const std::string mdp = ""
                );
            }
        }
    }
}

#endif