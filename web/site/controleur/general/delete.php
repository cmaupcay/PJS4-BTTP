<?php

$RACINE = ".";

    require($RACINE . '/modele/terminal.php');
    if(isset($_GET["idTerminal"])){
        supprimer_terminal($_GET["idTerminal"]);
    }
