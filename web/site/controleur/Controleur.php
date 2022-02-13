<?php

    include_once 'modele/Modele.php';

    /**
     * Extension de Modele.php
     * Controlleur facilement paramétrés par depuis_ini de Moele 
     * dans le constructeur de Controleur
     */
    abstract class _Controleur {

        /**
         * Construction depuis un fichier ini
         */
        public function __controleur(string $fichier_ini) {
            $this->depuis_ini($fichier_ini);
        }
    }

    /**
     * Classe de base des controleurs
     */
    public class Controleur extends _Controleur {

        public function __construct(?string $fichier_ini = null) {
            if($fichier_ini == null) $fichier_ini = $this->ini();
        }

        /**
         * définit le fichier ini de base pour paramétrer le controleur
         */
        public function ini() : ?string { return null; }
        public function informations(): array { return []; }

        /**
         * définit l'action à exécuter lorsque le controleur est appelé
         */
        abstract public function executer(
            array &$server, array &$session, array &$post, array &$get, array &$params,
            BD &$_BD, Authentification &$_AUTH, Routeur &$_ROUTEUR, ?JetonAuthentification &$_JETON = null);


    }



?>