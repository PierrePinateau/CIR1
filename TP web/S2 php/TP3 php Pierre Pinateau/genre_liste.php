<!DOCTYPE html>
<html lang="fr">
  <head>
    <meta charset="utf8" />
    <title> Liste des genres </title>
  </head>

  <body>
    	<?php	include 'connexion.php';


      $requete = "SELECT genre FROM genre" ;
      $result = mysqli_query($link,$requete);
      /* puis vérifiez que l’exécution de la requête a réussi,
      si requête réussie, retournez le nombre de lignes renvoyé par la requête.
      Aide : suivre la démarche de la section 5 */
      /* Extraction des résultats de la requête SELECT */
      if ( mysqli_num_rows($result) > 0) {
      //ci-dessous on extrait et on affiche les résultats de la requête dans une liste (comme la démarche de la section 6
      echo "<ul>";
      while ($row = mysqli_fetch_assoc($result))
      {
      echo "<li>".$row["genre"]."</li>\n";
      }
      echo "</ul>\n";
      }
      else
      {
      echo "La requête ne renvoie pas de résultat !" ;
      }
      // fermez la connexion
      mysqli_close($link);

    ?>
  </body>
</html>
