<!DOCTYPE html>
<html lang="en" dir="ltr">
	<head>
		<meta charset="utf-8">
		<title></title>
	</head>
	<body>

		<?php

			$message = ["Oh hello", "You're doing great", "Keep up the good work!\n"];
			$favorite_nums = [7,201,33,88,91];
			$try1= implode("!", $message);
			echo $try1;


			echo "<br><br>";
			print_r($favorite_nums);
			echo "<br><br>";

			$stack = ["wild succes", "failure", "struggle"];
			array_push($stack, "blocker", "impediment");
			$try2 = implode(",", $stack);
			echo $try2;

			array_pop($stack);
			echo "<br><br>";

			$try3 = implode(",", $stack);
			echo "$try3";


			echo "<br><br>";
			$record_holders = [];
			array_unshift($record_holders, "Tim Montgomery", "Maurice Greene", "Donovan Bailey", "Leroy Burrell", "Carl Lewis");
			$try4 = implode(",", $record_holders);
			echo "$try4";


			echo "<br><br>";
			array_unshift($record_holders, "Justin Gatlin", "Asafa Powell");
			$try5 = implode(",", $record_holders);
			echo "$try5";
			echo "<br><br>";


			array_shift($record_holders);
			$try6 = implode(",", $record_holders);
			echo $try6;


			echo "<br><br><br><br><br>";
			function premierElementTableau($tableau)
			{
				if (tableau[0] == NULL)
				{
					return NULL;
				}
				else
				{
					$val = array_shift($tableau);

					return $val;
				}

			}

			function dernierElementTableau($tableau)
			{

				if (tableau[0] == NULL)
				{
					return NULL;
				}
				else
				{
					$valeur = array_pop($tableau);

					return $valeur;
				}
			}

			?>
	</body>
</html>
