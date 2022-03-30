<?php
session_start();

$erreur = false;

require_once("./modele/connectBD.php");
require_once("./modele/inscription.php");
require_once("./modele/connexion.php");

if (isset($_POST["pseudo"]) && isset($_POST["mdp"])) { //Quelqu'un vient de se connecter
    $_SESSION["pseudo"] = $_POST["pseudo"];
    $_SESSION["mdp"] = $_POST["mdp"];
    unset($_POST["mdp"]);
    unset($_POST["pseudo"]);
}

if (isset($_POST["stayConnect"])) {
    setcookie("pseudo", $_SESSION["pseudo"], time() + (86400 * 30), "/"); //30 jours
    setcookie("mdp", $_SESSION["mdp"], time() + (86400 * 30), "/");
    unset($_POST["stayConnect"]);
}

if (isset($_SESSION["pseudo"]) && isset($_SESSION["mdp"])) {
    $identifie = verif_utilisateur($_SESSION["pseudo"], $_SESSION["mdp"]);
} else if (isset($_COOKIE["pseudo"]) && isset($_COOKIE["mdp"])) {
    $identifie = verif_utilisateur($_COOKIE["pseudo"], $_COOKIE["mdp"]);
    if ($identifie) {
        $_SESSION["pseudo"] = $_COOKIE["pseudo"];
        $_SESSION["mdp"] = $_COOKIE["mdp"];
    }
} else {

    $identifie = false;
}






require_once("./modele/connectBD.php");

if (isset($_GET['controle']) && isset($_GET['action'])) {

    $controle = $_GET['controle'];
    $action = $_GET['action'];

    //visiteurs
    if ($controle == "visiteurs" && $action == "accueil") {
        require('controleur/utilisateurs/visiteurs.php');
        accueil();
    } elseif ($controle == "visiteurs" && $action == "inscription") {
        require('controleur/utilisateurs/visiteurs.php');
        inscription();
    } elseif ($controle == "visiteurs" && $action == "connexion") {
        require('controleur/utilisateurs/visiteurs.php');
        connexion();
    } elseif ($controle == "visiteurs" && $action == "marketplace") {
        require('controleur/utilisateurs/visiteurs.php');
        marketplace();
    } elseif ($controle == "visiteurs" && $action == "code_source") {
        require('controleur/utilisateurs/visiteurs.php');
        montrer_code();
    }
    elseif ($controle == "visiteurs" && $action == "mdpOublie") {
        require('controleur/utilisateurs/abonnes.php');
        mdpOublie();
    } elseif ($controle == "visiteurs" && $action == "changeMdp") {
        require('controleur/utilisateurs/abonnes.php');
        changeMdp($_POST["pseudoToRescue"], $_POST["mdpToChange"]);
    }
    //abonnés
    elseif ($controle == "abonnes" && $action == "accueil" && $identifie) { //on rajoute l'identification pour acceder à la page abonné
        require('controleur/utilisateurs/abonnes.php');
        accueil();
    } elseif ($controle == "abonnes" && $action == "deconnexion" && $identifie) {
        require('controleur/utilisateurs/abonnes.php');
        deconnexion();
    } elseif ($controle == "abonnes" && $action == "appareils" && $identifie) {
        require('controleur/utilisateurs/abonnes.php');
        appareils();
    } elseif ($controle == "abonnes" && $action == "marketplace" && $identifie) {
        require('controleur/utilisateurs/abonnes.php');
        marketplace();
    } elseif ($controle == "abonnes" && $action == "informations" && $identifie) {
        require('controleur/utilisateurs/abonnes.php');
        informations();
    }  else {
        require('erreur404.tpl');
        $erreur = false;
    }
} else {
    $controle = 'visiteurs';
    $action = 'accueil';

    require('./controleur/utilisateurs/' . $controle . '.php');
    $action();
}
