#ifndef H_BTTP_ERREUR
#define H_BTTP_ERREUR

#include <iomanip>
#include <exception>

#ifndef BTTP_ERREUR_CODE_DEFAUT
    #define BTTP_ERREUR_CODE_DEFAUT -1
#endif

namespace BTTP
{
    // TOCOMMENT
    class Erreur : public std::exception
    {
    private:
        const std::string _nom;
        const std::string _message;
        const int _code;

    public:
        Erreur(const std::string nom, const std::string message, const int code = BTTP_ERREUR_CODE_DEFAUT)
            : _nom{ nom }, _message{ message }, _code{ code }
        {}

        inline const std::string& nom() const { return this->_nom; }
        inline const std::string afficher() const { return "[BTTP/" + this->_nom + ":" + std::to_string(this->_code) + "] " + this->_message + '\n'; }

        inline const int& code() const { return this->_code; }

        const char* what() const noexcept override { return this->_nom.c_str(); }
        
        inline friend std::ostream& operator<<(std::ostream& os, const Erreur& err) { return (os << err.afficher()); }
    };
}

#endif