<?php

function inscription() {
    require('./modele/inscription.php');

    $pseudo = isset($_POST['pseudo'])?($_POST['pseudo']):'';
    $mdp = isset($_POST['mdp'])?($_POST['mdp']):'';


    $msg ="";

    if(count($_POST) < 2) { //Redirige vers l'inscription si les deux champs recus ne sont pas remplis
        require('./vue/visiteurs/inscription.tpl');
    } else {
        if(verif_inscription($pseudo)) { //si le pseudo existe deja on le redirige vers le page de connexion

            $msg = "compte déjà existant";
            require('./vue/visiteurs/connexion.tpl');
        } else {

            insertion_bd($pseudo, $mdp);
            
            require('./modele/Connexion.php');

            if(verif_utilisateur($pseudo, $mdp, $resultat) == false){ //si pour une raison obscure l'inscription marche pas on renvoie l'utilisateur à la page d'inscription
                header("Location:index.php?controle=visiteur&action=inscription");
                die();
            }

            $_SESSION['profil'] = $resultat[0]; //nous permet de reutiliser les infos plus tard

            $url = "index.php?controle=utilisateur&action=accueil";

            header("Location:" . $url);
        }
    }
}

function accueil()
{
    require("./controleur/general/Connexion.php");

    if(isset($_SESSION['profil'])){ //Verification des infos de connexion
        if(verif_utilisateur($_SESSION['profil'][0], $_SESSION['profil'][1], $resultat) == false){ //regarder si les tableaux des profils marchent bien comme ca
            
            //nous permet d'utiliser du contenu marketplace specifique sinon on le fait pas
            
        }
    }
    
    require ('./modele/marketplace.php');

        echo 'salut visiteur';
       //cette fonction affichera les scripts disponibles de la marketplace
       // scripts_disponibles($scripts);

       require('./vue/visiteurs/accueil.tpl');
}

function connexion() {
    require('./modele/Connexion.php');

    //Ici on met ce dont on a besoin afin de relier le modele et la vue

    require_once('./vue/connexion.tpl');
}

?>