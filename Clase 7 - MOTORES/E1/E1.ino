/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 7
  Ejercicio: 1

  PINOUT:
  (SG90)
  PULSE -> D3
---------------------------------------------*/

#include <Servo.h>

Servo miServo;  // Objeto del servo

void setup() {
  miServo.attach(9);  // El servo está conectado al pin 9
  Serial.begin(9600);
}

void loop() {
  miServo.write(0);    // Gira a 0 grados
  Serial.println("Servo en 0°");
  delay(2000);      // Espera 2 segundos

  miServo.write(90);   // Gira a 90 grados
  Serial.println("Servo en 90°");
  delay(2000);      // Espera 2 segundos

  miServo.write(180);  // Gira a 180 grados
  Serial.println("Servo en 180°");
  delay(2000);      // Espera 2 segundos
}