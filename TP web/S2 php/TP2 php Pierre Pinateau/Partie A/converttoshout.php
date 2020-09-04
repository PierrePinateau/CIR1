<!DOCTYPE html>
<html lang = "fr" dir = "ltr">
	<head>
		<meta charset = "utf-8">
		<title></title>
	</head>
	<body>
		<?php
			function convert($str)
			{
			$str  =  strtoupper($str);
			echo $str.'!';
			}

			function CalculateCircleArea($diameter)
			{
				$rayon = $diameter/2;
				$var2 = pi();
				$var2 = $var2*$rayon*$rayon;
				echo $var2;
			}

			function check_pswd($str)
			{
				$var1 = strlen($str);
				$var2 = strpbrk($str, "0123456789");
				$var3 = strpbrk($str, "abcdefghijklmnopqrstuvwxyz");
				$var4 = strpbrk($str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

				if ($var1<8) {return "=> Faux mot de passe";}
				else {
					if ($var2 == FALSE) {return "=> Faux mot de passe";}
					else {
						 if ($var3 == FALSE) {return " => Faux mot de passe";}
						else {
							 if ($var4 == FALSE) {return " => Faux mot de passe";}
						else {return "OK";}
						}
					}
				}
		}


			$var1 = "je ne sais pas";
			convert($var1);

			echo "<br><br>";
			CalculateCircleArea(25);
			echo "<br>";
			CalculateCircleArea(30);
			echo "<br>";
			CalculateCircleArea(872);
			echo "<br>";
			CalculateCircleArea(6);
			echo "<br>";
			CalculateCircleArea(29);
			echo "<br><br>";

			$chaine = "test";
			$chaine1 = "testtest";
			$chaine2 = "Testtest";
			$chaine3 = "Testtest2";

			echo $chaine;
			$chaine = check_pswd($chaine);
			print("\n");
			echo $chaine;
			echo "<br>";

			echo $chaine1;
			$chaine1 = check_pswd($chaine1);
			print("\n");
			echo $chaine1;
			echo "<br>";

			echo $chaine2;
			$chaine2 = check_pswd($chaine2);
			print("\n");
			echo $chaine2;
			echo "<br>";

			echo $chaine3;
			$chaine3 = check_pswd($chaine3);
			print("\n");
			echo $chaine3;
			echo "<br>";
			?>
	</body>
</html>
