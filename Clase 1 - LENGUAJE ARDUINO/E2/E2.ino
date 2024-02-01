/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 1
  Ejercicio: 2
---------------------------------------------*/

void setup() {
  Serial.begin(9600);

  int numero = 7; // Puedes cambiar este valor para probar diferentes casos

  Serial.println("Usando if-else:");
  // Condicionales if-else para determinar si el número es par o impar
  if (numero % 2 == 0) {
    Serial.println("El número es par.");
  } else {
    Serial.println("El número es impar.");
  }

  Serial.println("\nUsando switch:");
  // Condicionales switch para determinar si el número es par o impar
  switch (numero % 2) {
    case 0:
      Serial.println("El número es par.");
      break;
    case 1:
      Serial.println("El número es impar.");
      break;
    default:
      Serial.println("Error en la evaluación.");
  }
}

void loop() {
  // Nada en el loop
}