/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 2
  Ejercicio: 3
---------------------------------------------*/

int num1 = 3;
int num2 = 18;

void setup() {
Serial.begin(9600);

int suma = num1 + num2; //Operación de suma

Serial.print("La suma de los números es: ");
Serial.println(suma);
}

void loop() {
}