#ifndef H_BTTP_MESSAGE_CONTROLE_INCONNU
#define H_BTTP_MESSAGE_CONTROLE_INCONNU

#include "../../../erreur/Erreur.h"

#define BTTP_MESSAGE_CONTROLE_INCONNU_CODE -200

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            namespace Messages
            {
                namespace Controle
                {
                    /**
                     * @brief Erreur de résolution de type de message de controle.
                     */
                    class Inconnu : public Erreur
                    {
                    private:
                        /**
                         * @brief Message à l'origine de l'erreur.
                         */
                        const Protocole::Messages::IMessage& _message;

                    public:
                        /**
                         * @param message Message dont le type de message de controle est inconnu de la fonction de génération.
                         */
                        Inconnu(const Protocole::Messages::IMessage& message)
                            : Erreur(
                                "Messages/Controle/Inconnu", "Impossible de résoudre le type de message de contrôle à appliquer pour le message.",
                                BTTP_MESSAGE_CONTROLE_INCONNU_CODE
                            ),
                            _message{ message }
                        {}

                        /**
                         * @brief Retourne le message à l'origine de l'erreur.
                         * @return const std::string& Message dont le type de message de contrôle était inconnu.
                         */
                        inline const Protocole::Messages::IMessage& message() const { return this->_message; }
                    };
                }
            }
        }
    }
}
#endif