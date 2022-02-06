#ifndef H_BTTP_ERREUR
#define H_BTTP_ERREUR

#include <iomanip>
#include <exception>

#ifndef BTTP_ERREUR_CODE_DEFAUT
    #define BTTP_ERREUR_CODE_DEFAUT -1
#endif

namespace BTTP
{
    /**
     * @brief Classe de base des erreurs pour le protocole BTTP et les applications associées.
     */
    class Erreur : public std::exception
    {
    private:
        /**
         * @brief Nom de l'erreur.
         */
        const std::string _nom;
        /**
         * @brief Message d'explication de l'erreur.
         */
        const std::string _message;
        /**
         * @brief Code numérique UNIQUE à l'erreur.
         */
        const int _code;

    public:
        /**
         * @brief Construction par défaut.
         * @param nom Nom de l'erreur. Les espaces de nom sont à séparer par des /.
         * @param message Message d'explication de l'erreur.
         * @param code Code numérique UNIQUE à l'erreur.
         */
        Erreur(const std::string nom, const std::string message, const int code = BTTP_ERREUR_CODE_DEFAUT)
            : _nom{ "BTTP/" + nom }, _message{ message }, _code{ code }
        {}

        /**
         * @brief Retourne le nom de l'erreur. Les espaces de nom sont séparés par des /.
         * @return const std::string& Nom de l'erreur.
         */
        inline const std::string& nom() const { return this->_nom; }
        /**
         * @brief Linéarise les informations de l'erreur pour l'affichage.
         * @return const std::string au format : [nom:code] message
         */
        inline const std::string afficher() const { return "[" + this->_nom + ":" + std::to_string(this->_code) + "] " + this->_message + '\n'; }
        /**
         * @brief Retourne le code numérique unique à l'erreur.
         * @return const int& Code erreur.
         */
        inline const int& code() const { return this->_code; }

        /**
         * @brief Retourne le nom de l'erreur.
         * @see BTTP::Erreur::nom()
         * @return const char* Nom de l'erreur.
         */
        const char* what() const noexcept override { return this->_nom.c_str(); }
        
        /**
         * @brief Envoie l'erreur au format d'affichage dans le flux de sortie. 
         * @see BTTP::Erreur::afficher()
         * @param os Flux de sortie.
         * @param err Erreur à afficher.
         * @return std::ostream& Flux de sortie mis à jour.
         */
        inline friend std::ostream& operator<<(std::ostream& os, const Erreur& err) { return (os << err.afficher()); }
    };
}

#endif