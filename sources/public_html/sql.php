

<?php
        try
        {
        $bdd = new PDO('mysql:host=localhost;dbname=menagerie;charset=utf8', 'root', 'your_password');        }
        catch (Exception $e)
        {
                die('Erreur : ' . $e->getMessage());
        }

        $reponse = $bdd->query('SELECT * from MPU6050 where date and temp < 30');

        $tableau = array('temp');
        $tableau_date = array('date');
        $j=0;


        while ($donnees = $reponse->fetch())
        {
?>


<?php

    
    $tableau[$j]=$donnees['temp'];
    $tableau_date[$j]=$donnees['date'];
      
    $j++;

        }

    $reponse->closeCursor(); // Termine le traitement de la requête

?>


<table class="table">



  <caption>Dernières données enregistrées</caption>
  <thead>
    <tr>
      <th>Temperature</th>
      <th>Heure</th>
    </tr>
  </thead>
  <tbody>
   <?php
  for ($i=0; $i<$j; $i++) 
  { 
   ?>

  <tr>

    <td>
<?php      
      echo $tableau[$i]; 
?> 
    </td>

<td>
    <?php
           echo $tableau_date[$i];
    ?>   
</td>

  </tr>

  <?php
  } // end for
?>

</table>


