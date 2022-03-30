#include "../../include/messages/Messages.h"

namespace BTTP
{
    namespace Protocole
    {
        namespace Messages
        {
            Message* resoudre(const std::string paquet)
            {
                if (paquet.length() > 0)
                    switch (static_cast<Type>(paquet[0]))
                    {
                    case Type::DEMANDE:
                        return new Demande(paquet);
                    case Type::REPONSE:
                        return new Reponse(paquet);
                    case Type::PRET:
                        return new Pret(paquet);
                    case Type::ERREUR:
                        return new Erreur(paquet);
                    case Type::OUVERTURE:
                        return new Ouverture(paquet);
                    case Type::EXECUTION:
                        return new Execution(paquet);
                    case Type::RESULTAT:
                        return new Resultat(paquet);
                    case Type::FERMETURE:
                        return new Fermeture(paquet);
                    default:
                        throw Protocole::Erreur::Messages::Type::Inconnu(paquet);
                    }
                return nullptr;
            }
        }
    }
}