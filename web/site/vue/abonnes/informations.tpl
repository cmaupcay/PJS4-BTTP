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
						<a class="navbar-brand" href="?controle=abonnes&action=accueil"><img alt="Brand" src="./vue/logo.png" style="width:140px"></a>
					</li>
				</ul>
					<ul class="nav" style="padding-right:0%; padding-top:0%">
						<li class="nav-item">
							<a class="nav-link" href="?controle=abonnes&action=profil">Profil</a>
						</li>
						<li class="nav-item">
							<a class="nav-link" href="?controle=abonnes&action=appareils"> Appareils </a>
						</li>
						<li class="nav-item">
							<a class="nav-link" href="?controle=abonnes&action=marketplace"> Marketplace </a>
						</li>
						<li class="nav-item">
							<a class="nav-link" href="?controle=abonnes&action=informations">Informations</a>
						</li>
						<li class="nav-item">
							<a class="nav-link" href="?controle=abonnes&action=deconnexion">Déconnexion</a>
						</li>
					</ul>
				</nav>
			</div>
        </div>

		<h2 style="text-align:center; padding-top:3%; padding-bottom:3%"> Informations </h2>
		<div class="container bg-light" style="padding-top:6%;">
		
			<h3 style="padding-left:7%; color:#003459"> Au fait, c'est quoi, BTTP ?</h3>
			<br>

			<p style="padding-left:5%; padding-right:5%; color:black"> Vous avez sûrement dû entendre parler de SSH ou encore de TeamViewer ou AnyDesk. Ou vous êtes peut être amateur en informatique, mais peut importe vos compétences dans le domaine, nous vous proposons d'exécuter des actions sur votre PC à distance à partir de votre smartphone.  
				BTTP est un système d’inter opérabilité mobile - PC qui vous permet, à partir de votre smartphone, d’exécuter des scripts sur votre PC de destination à distance. De nos jours, de plus en plus de personnes possèdent au moins deux appareils électroniques et l’inter opérabilité des systèmes est rarement assurée 
				si les deux appareils ne sont pas de la même marque. Il suffit d’avoir téléchargé l’application mobile et d’avoir un ordinateur distant allumé pour envoyer des requêtes et exécuter des scripts à distance.
			<br>
			<br>
				L'un des nombreux points forts de BTTP est sa sécurité. En effet, les messages échangés sont cryptés. 
				Ils passent par un terminal de contrôle qui a le rôle d’intermédiaire dans ce système. 
				Il s’assure notamment que l’émetteur est bien authentique.  Ainsi, vous pouvez exécuter des scripts de manière sécurisée.
				Le but de notre projet était de rendre possible l'exécution de script à distance depuis un smartphone. On voulait rendre notre système accessible au grand public, et de ne pas se limiter aux développeurs. Notre site permet de rendre notre système plus accessible et facile d'utilisation.
			</p>

			<h3 style="padding-top:3%; padding-left:8%; color:#003459"> Qui sommes nous ? </h3>
			<br>
			<p style="padding-left:5%; padding-right:5%; color:black"> Nous sommes une équipe de 5 étudiants en DUT Informatique à l’IUT de Paris Rives de Seine. Pour notre dernier projet, nous avons choisi de développer ce projet ambitieux. 
			En effet, nous avions 7 semaines pour le développer, sachant que notre application comporte la conception du protocole d'échange de messages, la conception de l'application ainsi que le site web. 
			Clément Mauperon et Luca Randazzo ont principalement travaillé sur la conception du protocole, qui définit la manière dont le client et le serveur vont communiquer. Ils ont également 
			Robin Landais était chargé du développement de notre applciation. Elle nous permet d'envoyer des scripts à un PC distant, elle joue donc le rôle de client. A partir de l'application vous pouvez exécuter des scripts sur votre PC distant, consulter les scripts publiques de la marketplace ou encore consulter votre profil pour y modifier vos informations personnelles.
			Sara Zaibet et Clément Prost ont développé le site web, qui sert de site vitrine à notre projet. En effet, sur notre site, vous pouvez consulter la marketplace contenant les scripts publiques. Vous pouvez les télécharger ou consulter leur code source associé.
			Si vous avez un compte, vous pouvez consulter vos appareils, les supprimer, et consulter leurs scripts associés. Vous avez la possibilité de changer votre mot de passe également. Le site sert principalement à faire jouer le rôle de Client à un PC si l'on ne dispose pas de l'application mobile.
			</p>

			<h3 style="padding-top:3%; padding-left:8%; color:#003459"> Nos valeurs et nos convictions</h3>
			<br>
			<p style="padding-left:5%; padding-right:5%; padding-bottom:6%; color:black"> Nous avions pour objectif de développer un système qui serait l'équivalent de SSH, mais pour le grand public. Nous ne visons pas forcément les développeurs ou les experts de l'informatique. Au contraire, grâce à notre système, chaque utilisateur pourra définir sa propre utilisation de BTTP.
			Grâce à nos scripts publiques disponibles sur la marketplace, vous pourrez facilement trouver les actions dont vous avez besoin. L'Open Source est une valeur qui nous est chère, nous sommes convaincus que notre projet s'améliorera au fur et à mesure des contributions. 
			Par ailleurs, le choix de l'open source garantit la sécurisation de notre système, soit une autre de nos valeurs essentielles. En effet, non suelement nous nous basons sur des technologies sécurisées, puissantes et fiables (PGP), mais nous avons surtout adopté un Privacy by Design qui rend notre système parfaitement sécurisé.
			<br>
			<br>
			Nous espérons que le projet vous plaît, si c'est le cas n'hésitez pas à le partager ou à contribuer à son évolution !
			</p>

		</div>
</div>
</body>
</html>