<!DOCTYPE html>

<html>

<head>
  <meta charset="utf-8">
  <link rel="stylesheet" type="text/css"
    href="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.3.1/css/bootstrap.min.css">
  <link rel="stylesheet" type="text/css"
    href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
  <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.3.1/js/bootstrap.bundle.min.js"></script>
  <link href="https://cdnjs.cloudflare.com/ajax/libs/magnific-popup.js/1.1.0/magnific-popup.min.css" rel="stylesheet" />
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
  <title>Accueil</title>

  <link rel="stylesheet" type="text/css" href="./vue/style.css">
</head>

<body>
  <div class="bg">

    <header class="header">
      <nav class="navbar navbar-expand-lg fixed-top py-3 fill">
        <div><a href="index.php?controle=visiteurs&action=accueil"
            class="nav-link text-uppercase font-weight-bold">Logo-pour-accueil</a></div>
        <div class="container">
          <button type="button" data-toggle="collapse" data-target="#navbarSupportedContent"
            aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation"
            class="navbar-toggler navbar-toggler-right"><i class="fa fa-bars"></i></button>

          <div id="navbarSupportedContent" class="collapse navbar-collapse">
            <ul class="navbar-nav ml-auto">
              <li class="nav-item active"><a href="index.php?controle=visiteurs&action=accueil"
                  class="nav-link text-uppercase font-weight-bold">ACCUEIL</a></li>
              <li class="nav-item"><a href="index.php?controle=abonnes&action=connexion"
                  class="nav-link text-uppercase font-weight-bold">CONNEXION</a></li>
              <li class="nav-item"><a href="index.php?controle=visiteurs&action=inscription"
                  class="nav-link text-uppercase font-weight-bold">INSCRIPTION</a></li>
            </ul>
          </div>
        </div>
      </nav>
    </header>
    <br><br><br>
    <div class="logo text-center">
      <img src="logo.png" alt="..." class="img-thumbnail">
    </div>
    <div class="o-bg">
      <div class="presentation">
        <h2><a href="marketplace.html">Scripts qui pourraient vous interesser : </a></h2>
        <a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a> <img src="e.bmp" alt="..."
          class="img-thumbnail"></a> <a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a>
        <button type="button" class="btn btn-info" data-toggle="collapse" data-target="#slide1">montrer plus de
          scripts</button>
        <div id="slide1" class="collapse">
          <a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a> <a href="script"><img src="e.bmp"
              alt="..." class="img-thumbnail"></a><a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a>
          <br>
          <a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a> <a href="script"><img src="e.bmp"
              alt="..." class="img-thumbnail"></a><a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a>
        </div>
      </div>
      <div class="presentation">
        <h2><a href="ordi.html">Gerer ordinateurs connectés : </a></h2>
        <a href="ordi"><img src="e.bmp" alt="..." class="img-thumbnail"></a> <a href="ordi"><img src="e.bmp" alt="..."
            class="img-thumbnail"></a> <a href="ordi"><img src="e.bmp" alt="..." class="img-thumbnail"></a>
        <button type="button" class="btn btn-info" data-toggle="collapse" data-target="#slide2">montrer plus de
          scripts</button>
        <div id="slide2" class="collapse">
          <a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a> <a href="script"><img src="e.bmp"
              alt="..." class="img-thumbnail"></a><a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a>
          <br>
          <a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a> <a href="script"><img src="e.bmp"
              alt="..." class="img-thumbnail"></a><a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a>
        </div>
      </div>
      <div class="presentation">
        <h2><a href="scripts.html">Scripts en votre possession : </a></h2>
        <a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a> <a href="script"><img src="e.bmp"
            alt="..." class="img-thumbnail"></a> <a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a>
        <button type="button" class="btn btn-info" data-toggle="collapse" data-target="#slide3">montrer plus de
          scripts</button>
        <div id="slide3" class="collapse">
          <a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a> <a href="script"><img src="e.bmp"
              alt="..." class="img-thumbnail"></a><a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a>
          <br>
          <a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a> <a href="script"><img src="e.bmp"
              alt="..." class="img-thumbnail"></a><a href="script"><img src="e.bmp" alt="..." class="img-thumbnail"></a>
        </div>
      </div>
    </div>
    <!--<form action="index.php?controle=visiteurs&action=inscription" method="POST">
      <h2 class="text-center"> Inscription </h2>

      <div class="form-group">
      <p><input name="Pseudo" type="text" placeholder="Pseudo"  class="form-control" autocomplete="off" required></p>
      </div>

      <div class="form-group">
      <p><input name="Mdp" type="password" placeholder="Mdp" class="form-control" autocomplete="off" required></p>
      </div>

      <div class="form-group">
      <input type="submit" class="btn-primary btn-block" value="S'inscrire !">
      </div>

    </form>-->

    <br><br><br><br><br><br><br><br><br>
  </div>
</body>

<style>
  body {
    background-image: url("code-1486361_960_720.png");
    background-repeat: no-repeat;
  }

  .bg {
    height: 100%;
  }

  .presentation {
    margin: 25px;
    background-color: rgb(250, 250, 210);
  }

  .header nav {
    border: 1px solid black;
    background-color: rgb(250, 250, 210);
  }

  .login-form {
    width: 340px;
    margin: 50px auto;
  }

  .login-form form {
    margin-bottom: 15px;
    background: #f7f7f7;
    box-shadow: 0px 2px 2px rgba(0, 0, 0, 0.3);
    padding: 30px;
  }

  .login-form h2 {
    margin: 0 0 15px;
  }

  .form-control,
  .btn {
    min-height: 38px;
    border-radius: 2px;
  }

  .btn {
    font-size: 15px;
    font-weight: bold;
  }
</style>

<!-- </html> -->