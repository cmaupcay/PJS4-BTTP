<?php
//Le contenu de ce fichier à été déplacé dans General.php afn de ne pas avoir a require plusieurs fichiers dans l'index

    function accueil() {

       //cette fonction affichera les scripts disponibles de la marketplace
       // scripts_disponibles($scripts);

       require('./vue/visiteurs/accueil.tpl');
    }

    function inscription() {
        require_once('./modele/inscription.php');

        $pseudo = isset($_POST['pseudo'])?($_POST['pseudo']):'';
        $mdp = isset($_POST['mdp'])?($_POST['mdp']):'';
        $mdp2= isset($_POST['mdp2'])?($_POST['mdp2']):'';


        $msg ="";

        if(count($_POST) < 3) {
            require('./vue/visiteurs/inscription.tpl');
        } else {
            if(verif_inscription($pseudo)) {

                $msg = "compte déjà existant";

                echo $msg;
                
                require('./vue/visiteurs/inscription.tpl');
            } else if($mdp != $mdp2){
                
                $msg = "Resaisissez votre mot de passe";

                echo $msg;

                require('./vue/visiteurs/inscription.tpl');
            }

            else {

                insertion_bd($pseudo, $mdp);
                
                require_once('./modele/connexion.php');

                verif_utilisateur($pseudo, $mdp, $resultat);

                $_SESSION['profil'] = $resultat[0];

                //require('./controle/connexion.php');

                $url = "?controle=abonnes&action=accueil";

                header("Location:" . $url);
            }
        }
    }

    function connexion() {
        require_once('./modele/connexion.php');
    
        //Ici on met ce dont on a besoin afin de relier le modele et la vue
    
        require_once('./vue/connexion.tpl');
    }

    function marketplace() {

        require_once './modele/marketplace.php';

        scripts_publiques($scripts);

        require './vue/marketplace.tpl';


        $s = "a";
        echo '<div class="container py-5 bg-light">';
        echo '<div class="row">';

            
                foreach($scripts as $script) {
                    echo('<div class="col-md-4 col-sm-4">');
                    echo('<div class="card mb-4 shadow-sm">');
                    echo('<div class="card-body"');

                    foreach($script as $scr => $s) {
                        $str = '';
                        switch($s) {
                            case "nom" : 
                                $str = '<p class="card-text"> Nom : ' . $s . '</p>';
                                break;
                            case "publication" :
                                $str = '<p class="card-text"> Date de publication : ' . $s . '</p>';
                                break;
                            case "version" :
                                $str ='<p class="card-text"> Version : ' . $s . '</p>';
                                break;
                        }
                        echo $str;
                    }
                    echo '<button type="button" class="btn btn-sm btn-outline-secondary"> Télécharger </button>'; //pq ça s'affiche pas ??? t bizarre
                    echo '<button type="button" class="btn btn-sm btn-outline-secondary"> Code source </button>';
                    echo '</div>';
                    echo '</div>';
                    echo '</div>';

                }
        echo '</div>';
        echo '</div>';

    }
