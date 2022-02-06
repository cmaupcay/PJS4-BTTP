#include "../include/BTTP-Client.h"

namespace BTTP 
{

    namespace Client 
    {

        namespace Coeur
        {

            const std::string fichier(const std::string nom, const std::string chemin, const bool dossier_contexte)
            { return (dossier_contexte ? Contexte::dossier() + '/' : "") + (chemin != "" ? chemin + '/' : "") + nom + '.' + BTTP_IDENTITE_EXT; }

            void ecrireCle(const std::string cle, const std::string nom, const std::string chemin, const bool creer_chemin, const bool dossier_contexte) 
            {

                const std::string fichie = fichier(nom, chemin, dossier_contexte);

                const std::string dossier = fichie.substr(0, fichie.find_last_of('/'));

                if(!std::filesystem::is_directory(dossier))
                {

                    if(creer_chemin) std::filesystem::create_directories(dossier);

                }

                std::ofstream fichier_ex(fichie, std::ios::binary);
                
                fichier_ex << cle << std::flush;
                fichier_ex.close();

            }

            const std::string lireCle(const std::string nom, const std::string chemin, const bool dossier_contexte){

                const std::string fichie = fichier(nom, chemin, dossier_contexte);
                std::ifstream fichier_im(fichie, std::ios::binary);

                //TODO corriger ça (je suis un peu un escroc)
                
                Protocole::Cle::Privee *cle = new Protocole::Cle::Privee(fichier_im);

                fichier_im.close();

                return cle->write(OpenPGP::PGP::Armored::NO);


            }



        }

    }
}