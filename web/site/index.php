<?php

session_start();

$erreur = false;


if (isset($_GET['controle']) && isset($_GET['action'])) {

    $controle = $_GET['controle'];
    $action = $_GET['action'];

    if ($controle == "visiteurs" && $action == "accueil") {
        require('controleur/utilisateurs/visiteurs.php');
        accueil();
    } elseif ($controle == "visiteurs" && $action == "inscription") {
        require('controleur/utilisateurs/visiteurs.php');
        inscription();
    } elseif ($controle == "visiteurs" && $action == "connexion") { //impossible d'avoir un abonné se connecter parce qu'on sait pas si c'est un abonné
        require('controleur/utilisateurs/visiteurs.php');
        connexion();
    } elseif ($controle == "abonnes" && $action == "accueil") { //pas sur si c utile d'avoir un controle en entier pour les abonnes et les visiteurs
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
