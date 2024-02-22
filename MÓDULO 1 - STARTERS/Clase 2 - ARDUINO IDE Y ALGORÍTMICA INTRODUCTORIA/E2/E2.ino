/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 2
  Ejercicio: 2
---------------------------------------------*/

void setup() {
  Serial.begin(9600);
  Serial.println("Por favor, ingresa tu nombre:");
}

void loop() {
  if (Serial.available() > 0) { //Ver si hay datos disponibles para ser leídos desde el puerto serie
    String nombre = Serial.readString(); //Obtener los caracteres leídos
    
    Serial.print("Hola, ");
    Serial.println(nombre);
  }
}