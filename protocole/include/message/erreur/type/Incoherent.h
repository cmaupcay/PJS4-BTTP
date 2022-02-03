#ifndef H_BTTP_MESSAGE_TYPE_INCOHERENT
#define H_BTTP_MESSAGE_TYPE_INCOHERENT

#include "../../../Erreur.h"

#ifndef BTTP_MESSAGE_TYPE_INCOHERENT_CODE
    #define BTTP_MESSAGE_TYPE_INCOHERENT_CODE -111
#endif

namespace BTTP
{
    namespace Protocole
    {
        namespace Erreur
        {
            class Messages_Type_Incoherent : public Erreur
            {
            private:
                const char _type_c;
                const std::string& _paquet;
            public:
                Messages_Type_Incoherent(const char type_c, const std::string& paquet)
                    : Erreur("Messages/Type/Incohérent", "Le type du paquet n'est pas cohérent avec le type du message.", BTTP_MESSAGE_TYPE_INCOHERENT_CODE),
                    _type_c{ type_c }, _paquet{ paquet }
                {}

                inline const char& type_c() const { return this->_type_c; }
                inline const std::string& paquet() const { return this->_paquet; }
            };
        }
    }
}
#endif