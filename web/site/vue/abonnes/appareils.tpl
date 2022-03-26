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
    <link rel="stylesheet" type="text/css" href="style.css">

</head>

<body>

<div class="container-fluid banner" style="background-color:#003459">
		<div class="row">
			<div class="col-md-12">
				<nav class="navbar navbar-md">
					<a class="navbar-brand" href="?controle=abonnes&action=accueil"> BTTP </a>
					<ul class="nav">
						<li class="nav-item">
							<a class="nav-link" href="?controle=visiteurs&action=produits">Profil</a>
						</li>
                        <li class="nav-item">
							<a class="nav-link" href="?controle=visiteurs&action=produits"> Marketplace </a>
						</li>
						<li class="nav-item">
							<a class="nav-link" href="?controle=visiteurs&action=infos">Infos</a>
						</li>
                        <li class="nav-item">
							<a class="nav-link" href="?controle=abonnes&action=deconnexion">Deconnexion</a>
						</li>
					</ul>
				</nav>
			</div>
        </div>

        <h2 class="display-5 text-center" style="padding-top:5%"> Voici tous vos appareils </h2>

        <br>
    <div class="container py-5 bg-light"> 

        <div class="row">

            <div class="col-md-4 col-sm-4">
                <div class="card mb-4 shadow-sm">
                    <div class="card-body">
                        <!--TODO : utiliser une fonction php de modèle qui récupère tous les terminaux d'un utilisateur puis les afficher avec un foreach -->
                        <p class="card-text"> Nom : PC1 </p>
                        <p class="card-text"> Etat : Disponible </p>

                        <button type="button" class="btn btn-sm btn-outline-secondary">
                            Supprimer
                        </button>
                        <button type="button" class="btn btn-sm btn-outline-secondary">
                            Scripts
                        </button>
                    </div>
                </div>
            </div>
            <div class="col-md-4 col-sm-4">
                <div class="card mb-4 shadow-sm">
                    <div class="card-body">
                        <!--TODO : utiliser une fonction php de modèle qui récupère tous les terminaux d'un utilisateur puis les afficher avec un foreach -->
                        <p class="card-text"> Nom : PC2 </p>
                        <p class="card-text"> Etat : Indisponible </p>

                        <button type="button" class="btn btn-sm btn-outline-secondary">
                            Supprimer
                        </button>
                        <button type="button" class="btn btn-sm btn-outline-secondary">
                            Scripts
                        </button>
                    </div>
                </div>
            </div>

            <div class="col-md-4 col-sm-4">
                <div class="card mb-4 shadow-sm">
                    <div class="card-body">
                        <!--TODO : utiliser une fonction php de modèle qui récupère tous les terminaux d'un utilisateur puis les afficher avec un foreach -->
                        <p class="card-text"> Nom : PC3 </p>
                        <p class="card-text"> Etat : Disponible </p>

                        <button type="button" class="btn btn-sm btn-outline-secondary">
                            Supprimer
                        </button>
                        <button type="button" class="btn btn-sm btn-outline-secondary">
                            Scripts
                        </button>
                    </div>
                </div>
            </div>
    </div>

</body>

</html>