/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Inventors
  Clase: 5
  Ejercicio: 1

  PINOUT:
  IN1 -> D13
  IN2 -> D12
  IN3 -> D14
  IN4 -> D27
---------------------------------------------*/

#include <BluetoothSerial.h>

// Define los pines del L298N
const int IN1 = 13;
const int IN2 = 12;
const int IN3 = 14;
const int IN4 = 27;

BluetoothSerial SerialBT;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  SerialBT.begin("ESP32_BT_Car"); // Nombre del dispositivo Bluetooth
  Serial.begin(9600);
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    
    switch(command) {
      case 'U': // Adelante
        moveForward();
        break;
      case 'D': // Atrás
        moveBackward();
        break;
      case 'L': // Izquierda
        turnLeft();
        break;
      case 'R': // Derecha
        turnRight();
        break;
      case 'S': // Detener
        stopMotors();
        break;
      default:
        break;
    }
  }
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
