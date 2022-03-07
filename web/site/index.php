<?php

    session_start();

    include_once 'controleur/general/General.php';

    $erreur = false;


    if(isset($_GET['controle']) && isset($_GET['action'])) {

        $controle = $_GET['controle'];
        $action = $_GET['action'];

        if($controle=="visiteurs" && $action=="accueil"){
            accueil();
        }
        elseif($controle=="visiteurs" && $action=="inscription"){
            inscription();
        }
        elseif($controle=="abonnes" && $action=="accueil"){ //pas sur si c utile d'avoir un controle en entier pour les abonnes et les visiteurs
            accueil();
        }
        elseif($controle=="abonnes" && $action=="connexion"){
            connexion();
        }
        else{
            require('erreur404.tpl');
            $erreur = false;
        }
    }
    $controle = 'connexion';
    $action = 'verif_connexion';

    require('./controleur/general/' . $controle . '.php');
    $action ();
?>