<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
    <style media="screen">

        caption{
        font-family: Broadway;

        }

      table {
        width: 100%;
        border-collapse:collapse;
        border-width:3px;
        border-style:solid;
        border-color:#6495ed;
        font-family: serif;

      }

      td {
      border-width:1px;
      border-style:solid;
      background-color: #FFF;
      border-color: #6495ed;

      }
      th {
        border-width:1px;
        border-style:solid;
        background-color: #EFF6FF;
        border-color: #6495ed;


      }


    </style>
  </head>
  <body>
    <?php
      include 'connexion.php';
      ?>
      <table border='1' align='center' cellpadding='5' >
        <caption>Liste des genres Méthode 1</caption>
    <tr><th></th>
      <th>genre</th>
    </tr>
    <?php

    /* Extraction des résultats de la requete SELECT */
    $requete = "SELECT genre FROM genre" ;
    $result = mysqli_query($link,$requete);
    $count = 1;
    if(mysqli_num_rows($result)> 0)
    {
      while ($row = mysqli_fetch_assoc($result)){
        /* constrution des lignes dynamiquement */
        echo "<tr>";
        echo "<td>" .$count  . "</td>" ;
        echo "<td>" . $row["genre"] . "</td>" ;
        echo "</tr>";
        $count = $count +1;
      }
    }
    else{
      echo "<tr>" ;echo "<td colspan='2'>La requête ne renvoie pas de résultat !</td>" ;
      echo "</tr>";
    }

     ?>
   </table>

   <table border='1' align='center' cellpadding='5' >
     <caption>Liste des genres Méthode 2</caption>
         <tr><th></th>
           <th>genre</th>
         </tr>

        <?php
        $sql = new mysqli("localhost", "root", "" , "film") ;
        $query = "SELECT genre FROM genre";
        $result = $sql->query($query);
        if (!$result) {
          printf("Query failed: %s\n", $mysqli->error);
          exit;
        }
            $count = 1;

        while($row = $result->fetch_row()) {
          $rows[]=$row;
                  foreach ($row as $key => $entry) {
                    echo "<tr>";
                    echo "<td>" .$count  . "</td>" ;
                    echo "<td>" . $entry . "</td>" ;
                    echo "</tr>";
                            $count = $count +1;

                  }
        }


              mysqli_close($link);
?>
   </table>


  </body>
</html>
