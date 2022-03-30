<?php

$RACINE = "C:\wamp64\www\PJS4\web\site";

    require($RACINE . '/modele/terminal.php');
    if(isset($_GET["idTerminal"])){
        supprimer_terminal($_GET["idTerminal"]);
    }
