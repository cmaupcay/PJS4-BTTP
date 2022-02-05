#ifndef H_BTTP_MESSAGES_DECONSTRUCTION_IMPOSSIBLE
#define H_BTTP_MESSAGES_DECONSTRUCTION_IMPOSSIBLE

#include "../../../Erreur.h"

#ifndef BTTP_MESSAGES_DECONSTRUCTION_IMPOSSIBLE_CODE
    #define BTTP_MESSAGES_DECONSTRUCTION_IMPOSSIBLE_CODE -100
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Messages
            {
                namespace Deconstruction
                {
                    // TOCOMMENT
                    class Impossible : public Erreur
                    {
                    private:
                        const std::string _paquet;
                    public:
                        Impossible(
                            const std::string paquet, const std::string message,
                            const std::string nom = "Impossible", const int code = BTTP_MESSAGES_DECONSTRUCTION_IMPOSSIBLE_CODE
                        )
                            : Erreur("Messages/Deconstruction/" + nom, "Le paquet ne peut pas être déconstruit : " + message, code), _paquet{ paquet }
                        {}

                        inline const std::string& paquet() const { return this->_paquet; }
                    };
                }
            }
        }
    }
}

#endif