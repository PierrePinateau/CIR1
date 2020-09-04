<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
        <form method="post">
           <p>Nombre 1 : <input type="number" name="nombre_un"/></p>
          <p>Nombre 2 : <input type="number" name='n2'/></p>
      <input type="submit" value="Goo D:"/>

        </form>
  </head>
  <body>
    <?php
    function plusGrand($a, $b)
    {
      if ($a>$b) {
        return $a;
        }
      else {
        return $b;
      }

    }
          echo "Nombre le plus grand : ".plusGrand($_POST['nombre_un'],$_POST['n2']);
    ?>
  </body>
</html>
