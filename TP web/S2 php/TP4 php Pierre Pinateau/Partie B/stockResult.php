<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
<?php
include "connexion.php";
    foreach ($_GET as $key => $value) {
if ($key == "quantif") {
  $quantif = $value;
}
    }


$requete = "SELECT numfournisseur, NomProduit, prixunitaire, unitesstock
FROM produit
where numfournisseur = 20
and CodeCategorie = 1";

  $result = mysqli_query($link,$requete);

  if ( $result == FALSE ) {
     echo "<p>Erreur d'exécution de la requete</p>" ;
     echo mysqli_errno($conn) . ": " . mysqli_error($link). "\n";
      die();
    }



      if( mysqli_num_rows($result)> 0)
      {
        while ($row = mysqli_fetch_assoc($result)){
          $stock = $row["unitesstock"];
        }}
$tot = $stock+$quantif;
$requete = "update produit set unitesstock=$tot where numfournisseur = 20 and CodeCategorie = 1";

  $result = mysqli_query($link,$requete);

  if ( $result == FALSE ) {
     echo "<p>Erreur d'exécution de la requete</p>" ;
     echo mysqli_errno($conn) . ": " . mysqli_error($link). "\n";
      die();
    }
 ?>
  </body>
</html>
