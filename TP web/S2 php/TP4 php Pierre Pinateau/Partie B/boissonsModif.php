<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
<?php
$quantif = 0;
$quantif2 = 0;
$quantif3 = 0;

include "connexion.php";
    foreach ($_GET as $key => $value) {
if ($key == "<br>quantif</br>" || $key == "quantif2" || $key == "quantif3") {
  $quantif = $value;
  $quantif2 = $value;
  $quantif3 = $value;
  if ($quantif==0 && $quantif2==0) {
    $quantif = $quantif3;
  }
  else {
    $quantif = $quantif2;
  }
}
if ($key == "df") {
  $id = $value;
}
    }



if ($quantif!=0) {
  $quantif = intval($quantif);
  $id=intval($id);
$requete1 = "UPDATE `produit` SET UnitesStock=$quantif WHERE RefProduit=$id";

      $result1 = mysqli_query($link,$requete1);

  if ( $result1 == FALSE ) {
     echo "<p>Erreur d'exécution de la requete</p>" ;
     echo mysqli_errno($link) . ": " . mysqli_error($link). "\n";
      die();
    }
    else {
      echo "Le stock de la boisson a bien été modifié à $quantif<br><br>";
      echo "Pour vous en assurer, dans l'onglet sql tapez : SELECT NomProduit, UnitesStock, RefProduit FROM `produit` WHERE  RefProduit=$id";
    }
  }


  else {
$requete = "SELECT RefProduit, NomProduit, UnitesStock,PrixUnitaire FROM produit WHERE CodeCategorie =1";

  $result = mysqli_query($link,$requete);

  if ( $result == FALSE ) {
     echo "<p>Erreur d'exécution de la requete</p>" ;
     echo mysqli_errno($link) . ": " . mysqli_error($link). "\n";
      die();
    }
while ($row = mysqli_fetch_assoc($result))
{
  if ($row["RefProduit"]==1 || $row["RefProduit"]==2 || $row["RefProduit"]==39) {
    // code...
    echo "<option value='" . $row['RefProduit'] . "'>" . $row["NomProduit"]. "</option>" ;
  }
}

      mysqli_close($link);
      //8 Modification du stock (liste déroulante dynamique)
}
if ($quantif2!=0 || $quantif3!=0) {
//Démarreunenouvellesessionoureprendunesessionexistante
session_start();//destructiondesvariablesdesession
unset($_SESSION["auth"]);unset($_SESSION["nom"]);//destructiondelasession
echo "</br></br>Vous avez été déconecté De lA sEssIon";
session_destroy();}
?>
  </body>
</html>
