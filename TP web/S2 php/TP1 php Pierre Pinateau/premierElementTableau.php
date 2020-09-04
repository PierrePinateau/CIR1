<?php
function premierElementTableau($val){
  if (count($val)>0) {
    $val = $val[0];
    return $val;
  }
  else {
    return "null";
  }
}

function dernierElementTableau($val)
{
  if (count($val)>0) {
    $val = $val[count($val)-1];
    return $val;
  }
  else {
    return "null";
  }
}

 $cars = array("Volvo", "BMW", "Toyota");
 $test = premierElementTableau($cars);
 $test2 = dernierElementTableau($cars);
 echo "<p>Premier element : $test</p>";
 echo "<p>Dernier element : $test2</p>";

 ?>
