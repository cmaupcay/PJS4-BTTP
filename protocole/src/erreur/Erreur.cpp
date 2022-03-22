#include "../../include/erreur/Erreur.h"

namespace BTTP
{
    Erreur::Erreur(const std::string nom, const std::string message, const int code)
        : _nom{ "BTTP/" + nom }, _message{ message }, _code{ code }
    {}
}