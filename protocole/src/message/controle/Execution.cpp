#include "../../../include/message/controle/Execution.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            namespace Controle
            {
                Execution::Execution(
                    const IMessage* message, const Cle::Publique destinataire,
                    const Identite* signataire, const std::string mdp
                ) : Message(Type::EXECUTION, message, destinataire, signataire, mdp), 
                _id_script{ nullptr }
                {
                    // Récupération de l'identifiant du script.
                    this->_id_script = new uint32_t(
                        Messages::Execution(message->construire()).id_script()
                    );
                }
            }
        }
    }
}