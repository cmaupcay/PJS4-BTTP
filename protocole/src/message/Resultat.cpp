#include "../../include/message/Resultat.h"

namespace BTTP 
{

    namespace Protocole
    {

        namespace Messages
        {
            Resultat::Resultat() 
                : Message(Type::EXECUTION),
                _id{ nullptr }, _resultat{ "" }
            {}


            Resultat::Resultat(const std::string paquet)
                : Message(Type::RESULTAT),
                _id{ nullptr }, _resultat {""}
            {this->deconstruire(paquet); }

            
            const std::string Resultat::contenu() const 
            {
                
            }
            
        }
    }
}