<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>




      <table border='1' align='center' cellpadding='5' >
        <tr><th>SOCIETE</th>
          <th>VILLE</th>
        </tr>

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

    $count = 0;
    if( mysqli_num_rows($result)> 0)
    {
      while ($row = mysqli_fetch_assoc($result)){
        /* constrution des lignes dynamiquement */
        echo "<tr>";
        echo "<td>" . $row["nom"] . "</td>" ;
        echo "<td>" . $row["total"] . "</td>" ;
        echo "</tr>";
        $count += $row["total"];
      }
              echo "<tr>";
              echo "<td> TOTAL STOCK</td>" ;
              echo "<td>" . $count . "</td>" ;
              echo "</tr>";
    }
    else{
      echo "<tr>" ;echo "<td colspan='2'>La requête ne renvoie pas de résultat !</td>" ;
      echo "</tr>";
    }

mysqli_close($link);


 ?>



  </body>
</html>
