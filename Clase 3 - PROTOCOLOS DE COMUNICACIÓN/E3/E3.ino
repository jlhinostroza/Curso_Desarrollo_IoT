/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 3
  Ejercicio: 3

  PINOUT:
  (HC-056)
  TX -> D2
  RX -> D1

  (LED RGB)
  R -> D9
  G -> D10
  B -> D11
---------------------------------------------*/

#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); // RX, TX pins del módulo HC-05
#define pinRojo 9
#define pinVerde 10
#define pinAzul 11

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);
}

void loop() {
  if (bluetooth.available() > 0) {
    char comando = bluetooth.read();

    switch (comando) {
      case 'R':
        setColor(255, 0, 0); // Rojo
        break;
      case 'G':
        setColor(0, 255, 0); // Verde
        break;
      case 'B':
        setColor(0, 0, 255); // Azul
        break;
      case 'W':
        setColor(255, 255, 255); // Blanco
        break;
      case 'O':
        setColor(0, 0, 0); // Apagar
        break;
      default:
        break;
    }
  }
}

void setColor(int rojo, int verde, int azul) {
  analogWrite(pinRojo, rojo);
  analogWrite(pinVerde, verde);
  analogWrite(pinAzul, azul);
}
