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

Servo miServo;

// Definición de pines para el control de motores
#define PIN_IN1 10
#define PIN_IN2 9
#define PIN_IN3 8
#define PIN_IN4 7

// Definición de pines para el sensor de ultrasonido
#define PIN_TRIG 5
#define PIN_ECHO 4

// Definición de pines para el servo
#define PIN_SERVO 3

// Variables para el cálculo de la distancia
long duracion;
int distancia;

// Variables para el control del servo
int posicionServo = 90; // Posición inicial del servo

void setup() {
  delay(1000);

  miServo.attach(PIN_SERVO);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);

  miServo.write(posicionServo);
}

void loop() {
  delay(50);

  distancia = medirDistancia();

  if (distancia < 15) {
    detenerAuto();

    // Mirar a la derecha
    moverServo(10);
    delay(600);
    int distanciaDerecha = medirDistancia();

    // Mirar a la izquierda
    moverServo(170);
    delay(600);
    int distanciaIzquierda = medirDistancia();

    // Mirar al frente
    moverServo(90);
    delay(600);

    if (distanciaIzquierda > distanciaDerecha) {
      girarIzquierdaAuto();
    } else {
      girarDerechaAuto();
    }
  }

  if (distancia > 15) {
    avanzarAuto();
  }
}

void detenerAuto() {
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, LOW);
}

void girarDerechaAuto() {
  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, HIGH);
  delay(250);
}

void girarIzquierdaAuto() {
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, HIGH);
  digitalWrite(PIN_IN3, HIGH);
  digitalWrite(PIN_IN4, LOW);
  delay(250);
}

void avanzarAuto() {
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, HIGH);
  digitalWrite(PIN_IN3, HIGH);
  digitalWrite(PIN_IN4, LOW);
}

void moverServo(int angulo) {
  miServo.write(angulo);
  delay(500);
}

int medirDistancia() {
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  duracion = pulseIn(PIN_ECHO, HIGH);
  distancia = duracion * 0.034 / 2;

  return distancia;
}