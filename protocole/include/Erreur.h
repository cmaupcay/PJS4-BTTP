#ifndef H_BTTP_ERREUR
#define H_BTTP_ERREUR

#include <string>
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
        inline const std::string& message() const { return this->_message; }

        const char* what() const throw ()
        { return ("[" + this->_nom + "] " + this->_message).c_str(); }
    };
}

#endif