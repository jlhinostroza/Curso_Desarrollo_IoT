/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 8
  Ejercicio: 1

  PINOUT:
  (L298N)
  IN1 -> D10
  IN2 -> D9
  IN3 -> D8
  IN4 -> D7

  (HC-SR04)
  TRIG -> D5
  ECHO -> D4

  (SG90)
  PULSE -> D3
---------------------------------------------*/

#include <Servo.h>

Servo mi_servo;

// Definición de pines para el control de motores
int pin_in1 = 10;
int pin_in2 = 9;
int pin_in3 = 8;
int pin_in4 = 7;

// Definición de pines para el sensor de ultrasonido
int pin_trig = 5;
int pin_echo = 4;

// Definición de pines para el servo
int pin_servo = 3;

// Variables para el cálculo de la distancia
long duracion;
int distancia;

// Variables para el control del servo
int posicion_servo = 90; // Posición inicial del servo

void setup() {
  delay(1000);

  mi_servo.attach(pin_servo);

  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);

  pinMode(pin_in1, OUTPUT);
  pinMode(pin_in2, OUTPUT);
  pinMode(pin_in3, OUTPUT);
  pinMode(pin_in4, OUTPUT);

  mi_servo.write(posicion_servo);
}

void loop() {
  delay(50);

  distancia = medir_distancia();

  if (distancia < 15) {
    detener_auto();

    // Mirar a la derecha
    mover_servo(10);
    delay(600);
    int distancia_derecha = medir_distancia();

    // Mirar a la izquierda
    mover_servo(170);
    delay(600);
    int distancia_izquierda = medir_distancia();

    // Mirar al frente
    mover_servo(90);
    delay(600);

    if (distancia_izquierda > distancia_derecha) {
      girar_izquierda_auto();
    } else {
      girar_derecha_auto();
    }
  }

  if (distancia > 15) {
    avanzar_auto();
  }
}

void detener_auto() {
  digitalWrite(pin_in1, LOW);
  digitalWrite(pin_in2, LOW);
  digitalWrite(pin_in3, LOW);
  digitalWrite(pin_in4, LOW);
}

void girar_derecha_auto() {
  digitalWrite(pin_in1, HIGH);
  digitalWrite(pin_in2, LOW);
  digitalWrite(pin_in3, LOW);
  digitalWrite(pin_in4, HIGH);
  delay(250);
}

void girar_izquierda_auto() {
  digitalWrite(pin_in1, LOW);
  digitalWrite(pin_in2, HIGH);
  digitalWrite(pin_in3, HIGH);
  digitalWrite(pin_in4, LOW);
  delay(250);
}

void avanzar_auto() {
  digitalWrite(pin_in1, LOW);
  digitalWrite(pin_in2, HIGH);
  digitalWrite(pin_in3, HIGH);
  digitalWrite(pin_in4, LOW);
}

void mover_servo(int angulo) {
  mi_servo.write(angulo);
  delay(500);
}

int medir_distancia() {
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);

  duracion = pulseIn(pin_echo, HIGH);
  distancia = duracion * 0.034 / 2;

  return distancia;
}
