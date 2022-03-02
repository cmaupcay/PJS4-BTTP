<?php


    function accueil() {
        require ('.modele/marketplace.php');

        echo 'salut visiteur';
       //cette fonction affichera les scripts disponibles de la marketplace
       // scripts_disponibles($scripts);

       require('./vue/visiteurs/accueil.tpl');
    }

    function inscription() {
        require('./modele/inscription.php');

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

                inseretion_bd($pseudo, $mdp);
                
                require('./modele/connexion.php');

                verif_utilisateur($pseudo, $mdp, $resultat);

                $_SESSION['profil'] = $resultat[0];

                require('./controle/connexion.php');

                $url = "index.php?controle=utilisateur&action=accueil";

                header("Location:" . $url);
            }
        }
    }
?>