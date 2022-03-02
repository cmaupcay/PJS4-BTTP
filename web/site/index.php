<?php

    session_start();

    $erreur = false;


    if(isset($_GET['controle']) && isset($_GET['action'])) {

        $controle = $_GET['controle'];
        $action = $_GET['action'];

        if(!(($controle=="visiteurs") && ($action =="action" || ($action="inscription")) || 
            ($controle=="abonnes") && ($action=="accueil" || $action=="connexion"))){

                require('erreur404.tpl');
                $erreur = false;
        }
    }
    $controle = 'connexion';
    $action = 'verif_connexion';

    require('./controleur/general/' . $controle . '.php');
    $action ();
?>