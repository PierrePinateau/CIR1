<!DOCTYPE html>
<html lang="fr" dir="ltr">
	<head>
		<meta charset="utf-8">
		<title></title>
	</head>
	<body>
		<?php

		function CalculateTip($var)
		{
			return ($var + $var*18/100);
		}
		echo round(CalculateTip(100));
		echo "<br>";
		echo round(CalculateTip(35));
		echo "<br>";
		echo round(CalculateTip(88.77));

		//////////////////
		function cal_distance($var1, $var2)
		{
			if ($var1>$var2)
			{
				$var1=$var1-$var2;
				return $var1;
			}

			else
			{
				$var2=$var2-$var1;
				return $var2;
			}
		}

		$var_name_generator_8=cal_distance(4,-1);
		print("\n");

		echo $var_name_generator_8;
		$var_name_generator_8=cal_distance(-1,4);
		print("\n");

		echo $var_name_generator_8;
		$var_name_generator_8=cal_distance(3,7);
		print("\n");

		echo $var_name_generator_8;
		$var_name_generator_8=cal_distance(7,3);
		print("\n");

		echo $var_name_generator_8;
		?>


	</body>
</html>
