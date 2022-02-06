#ifndef H_BTTP_MESSAGES_VIDE
#define H_BTTP_MESSAGES_VIDE

#include "../../Erreur.h"

#ifndef BTTP_MESSAGES_VIDE_CODE
    #define BTTP_MESSAGES_VIDE_CODE -200
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Messages
            {
                /**
                 * @brief Erreur de tentative de lecture d'un message vide.
                 */
                class Vide : public Erreur
                {
                protected:
                    /**
                     * @param emplacement Emplacement vide qui a été lu.
                     * @param code Code UNIQUE à l'erreur.
                     */
                    Vide(const std::string emplacement, const int code = BTTP_MESSAGES_VIDE_CODE)
                        : Erreur("Messages/Vide", emplacement + " est vide.", code)
                    {}

                public:
                    Vide()
                        : Erreur("Messages/Vide", "Le message est vide.", BTTP_MESSAGES_VIDE_CODE)
                    {}
                };
            }
        }
    }
}
#endif