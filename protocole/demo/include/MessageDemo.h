#include <BTTP.h>

class MessageDemo : public BTTP::Protocole::Messages::Message
{
private:
    std::string _contenu;
    inline const std::string contenu() const override 
    { return this->_contenu; }
        
    inline void deconstruction(const std::string contenu) override
    { 
        std::string _tmp = std::string(contenu.rbegin(), contenu.rend());
        if (_tmp[0] == '\n')
        {
            _tmp.erase(_tmp.begin());
            _tmp.append("\n");
        }
        this->_contenu = _tmp;
    }

public:
    MessageDemo(const std::string contenu)
        : BTTP::Protocole::Messages::Message(
            BTTP::Protocole::Messages::Type::EXECUTION
        ), _contenu{ "" }
    { this->deconstruction(contenu); }

    inline const std::string& lire() const { return this->_contenu; }
};