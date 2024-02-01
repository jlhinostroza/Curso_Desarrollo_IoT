<?php
$hostname = "localhost";
$username = "root";
$password = "";
$database = "sensor_db"; //CAMBIAR POR NOMBRE DE LA BASE DE DATOS

$con = mysqli_connect($hostname, $username, $password, $database);

if (!$con) { 
	die("Conexión fallida: " . mysqli_connect_error()); 
} 

echo "Conexión con BDD exitosa<br>"; 

if(isset($_POST["temperature"]) && isset($_POST["humidity"])) { //CAMBIAR POR LOS PARAMETROS A TOMAR

	$t = $_POST["temperature"];
	$h = $_POST["humidity"];

	$sql = "INSERT INTO dht11 (temperature, humidity) VALUES (".$t.", ".$h.")"; 

	if (mysqli_query($con, $sql)) { 
		echo "\nNuevo muestreo"; 
	} else { 
		echo "Error: " . $sql . "<br>" . mysqli_error($con); 
	}
}
?>