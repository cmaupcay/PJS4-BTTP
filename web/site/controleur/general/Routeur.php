<?php

    require_once 'controleur/Controleur.php';

    class Routeur {
        public function informations(): array{
            return[
                'index', 'err', 'css', 'js', 'media', 'controle', 'args',  
            ];
        }

        //PARAMETRES
        protected $index; //nom de la vue par défaut
        protected function getIndex() : string { return $this->index; }

        protected $err; //clé d'indication d'une erreur
        protected function getErr() : string { return $this->err; }

        protected $css; //clé d'appel d'un fichier css
        protected function getCss() : string { return $this->css; }

        protected $js; // clé d'appel d'un fichier js
        protected function getJs() : string { return $this->js; }

        protected $media; //clé d'appel d'un fichier multimédia
        public function getMedia() : string { return $this->media; }

        protected $controle; //liste des associations vue / controleur
        protected function getControle() : string { return $this->controle; }

        protected $args; //liste des vues acceptants des arguments 

        protected function est_URI_argumente(string $uri) : ?string {
            if($this->args !== null) {
                $longueur = strlen($uri);
                foreach($this->args as $vue) {
                    if($longueur > strlen($vue) +1 && strpos($uri, $vue) === 0) {
                        return $vue;
                    }
                }
            }
        }

        public static function extraire_arguments(string $uri, string $vue) : array {
            $args = explode('/', substr($uri, strlen($vue) + 1));
            if(strlen($args[0] === 0))
                return [];
            
            //sécurisation injections SQL
            foreach($args as &$arg) {
                $arg=urldecode($arg);
                $arg= str_replace('-', ' ', $arg);
                $arg = str_replace(['"', '\'', ';'], '', $arg);
                $arg = utf8_encode($arg);
            }
            return $args;
        }

        //APPEL AUX RESSOURCES
        //chargement d'un fichier
        private function charger_fichier(string $fichier, ?string $type=null) {
            if(strlen($fichier) > 0 && $fichier[-1] !== '/' && file_exists($fichier)) {

                //mime = type de la page
                if($type === null)
                    header('Content-type: ' . mime_content_type($fichier));
                else
                    header('Content-type: ' . $type);
                include $fichier;
                die();
            }
        }

        //Chargement d'un fichier css
        private function charger_css(string $fichier) {
            // ???
            $fichier = 'vue/Style' . $fichier . '.css';
            $this->charger_fichier($fichier, 'text/css');
        }

        // Chargement d'un fichier JavaScript
        private function charger_js(string $fichier)
        {
            // Les fichiers JavaScript ne sont chargés que depuis la racine '/js/' !
            // L'extension de fichier '.js' ne doit pas être spécifiée.
            $fichier = 'js/' . $fichier . '.js';
            $this->charger_fichier($fichier, 'text/javascript');
        }

        // Chargement d'un fichier multimédia
        private function charger_media(string $fichier)
        {
            // Les médias ne sont chargés que depuis la racine '/vue/media/' !
            // L'extension de fichier doit être spécifiée.
            $fichier = 'media/' . $fichier;
            $this->charger_fichier($fichier);
        }

        //ROUTAGE

        private function appel_ressource(string $uri) : string {
            $var = explode('=', substr($uri, 1), 2);
            if(count($var) === 2) {
                switch($var[0]) {
                    //spécifisation de l'erreur
                    case $this->err:
                        //retourne le couple <cle_erreur>/<nom_erreur>
                        return implode('/', $var);
                    //chargement d'un fichier multimédia
                    case $this->media:
                        $this->charger_media($var[1]);
                        break;
                    //chargement d'un fichier css
                    case $this->css:
                        $this->charger_css($var[1]);
                        break;
                    //chargemet d'un fichier js
                    case $this->js:
                        $this->charger_js($var[1]);
                        break;
                    //Type inconnu : rdirection page d'erreur
                    default:
                        break;
                }
            }
            return $this->err . '=404';
        }

        public function definir_vue(string $uri, array &$params) : string {
            $uri = substr($uri, 1);
            if(strlen($uri) === 0) return $this->index;

            if($uri[-1] === '/') {
                $uri = substr($uri, 0, -1);
            } else {
                if($uri[0] === '?') 
                    return $this->appel_ressource($uri); //à coder
                return $this->err . '=404';
            }
            // Vérifier si c'est une vue argumentée
            if (($vue = $this->est_URI_argumente($uri)) !== null) {
                // Extraire les arguments de l'URI et les ajouter les arguments de l'URI au tableau des paramètres
               // $params[URI] = self::extraire_arguments($uri, $vue); ça marche pas
                // Retourner la vue ayant acceptée les arguments
                return $vue;
            }
            // APPEL DE RESSOURCE
            // Retourner la vue définie
            return $uri;
            
        }

        public function charger_controleurs(string $vue) : array {
            //par défaut aucun controleur n'est chargé
            $controleur_general = [];
            $controleur_vue = [];

            if(isset($this->controle[0])) 
                $controleur_general = explode(',', $this->controle[0]);
            if(isset($this->controle[$vue])) 
                $controleur_vue = explode(',', $this->controle[$vue]);
            //fusionner les deux listes de noms de controleurs obtenus et supprimer les doublons
            $controleurs_noms = array_unique(array_merge($controleur_general, $controleur_vue));

            //Transformer la liste de nom en liste d'objet Controleur
            $controleurs = [];
            
            foreach($controleurs_noms as $nom) {
                //Transformer le nom de controlleur en nom de fichier
                $fichier = 'controleur/' . $nom . '.php';
                
                try {
                    //On vérifie que le fichier existe
                    if(!file_exists($fichier))
                        throw null;
                    //On inclut le fichier
                    require_once $fichier;
                    //On instancie le controlleur dans le tableau de noms
                    $controlleurs = new $noms();
               
                } catch(\Throwable $th) {
                    //si le controleur est introuvable on lève un erreur
                    throw new Error('Le controleur "' . $nom . '" est introuvable');
                
                }
            }

            return $controlleurs;

        }

        //Redirection vers une vue
        public function redirection(?string $vue) {
            //si $vue === null, la redirection se fera sur la vue par défaut
            header('Location: /' . (is_null($vue) ? '' : $vue . '/') );

            die('Redirection ...');
        }
    }
?>