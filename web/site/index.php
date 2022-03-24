<?php

session_start();

$erreur = false;

require_once("./modele/connectBD.php");
require_once("./modele/inscription.php");
require_once("./modele/connexion.php");

if(isset($_POST["pseudo"]) && isset($_POST["mdp"])){ //Quelqu'un vient de se connecter
    //echo($_POST["pseudo"] . " ");
    //echo($_POST["mdp"] . " ");
    $_SESSION["pseudo"] = $_POST["pseudo"];
    $_SESSION["mdp"] = $_POST["mdp"];
}

if(isset($_SESSION["pseudo"]) && isset($_SESSION["mdp"])){
    echo($_SESSION["pseudo"] . " ");
    echo($_SESSION["mdp"] . " ");
    $identifie = verif_utilisateur($_SESSION["pseudo"], $_SESSION["mdp"]);
}
else{
    
    $identifie = false;
}



if (isset($_GET['controle']) && isset($_GET['action'])) {

    $controle = $_GET['controle'];
    $action = $_GET['action'];

    if ($controle == "visiteurs" && $action == "accueil") {
        require('controleur/utilisateurs/visiteurs.php');
        accueil();
    } elseif ($controle == "visiteurs" && $action == "inscription") {
        require('controleur/utilisateurs/visiteurs.php');
        inscription();
    } elseif ($controle == "visiteurs" && $action == "connexion") {
        require('controleur/utilisateurs/visiteurs.php');
        connexion();
    } elseif ($controle == "abonnes" && $action == "accueil" && $identifie) { //on rajoute l'identification pour acceder à la page abonné
        require('controleur/utilisateurs/abonnes.php');
        accueil();
    } else {
        require('erreur404.tpl');
        $erreur = false;
    }
} else {
    $controle = 'Connexion';
    $action = 'verif_connexion';

    require('./controleur/general/' . $controle . '.php');
    $action();
}
