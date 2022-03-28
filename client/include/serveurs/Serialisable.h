#ifndef H_BTTP_CLIENT_SERIALISABLE
#define H_BTTP_CLIENT_SERIALISABLE

#include "../Racine.h"

namespace BTTP
{
    namespace Client
    {
        class ISerialisable
        {
        public:
            virtual const std::string serialiser() const = 0;
        };
    }
}

#endif