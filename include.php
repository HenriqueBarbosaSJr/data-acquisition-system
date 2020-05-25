<?php

    include "connectiondb.php";
    $s1_rec = $_GET['s1'];
    $s2_rec = $_GET['s2'];
    $s3_rec = $_GET['s3'];

    $SQL_INS = "INSERT INTO sensores (sensor1, sensor2, sensor3) VALUES (:S1, :S2, :S3)";


    $stmt = $con->prepare($SQL_INS);

    $stmt->bindParam(':S1', $s1_rec);
    $stmt->bindParam(':S2', $s2_rec);
    $stmt->bindParam(':S3', $s3_rec);
 

    if($stmt->execute()){
        echo " <br> Insert OK";
    }else{
        echo "<br> Insert erro";
    }
?> 