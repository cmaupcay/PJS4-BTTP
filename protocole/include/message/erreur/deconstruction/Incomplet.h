#ifndef H_BTTP_MESSAGES_DECONSTRUCTION_INCOMPLET
#define H_BTTP_MESSAGES_DECONSTRUCTION_INCOMPLET

#include "Impossible.h"

#ifndef BTTP_MESSAGES_DECONSTRUCTION_INCOMPLET_CODE
    #define BTTP_MESSAGES_DECONSTRUCTION_INCOMPLET_CODE -101
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
                    class Incomplet : public Impossible
                    {
                    private:
                        const uint8_t _elements;
                        const uint8_t _elements_attendus;

                    public:
                        Incomplet(const std::string paquet, const uint8_t elements, const uint8_t elements_attendus)
                            : Impossible(
                                paquet, "des informations nécessaires sont absentes (" + std::to_string(elements) + '/' + std::to_string(elements_attendus) + ").",
                                "Incomplet", BTTP_MESSAGES_DECONSTRUCTION_INCOMPLET_CODE
                            ),
                            _elements{ elements }, _elements_attendus{ elements_attendus }
                        {}

                        const uint8_t& elements() const { return this->_elements; }
                        const uint8_t& elements_attendus() const { return this->_elements_attendus; }
                    };
                }
            }
        }
    }
}

#endif