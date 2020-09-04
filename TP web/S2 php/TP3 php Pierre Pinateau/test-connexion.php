<!DOCTYPEhtml>
<html>
<head>
  <title>Exemple</title>
  <metacharset="UTF-8"/>
</head>

<body>
  <?php
  //**************************************************
  //Connexionauserveurdebasededonnées
  //serveur:....
  //login:...
  //mdp:.....
  //base:.....
  //**************************************************
  //*corrigerlesparamètresci-dessouspourseconnecteràlabasededonnée
  $link = mysqli_connect("localhost","root","","test");

  if($link==false){
    echo"Erreur de connexion:".mysqli_connect_errno();
    die();
  }

  else{
    echo"<h1>connexion réussie</h1>";
  }

  $requete = "select societe, ville from fournisseur order by societe" ;
  $result = mysqli_query($link,$requete);

  if ( $result == FALSE ) {
     echo "<p>Erreur d'exécution de la requete</p>" ;
     echo mysqli_errno($conn) . ": " . mysqli_error($link). "\n";
      die();
    }
    else {
      echo "<p>SELECT a retourné " . mysqli_num_rows($result) . " lignes</p>" ;
    }


    /* Extraction des résultats de la requete SELECT */


    ?>

  <!--construction du tableau en HTML avec une première ligne d'entête -->
  <table border='1' align='center' cellpadding='5' >
    <tr><th>SOCIETE</th>
      <th>VILLE</th>
    </tr>
    <?php

    /* Extraction des résultats de la requete SELECT */
    if( mysqli_num_rows($result)> 0)
    {
      while ($row = mysqli_fetch_assoc($result)){
        /* constrution des lignes dynamiquement */
        echo "<tr>";
        echo "<td>" . $row["societe"] . "</td>" ;
        echo "<td>" . $row["ville"] . "</td>" ;
        echo "</tr>";
      }
    }
    else{
      echo "<tr>" ;echo "<td colspan='2'>La requête ne renvoie pas de résultat !</td>" ;
      echo "</tr>";
    }

mysqli_close($link);
?>
  </body>

  </html>
