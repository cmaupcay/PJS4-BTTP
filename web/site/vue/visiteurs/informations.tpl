<!DOCTYPE html>
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

<body style="background-color:#003459">

<div class="container-fluid banner">
		<div class="row">
			<div class="col-md-12">
			<nav class="navbar navbar-md">
				
				<ul class="nav">
						<li class="nav-item" style="padding-left:10%; padding-top:0%">
						<a class="navbar-brand" href="?controle=visiteurs&action=accueil"><img alt="Brand" src="./vue/logo.png" style="width:140px"></a>
						</li>
				</ul>
				

					<ul class="nav" style="padding-right:0%; padding-top:0%">
						<li class="nav-item">
							<a class="nav-link" href="?controle=visiteurs&action=produits">Produits</a>
						</li>
						<li class="nav-item">
							<a class="nav-link" href="?controle=visiteurs&action=marketplace">Marketplace</a>
						</li>
						<li class="nav-item">
							<a class="nav-link" href="?controle=visiteurs&action=informations">Informations</a>
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

		<h2 style="text-align:center; padding-top:3%; padding-bottom:3%"> Informations </h2>

		<div class="container bg-light" style="padding-top:6%;">
		
			<h3 style="padding-left:7%; color:#003459"> Au fait, c'est quoi, BTTP ?</h3>
			<br>
			<p style="padding-left:5%; padding-right:5%; color:black">BTTP est un système d’inter opérabilité mobile - PC qui vous permet, à partir de votre smartphone, d’exécuter des scripts sur votre PC de destination à distance. 
				En effet, il suffit d’avoir téléchargé l’application mobile et d’avoir un ordinateur distant allumé pour envoyer des requêtes et exécuter des scripts à distance.
				De nos jours, de plus en plus de personnes possèdent au moins deux appareils électroniques et l’inter opérabilité des systèmes est rarement assurée 
				si les deux appareils ne sont pas de la même marque.
			</p>
			<br>
			<p style="padding-left:5%; padding-right:5%; color:black">La particularité de BTTP est sa sécurité. En effet, les messages échangés sont cryptés. 
				Ils passent par un terminal de contrôle qui a le rôle d’intermédiaire dans ce système. 
				Il s’assure notamment que l’émetteur est bien authentique.  Ainsi, vous pouvez exécuter des scripts de manière sécurisée.
				Le but de notre projet était de rendre possible l'exécution de script à distance depuis un smartphone. On voulait rendre notre système accessible au grand public, et de ne pas se limiter aux développeurs. Notre site permet de rendre notre système plus accessible et facile d'utilisation.
			</p>

			<h3 style="padding-top:3%; padding-left:8%; color:#003459"> Qui sommes nous ? </h3>
			<br>
			<p style="padding-left:5%; padding-right:5%; color:black"> Nous sommes une équipe de 5 étudiants en DUT Informatique à l’IUT de Paris Rives de Seine. Pour notre dernier projet, nous avons choisi de développer ce projet ambitieux. 
			En effet, nous avions 7 semaines pour le développer, sachant que notre application compote la conception du protocole d'échange de messages, la conception de l'application ainsi que le site web. Clément Mauperon et Luca Randazzo ont principalement travaillé sur la conception du protocole (complétez moi).
			Robin Landais était chargé du développement de notre applciation. Elle nous permet d'envoyer des scripts à un PC distant.
			Sara Zaibet et Clément Prost ont développé le site web, qui sert de site vitrine à notre projet. En effet, sur notre site, vous pouvez consulter la marketplace contenant les scripts publiques. Vous pouvez les télécharger ou consulter leur code source associé.
			Si vous avez un compte, vous pouvez consulter vos appareils, les supprimer, et consulter leurs scripts associés. Vous avez la possibilité de changer votre mot de passe également.
			</p>

			<h3 style="padding-top:3%; padding-left:8%; color:#003459"> Quel futur pour BTTP ? </h3>
			<br>
			<p style="padding-left:5%; padding-right:5%; padding-bottom:6%; color:black"> Notre système peut être utilisé dans le domaine de l'IOT. En effet, on pourrait contrôler des objets connectés depuis notre application. Par exemple, on pourrait envoyer une requête à une lampe connectée pour que celle-ci change de couleur.
			</p>

		</div>
</div>
</body>
</html>