<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">

    <title></title>
  </head>
  <body>


<div class="col-offset-4 col-4 text-center">
<form class="" action="boissonsModif.php" method="get">
  Sélectionez votre boasson pré-fé-ré : <select class="form-control" name="df">
<?php include "boissonsModif.php" ?>
</select>

<br>

Quantité à modifier: <input class="form-control" type="number" name="quantif" value="">
(C'est un smallint donc pas trop quand même hein) <br>
<button class="btn-primary text-center" type="submit" name = "modif">Modifier</button>
</form>
</div>
  </body>
</html>



<!--
bon j'avais pas compris que ca devait etre une liste statique qu'il fallait faire en premier,
Et vu que j'ai la flemme de tout rechangé du coup ca aurait été :

<form class="" action="boissonsModif.php" method="get">
  Sélectionez votre boisson préféré :
   <select class="form-control" name="df">
    <option value="1"> chai</option>
    <option value="2"> Chartreuse verte</option>
    <option value="36"> Je sais plus le nom de la boisson</option>
  </select>
</form>
-->
