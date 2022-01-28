#ifndef H_BTTP_ERREUR
#define H_BTTP_ERREUR

#include <iomanip>
#include <exception>

namespace BTTP
{
    class Erreur : public std::exception
    {
    private:
        const std::string _nom;
        const std::string _message;

    public:
        Erreur(const std::string nom, const std::string message)
            : _nom{ nom }, _message{ message }
        {}

        inline const std::string& nom() const { return this->_nom; }
        inline const std::string afficher() const { return "[BTTP/" + this->_nom + "] " + this->_message + '\n'; }

        const char* what() const noexcept override { return this->_nom.c_str(); }
        
        inline friend std::ostream& operator<<(std::ostream& os, const Erreur& err) { return (os << err.afficher()); }
    };
}

#endif