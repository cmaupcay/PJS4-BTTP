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

    require_once './vue/abonnes/profil.tpl';
}

function appareils() {

    require_once './modele/utilisateur.php';

    $appareils = getAppareils();

    require_once("./vue/abonnes/appareils.tpl");
    
    echo '<div class="container py-5 bg-light">';
    echo '<div class="row">';

        foreach($appareils as $appareil) {
            echo('<div class="col-md-4 col-sm-4">');
            echo('<div class="card mb-4 shadow-sm">');
            echo('<div class="card-body">');
            $i = 0;
            foreach($appareil as $ap => $a) {
                if($i == 0){
                    echo'<p class="card-text"> Empreinte de la clé publique : ' . $a . '</p>';
                }
                if($i == 1){
                    echo'<p class="card-text"> Nom: ' . $a . '</p>';
                }
                if($i == 2){
                    echo'<p class="card-text"> Date d\'ajout : ' . $a . '</p>';
                }
                if($i == 3){
                    echo'<p class="card-text"> Dernière connexion : ' . $a . '</p>';
                }
                    $i++;
            }

            //TODO : faire passer l'id du terminal pour l'envoyer dans la fonction supprimer_terminal
            echo '<a href="?controle=abonnes?action=supprimer"><button class="btn btn-sm btn-outline-secondary"> Supprimer </button></a>';
            echo '<a href="?controle=abonnes?action=scripts"><button class="btn btn-sm btn-outline-secondary"> Scripts </button></a>';

            echo '</div>';
            echo '</div>';
            echo '</div>';

        }
    echo '</div>';
    echo '</div>';
}

function supprimer($idTerminal) {
    require './modele/terminal.php';

    supprimer_terminal($idTerminal);

    require_once './modele/appareils.tpl';

    echo 'suppression réussie'; //juste pour tester 
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

    $url = "?controle=visiteurs&action=accueil";
    header("Location:" . $url);

}




