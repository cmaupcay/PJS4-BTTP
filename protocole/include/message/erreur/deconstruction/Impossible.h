#ifndef H_BTTP_MESSAGES_DECONSTRUCTION_IMPOSSIBLE
#define H_BTTP_MESSAGES_DECONSTRUCTION_IMPOSSIBLE

#include "../../../Erreur.h"

#define BTTP_MESSAGES_DECONSTRUCTION_IMPOSSIBLE_CODE -100

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
                     * @brief Erreur de déconstruction d'un paquet par un message.
                     */
                    class Impossible : public Erreur
                    {
                    private:
                        /**
                         * @brief Paquet à l'origine de l'erreur.
                         */
                        const std::string _paquet;

                    public:
                        /**
                         * @param paquet Paquet à l'origine de l'erreur.
                         * @param message Message détaillant l'erreur.
                         * @param nom Nom de l'erreur.
                         * @param code Code numérique UNIQUE à l'erreur.
                         */
                        Impossible(
                            const std::string paquet, const std::string message,
                            const std::string nom = "Impossible", const int code = BTTP_MESSAGES_DECONSTRUCTION_IMPOSSIBLE_CODE
                        )
                            : Erreur("Messages/Deconstruction/" + nom, "Le paquet ne peut pas être déconstruit : " + message, code), _paquet{ paquet }
                        {}

                        /**
                         * @brief Retourne le paquet à l'origine de l'erreur.
                         * @return const std::string& Paquet n'ayant pas pu être déconstruit.
                         */
                        inline const std::string& paquet() const { return this->_paquet; }
                    };
                }
            }
        }
    }
}

#endif