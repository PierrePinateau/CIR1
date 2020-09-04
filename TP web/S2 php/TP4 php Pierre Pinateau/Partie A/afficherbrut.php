<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>




<?php
include "connexion.php";
    $requete = "SELECT fournisseur.societe as nom, sum(prixunitaire*unitesstock)
    as total FROM produit inner join fournisseur
    on produit.numfournisseur = fournisseur.numfournisseur inner
    join categorie on produit.codecategorie = categorie.codecategorie WHERE
    categorie.Nomcategorie='Boissons' GROUP BY fournisseur.societe";

  $result = mysqli_query($link,$requete);

  if ( $result == FALSE ) {
     echo "<p>Erreur d'exécution de la requete</p>" ;
     echo mysqli_errno($conn) . ": " . mysqli_error($link). "\n";
      die();
    }
    else {
      echo "<p>SELECT a retourné " . mysqli_num_rows($result) . " lignes</p>" ;
    }


    if( mysqli_num_rows($result)> 0)
    {
      while ($row = mysqli_fetch_assoc($result)){
        /* constrution des lignes dynamiquement */
        echo $row["nom"] . " ";
        echo $row["total"] ;
        echo "</br>";
      }
    }
    else{
      echo "La requête ne renvoie pas de résultat !" ;
    }

mysqli_close($link);


 ?>



  </body>
</html>
