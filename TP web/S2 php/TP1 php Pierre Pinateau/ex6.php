<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>:sweat²:</title>

  </head>
  <body>
    <form method="post">
       <p>Txt : <input type="text" name="id_map"/></p>
    </form>

    <?php
        function remplacerLettres($a){
           $replace = array("e", "i", "o");
           $number = array("3","1","0");
           return str_replace($replace, $number, $a);
        }
        echo "Résultat :".remplacerLettres($_POST['id_map']);

     ?>
  </body>
</html>
