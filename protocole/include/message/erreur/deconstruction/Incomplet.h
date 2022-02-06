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
                    /**
                     * @brief Erreur de déconstruction d'un paquet par un message après découpage du paquet.
                     */
                    class Incomplet : public Impossible
                    {
                    private:
                        /**
                         * @brief Nombre d'éléments extraits du paquet à l'origine de l'erreur.
                         */
                        const uint8_t _elements;
                        /**
                         * @brief Nombre d'éléments nécessaires pour la construction du message.
                         */
                        const uint8_t _elements_attendus;

                    public:
                        /**
                         * @param paquet Paquet à l'origine de l'erreur.
                         * @param elements Nombre d'éléments extraits du paquet.
                         * @param elements_attendus Nombre d'éléments nécessaires.
                         */
                        Incomplet(const std::string paquet, const uint8_t elements, const uint8_t elements_attendus)
                            : Impossible(
                                paquet, "des informations nécessaires sont absentes (" + std::to_string(elements) + '/' + std::to_string(elements_attendus) + ").",
                                "Incomplet", BTTP_MESSAGES_DECONSTRUCTION_INCOMPLET_CODE
                            ),
                            _elements{ elements }, _elements_attendus{ elements_attendus }
                        {}

                        /**
                         * @brief Retourne le nombre d'éléments extrait du paquet.
                         * @return const uint8_t& Nombre d'élements.
                         */
                        const uint8_t& elements() const { return this->_elements; }
                        /**
                         * @brief Retourne le nombre d'éléments nécessaire à la construction du message.
                         * @return const uint8_t& Nombre d'éléments attendus.
                         */
                        const uint8_t& elements_attendus() const { return this->_elements_attendus; }
                    };
                }
            }
        }
    }
}

#endif