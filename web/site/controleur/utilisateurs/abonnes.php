<?php

function accueil()
{
    require("./controleur/general/connexion.php");
    
    require ('./modele/marketplace.php');

       //cette fonction affichera les scripts disponibles de la marketplace
       // scripts_disponibles($scripts);

       //affichera la liste des scritps disponibles 
       require('./vue/abonnes/accueil.tpl');
}

function appareils() {

    require("./vue/abonnes/appareils.tpl");
    
}

function deconnexion() {

    $_SESSION['profil'] = array();
    setcookie("Jeton", "", time() - 3600);

    $url = "index.php?controle=visiteurs&action=accueil";
    header("Location:" . $url);

}

