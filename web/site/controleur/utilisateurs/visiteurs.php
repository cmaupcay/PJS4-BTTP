<?php
//Le contenu de ce fichier à été déplacé dans General.php afn de ne pas avoir a require plusieurs fichiers dans l'index

    function accueil() {
        require ('./modele/marketplace.php');

        echo 'salut visiteur';
       //cette fonction affichera les scripts disponibles de la marketplace
       // scripts_disponibles($scripts);

       require('./vue/visiteurs/accueil.tpl');
    }

    function inscription() {
        require_once('./modele/inscription.php');

        $pseudo = isset($_POST['pseudo'])?($_POST['pseudo']):'';
        $mdp = isset($_POST['mdp'])?($_POST['mdp']):'';


        $msg ="";

        if(count($_POST) < 2) {
            require('./vue/visiteurs/inscription.tpl');
        } else {
            if(verif_inscription($pseudo)) {

                $msg = "compte déjà existant";
                require('./vue/visiteurs/inscription.tpl');
            } else {

                insertion_bd($pseudo, $mdp);
                
                require_once('./modele/connexion.php');

                verif_utilisateur($pseudo, $mdp, $resultat);

                $_SESSION['profil'] = $resultat[0];

                //require('./controle/connexion.php');

                $url = "?controle=abonne&action=accueil";

                header("Location:" . $url);
            }
        }
    }

    function connexion() {
        require_once('./modele/connexion.php');
    
        //Ici on met ce dont on a besoin afin de relier le modele et la vue
    
        require_once('./vue/connexion.tpl');
    }
