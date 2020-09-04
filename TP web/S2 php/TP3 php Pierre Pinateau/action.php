<?php

    $truc = $_POST['add'];
    include 'connexion.php';

    $requete = "insert into genre (genre) value ('$truc')";
    $result = mysqli_query($link,$requete);

    include 'genre_tab.php'

 ?>
