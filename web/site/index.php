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
        elseif($controle=="visiteurs" && $action=="connexion"){ //impossible d'avoir un abonné se connecter parce qu'on sait pas si c'est un abonné
            connexion();
        }
        elseif($controle=="abonnes" && $action=="accueil"){ //pas sur si c utile d'avoir un controle en entier pour les abonnes et les visiteurs
            accueil();
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