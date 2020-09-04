<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    <link rel="stylesheet" href="css/bleubleu.css">
    <title>Where is Bleubleu ?</title>




  </head>
  <body style="background-color: #36393f;color:white;">
    <?php
    session_start();
    //testd'existencedelavariabledesessionauth
    if(!isset($_SESSION["auth"])||$_SESSION["auth"]==0){
      //redirection
      header("location:formAcces.php");}

      include "connexion.php";
    ?>
    <div class="container">
        <div class="row">


        <div class="text col-sm-4 text-center">

        <form method="get" action="boissonsModif.php">
          <label for="diff">Boissons : </label>
          <select class="form-control form-control-lg" name="df">
          <?php

          $requete = "SELECT RefProduit, NomProduit, indisponible FROM produit WHERE CodeCategorie =1";
          $result = mysqli_query($link,$requete);

          if ( mysqli_num_rows($result) > 0)
          {
          while ($row = mysqli_fetch_assoc($result))
          {
            if (!$row['indisponible']) {
              // code...
              echo "<option value='" . $row['RefProduit'] . "'>" . $row["NomProduit"]. "</option>" ;
            }
            else {

              echo "<option style=\"color:orange;font-style: italic;\" value='" . $row['RefProduit'] . "'disabled>" . $row["NomProduit"]. "</option>" ;
            }
          }
          }
                mysqli_close($link);

          ?>
          </select>
          Quantité à modifier: <input class="form-control" type="number" name="quantif2" value="13">

    </div>
  <div class="form-group data col-sm-offset-1 col-sm-2 pt-3">
      Les boissons orange sont indisponible..
  </div>

        <div class="form-group col-sm-offset-1 col-sm-4">

    <button name="quantif" style="--content: 'Modifier   !';">
      <div class="left"></div>Modifier !
      <div class="right"></div>
    </button>
    </div>
</form>

        </div>
        <div class="row">
          <div class="col-sm-offset-5 col-sm-2 text-center" style="position:fixed;bottom:3%;">
          </div> </div>
    </div>































  <?php
    include "connexion.php";
  ?>
  <div class="container">
      <div class="row">


      <div class="text col-sm-4 text-center">

      <form method="get" action="boissonsModif.php">
        <label for="diff">Boissons : </label>
        <select class="form-control form-control-lg" name="df">
        <?php

        $requete = "SELECT RefProduit, NomProduit, indisponible FROM produit WHERE CodeCategorie =1";
        $result = mysqli_query($link,$requete);

        if ( mysqli_num_rows($result) > 0)
        {
        while ($row = mysqli_fetch_assoc($result))
        {
          if (!$row['indisponible']) {
            // code...
            echo "<option value='" . $row['RefProduit'] . "'>" . $row["NomProduit"]. "</option>" ;
          }
        }
        }
              mysqli_close($link);

        ?>
        </select>
        Quantité à modifier: <input class="form-control" type="number" name="quantif3" value="13">

  </div>
<div class="form-group data col-sm-offset-1 col-sm-2 pt-3">
    Les boissons pas affichées sont pas disponible..
</div>

      <div class="form-group col-sm-offset-1 col-sm-4">

  <button name="quantif" style="--content: 'Modifier   !';">
    <div class="left"></div>Modifier !
    <div class="right"></div>
  </button>
  </div>

      </div>
      <div class="row">
        <div class="col-sm-offset-5 col-sm-2 text-center" style="position:fixed;bottom:3%;">
        </div> </div>
  </div>



  </body>
</html>
