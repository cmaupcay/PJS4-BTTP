<?php

function accueil()
{
    require_once("./controleur/general/connexion.php");
    
    require_once('./modele/marketplace.php');

       //cette fonction affichera les scripts disponibles de la marketplace
       // scripts_disponibles($scripts);

       //affichera la liste des scritps disponibles 
       require('./vue/abonnes/accueil.tpl');
}

function profil() {

    require_once './modele/utilisateur.php';

    $pseudo = isset($_POST['pseudo'])?($_POST['pseudo']):'';

    require_once './vue/abonnes/profil.tpl';
}

function appareils() {

    require_once './modele/utilisateur.php';

    require_once("./vue/abonnes/appareils.tpl");
    
}

function marketplace() {

    require_once './modele/marketplace.php';

    $scriptsRecuperes = scripts_publiques();

    require_once './vue/abonnes/marketplace.tpl';

    echo '<div class="container py-5 bg-light">';
    echo '<div class="row">';

    foreach($scriptsRecuperes as $script) {
        echo('<div class="col-md-4 col-sm-4">');
        echo('<div class="card mb-4 shadow-sm">');
        echo('<div class="card-body"');
        $i = 0;
        foreach($script as $scr=>$s) {
            if($i == 0) {
                echo '<p class="card-text"> Nom : ' . $s . '</p>';
            }
            if($i == 1) {
                echo '<p class="card-text"> Date de publication : ' . $s . '</p>';
            }
            if($i==2) {
                echo '<p class="card-text"> Version : ' . $s . '</p>';
            }
                $i++;
        }
        echo '<button type="button" class="btn btn-sm btn-outline-secondary"> Télécharger </button>';
        echo '<button type="button" class="btn btn-sm btn-outline-secondary"> Code source </button>';
        echo '</div>';
        echo '</div>';
        echo '</div>';
    }
    echo '</div>';
    echo '</div>';
}

function informations() {
    
    require_once './vue/abonnes/informations.tpl';
}

function deconnexion() {

    $_SESSION['profil'] = array();
    setcookie("Jeton", "", time() - 3600);

    $url = "index.php?controle=visiteurs&action=accueil";
    header("Location:" . $url);

}




