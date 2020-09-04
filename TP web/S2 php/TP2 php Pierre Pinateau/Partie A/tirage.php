<!DOCTYPE html>
<html lang="fr" dir="ltr">
	<head>
		<meta charset="utf-8">
		<title></title>
	    <link rel="stylesheet" href="tirage.css">
	</head>
	<body>

			<h1> Nombres aléatoires </h1>
			<h2>Suite de tirages</h2>

			<?php
			$compteur = 0;

			$var1 = rand(100, 999);
			$var2 = rand(100, 999);
			$var3 = rand(100, 999);

			// utilisation des modulos pour trouver si le nombre est pair ou non
			while (!($var1 % 2 == 0 && $var2 % 2 == 1 && $var3 % 2 == 1))
			{
			$var1 = rand(100, 999);
			$var2 = rand(100, 999);
			$var3 = rand(100, 999);

			echo $compteur;
			print("\n : ");
			echo $var1;
			print("\n");
			echo $var2;
			print("\n");
			echo $var3;
			echo "<br>";
			$compteur = $compteur + 1;
			}

			echo $compteur;
			print("\n : ");
			echo $var1;
			print("\n");
			echo $var2;
			print("\n");
			echo $var3;
			echo "<br>";
			
			echo "<br>";
			print("Résultat obtenu en $compteur coups")
			?>
		</body>
</html>
