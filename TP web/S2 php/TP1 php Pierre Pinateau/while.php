<!DOCTYPE html>
  <html>
  <head>
    <title>Exemple</title>
    <meta charset="UTF-8" />
  </head>
  <body>
    <h1>Structures de contrôle</h1>
    <?php
    $x = 0.0 ;
    while ( $x <= 1 )
    {
    echo "cos(" . $x . ") = " . cos($x) . " <br/>";
    $x = $x + 0.1 ;
    }
    ?>
  </body>
</html>
