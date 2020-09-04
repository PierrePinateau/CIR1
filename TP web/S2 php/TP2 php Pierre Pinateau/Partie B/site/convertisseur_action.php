<!DOCTYPE html>
<html lang="fr">
  <head>
    <meta charset="utf-8">
    <title> convert Action </title>
    <link rel="stylesheet" href="page.css">
  </head>

  <body>
    <?php include "entete.php" ?>
    <div class="navcorps">

    <?php
    if (empty($_POST['money']) || empty($_POST['type'])) {
      echo "Rentrez des valeurs ici : ../convertisseur.php";
    }
    else {
      $money= $_POST['money'];
      if ($_POST['type']=="euro") {
        echo "$money". "€ fait : ". $money*1.1 ."$";
      }
      else {
        echo "$money\$ fait : ". $money*0.9 ."€";
      }
    }

    ?>
  </div>

  <?php include "pieddepage.php" ?>
  </body>
</html>
