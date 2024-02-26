/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Inventors
  Clase: 2
  Ejercicio: 2
  
  PINOUT:
  (LED):
  + -> D25
---------------------------------------------*/

const int pinDAC = 25;

void setup() {
  // Configurar el canal DAC
  dacWrite(pinDAC, 0); // Establecer el valor inicial a 0
}

void loop() {
  // Generar una onda sinusoidal en el DAC
  for (int i = 0; i < 255; i++) {
    dacWrite(pinDAC, i); // Escribir valores crecientes en el DAC
    delay(10); // Esperar un breve período de tiempo para ver el cambio
  }
  
  for (int i = 255; i >= 0; i--) {
    dacWrite(pinDAC, i); // Escribir valores decrecientes en el DAC
    delay(10); // Esperar un breve período de tiempo para ver el cambio
  }
}
