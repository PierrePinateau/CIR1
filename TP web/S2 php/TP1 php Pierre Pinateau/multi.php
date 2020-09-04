<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
    <link rel="stylesheet" href="master.css">
  </head>

  <body>
    <p style="color:red;font-size:1.5em;">Tables de multiplications</p>
    <br>
    <?php
    for ($i=1; $i < 11; $i++) {
      echo "<ul id=\"t\">";
      for ($v=1; $v < 11; $v++) {
        $r = $i*$v;
        echo "<li>$r</li>";
      }
      echo "</ul>";
    }

     ?>


  </body>
</html>
