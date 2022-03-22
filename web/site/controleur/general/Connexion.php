<?php

/**
 * Pas besoin ? pas de cookies dans la base
 */

function verif_connexion() { //A voir si on utilise
    
    require_once("vue/connexion.tpl");

     if(isset($_COOKIE['Jeton'])){
        
        require("./modele/Connexion.php");

        $_SESSION['profil'] = array();

        if($resultat > 0) {
            $date = $resultat[0]['DateMaxJeton'];

            if($date > date('Y-m-d h:i:s', time())) {
                $_SESSION['profil'] = $resultat[0];
                return true;
            }
        }
    }
    return false;
}
