#ifndef H_BTTP_SERVEUR_DATA_MODELE
#define H_BTTP_SERVEUR_DATA_MODELE

#include "Source.h"

#define BTTP_DATA_ID_NULL 0

namespace BTTP
{
    namespace Serveur
    {
        namespace Data
        {
            class Modele
            {
            private:
                std::unique_ptr<Source>& _source;
                const std::string& _reference;
                uint32_t _id;

            protected:
                Modele(std::unique_ptr<Source>& source, const std::string reference, const uint32_t id = BTTP_DATA_ID_NULL)
                    : _source{ source }, _reference{ reference }, _id { id }
                {}

                virtual const bool existe_sans_id() const = 0;
                virtual const bool existe_depuis_id() const = 0;

                virtual const bool mettre_a_jour_sans_id() = 0;
                virtual const bool mettre_a_jour_depuis_id() = 0;

            public:
                inline const bool existe() const 
                { return (this->_id == BTTP_DATA_ID_NULL ? this->existe_sans_id() : this->existe_depuis_id()); }
                
                inline const bool mettre_a_jour()
                { return (this->_id == BTTP_DATA_ID_NULL ? this->mettre_a_jour_sans_id() : this->mettre_a_jour_depuis_id()); }

                inline const std::string& reference() const { return this->_reference; }
                inline const uint32_t& id() const { return this->_id; }
            };
        }
    }
}

#endif