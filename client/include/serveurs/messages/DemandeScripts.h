#ifndef H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_SCRIPTS
#define H_BTTP_CLIENT_SERVEUR_MESSAGE_DEMANDE_SCRIPTS

#include "../Appareil.h"

/** Champs de demande correspondant aux scripts d'un appareil. */
#define BTTP_DEMANDE_SCRIPTS "app.src"
/** Nom de l'argument définissant l'appareil cible (empreinte de la clé). */
#define BTTP_DEMANDE_SCRIPTS_APPAREIL "app"

namespace BTTP
{
    namespace Client
    {
        namespace Serveurs
        {
            namespace Messages
            {
                class DemandeScripts : public Protocole::Messages::Demande
                {
                public:
                    DemandeScripts(const Appareil& appareil)
                        : Protocole::Messages::Demande(
                            BTTP_DEMANDE_SCRIPTS, 
                            { {
                                BTTP_DEMANDE_SCRIPTS_APPAREIL,
                                appareil.cle().empreinte()
                            } }
                        )
                    {}
                };
            }
        }
    }
}

#endif