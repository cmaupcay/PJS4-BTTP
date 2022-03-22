#ifndef H_BTTP_MESSAGES
#define H_BTTP_MESSAGES

#include "ClePublique.h"
#include "Demande.h"
#include "Reponse.h"
#include "Pret.h"
#include "Erreur.h"
#include "Ouverture.h"
#include "Execution.h"
#include "Resultat.h"
#include "Fermeture.h"

#include "erreur/type/Inconnu.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            // TOTEST
            /**
             * @brief Résout le type d'un paquet et créé une instance de la classe du message associé au type.
             * 
             * @param paquet Paquet à résoudre.
             * @return BTTP::Protocole::Message* Instance de la classe associé au type résolu.
             * 
             * @throws Erreur::Messages::Type::Inconnu Le type du paquet n'est pas connu.
             */
            Message* resoudre(const std::string paquet);
        }
    }
}

#endif