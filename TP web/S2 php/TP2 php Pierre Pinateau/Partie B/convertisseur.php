<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>:sweat²:</title>

  </head>
  <body>
    <h1>Convertisseur dollars/euro</h1>
    <form method="post" action="convertisseur_action.php">
          <input type="radio" name="type" value="euro"/>
          <label for="euro">euro vers dollars</label> <br>
          <input type="radio" name="type" value="dollars"/>
          <label for="dollars">dollars vers euro</label>

      <br><br>
      Value : <input type="number" name="money"/>

      <input type="submit" value="Validé D:"/>
      <input type="reset" value="Reset D:"/>
    </form>

  </body>
</html>
