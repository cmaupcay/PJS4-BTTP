<?php

/**
 * Pas besoin ? pas de cookies dans la base
 */

    function connexion(){
    require '../modele/connexion.php';

    return verif_utilisateur($_POST['pseudo'], $_POST['mdp']);
    }

?>