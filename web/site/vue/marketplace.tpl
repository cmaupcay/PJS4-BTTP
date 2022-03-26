<html>
<head>
    <meta charset="UTF-8">

    <title> Bienvenue </title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <link rel="stylesheet" type="text/css" href="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.3.1/css/bootstrap.min.css">
    <link rel="stylesheet" type="text/css" href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.3.1/js/bootstrap.bundle.min.js"></script>
    <link href="https://cdnjs.cloudflare.com/ajax/libs/magnific-popup.js/1.1.0/magnific-popup.min.css" rel="stylesheet" />
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
    <link rel="stylesheet" type="text/css" href="./vue/style.css">

    <style>
 body{
	margin:0;
	padding:0;
	background:#fff;
	font-family: 'Raleway',sans-serif;
	color: #fff;
	}
	.banner{
		height: 100vh;
		width: 100%;
		background-color:rgb(14, 0, 41);
		background-position: top;
		background-size:cover;
		/*background-attachment: fixed;*/
		background-repeat: no-repeat;
	}
	.banner .navbar{
		margin-top:2%;
	}
	.banner .navbar-brand{
		color: #fff;
		font-size:1.8em;
		font-weight: 700;
		margin-left: 10%;
	}
	.banner .nav{
		margin-right:5%; 
	}
	.banner .nav li a{
		color:#aaa;
		font-size: 1.2em;
	}
	.banner .info{
		margin-top:15%;
		transform: translateY(-15%);
	}
	.banner .info h1{
		font-size: 2.5em;
		font-weight: 700;
		color: #fff;
		letter-spacing: 2px;
	}
	.banner .info p{
		font-size: 2em;
		font-weight: 500;
		color: #aaa;
		letter-spacing: 2px;
	}
	.banner .info a{
		margin-left:50%;
		transform: translateX(-50%);
		color: #fff;
		background: #e91d43;
		padding:10px 20px; 
		font-size: 2em;
		font-weight: 600;
	}
	.banner .info a:hover{
		background: #e91e63;
	}
    </style>

</head>

<body>

<div class="container-fluid banner">
		<div class="row">
			<div class="col-md-12">
				<nav class="navbar navbar-md">
					<a class="navbar-brand" href="?controle=visiteurs&action=accueil"> BTTP </a>
					<ul class="nav">
						<li class="nav-item">
							<a class="nav-link" href="?controle=visiteurs&action=produits">Produits</a>
						</li>
						<li class="nav-item">
							<a class="nav-link" href="?controle=visiteurs&action=infos">Infos</a>
						</li>
						<li class="nav-item">
							<a class="nav-link" href="?controle=visiteurs&action=connexion">Connexion</a>
						</li>
						<li class="nav-item">
							<a class="nav-link" href="?controle=visiteurs&action=inscription">Inscription</a>
						</li>
					</ul>
				</nav>
			</div>
        </div>

        <h2 class="display-5 text-center" style="padding-top:5%"> Recherchez les scripts qui vous intéressent </h2>

        <div class="input-group mb-3" style="padding-top:3%; padding-bottom:5%">
            <input type="text" class="form-control" placeholder="Recherchez des scripts ..." aria-label="Recherchez des scripts ..." aria-describedby="basic-addon2">
                <div class="input-group-append">
                    <button class="btn btn-outline-secondary" type="button" style="background-color:blue; width:10em"> Rechercher </button>
                 </div>
        </div>

        <br>

    <div class="container py-5 bg-light"> 

        <div class="row">

            <?php 
                foreach($scripts as $script) {
                    echo '<div class="col-md-4 col-sm-4">';
                    echo '<div class="card mb-4 shadow-sm">';
                    echo '<div class="card-body"';

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
                    }

                    echo '<button type="button" class="btn btn-sm btn-outline-secondary"> Télécharger </button>'; //pq ça s'affiche pas ??? t bizarre
                    echo '<button type="button" class="btn btn-sm btn-outline-secondary"> Code source </button>';
                    echo '</div></div>';

                }
            ?>
        </div>
            <!--
<div class="col-md-4 col-sm-4">
                <div class="card mb-4 shadow-sm">
                    <div class="card-body">

                        <p class="card-text"> Nom : Téléchargement </p>
                        <p class="card-text"> Catégorie : Téléchargement </p>
                        <p class="card-text"> Auteur : saralaresta </p>
                        <p class="card-text"> Version : 1.0.2 </p>

                        <button type="button" class="btn btn-sm btn-outline-secondary">
                            Code source
                        </button>
                        <button type="button" class="btn btn-sm btn-outline-secondary">
                            Télécharger
                        </button>

                    </div>
                </div>
            </div>

            <div class="col-md-4 col-sm-4">
                <div class="card mb-4 shadow-sm">
                    <div class="card-body">
                        <p class="card-text"> Nom : mini drive </p>
                        <p class="card-text"> Catégorie : raccourci </p>
                        <p class="card-text"> Auteur : clément le boss </p>
                        <p class="card-text"> Version : 3.0 </p>
                        
                        <button type="button" class="btn btn-sm btn-outline-secondary">
                            Code source
                        </button>
                        <button type="button" class="btn btn-sm btn-outline-secondary">
                            Télécharger
                        </button>

                    </div>
                </div>
            </div>

            <div class="col-md-4 col-sm-4">
                <div class="card mb-4 shadow-sm">
                    <div class="card-body">

                        <p class="card-text"> Nom : Gestionnaire de mdp </p>
                        <p class="card-text"> Catégorie : Notification </p>
                        <p class="card-text"> Auteur : Lucastor </p>
                        <p class="card-text"> Version : 4.0 </p>

                        <button type="button" class="btn btn-sm btn-outline-secondary">
                            Code source
                        </button>
                        <button type="button" class="btn btn-sm btn-outline-secondary">
                            Télécharger
                        </button>

                    </div>
                </div>
            -->
    </div>

</body>

</html>