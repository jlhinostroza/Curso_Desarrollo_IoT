/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 7
  Ejercicio: 2

  PINOUT:
  (L298N)
  IN1 -> D10
  IN2 -> D9
  IN3 -> D8
  IN4 -> D7

  5V -> Vin
---------------------------------------------*/

#define motor1pin1 10
#define motor1pin2 9
#define motor2pin1 8
#define motor2pin2 7

void setup() {
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}
void loop() {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  delay(5000);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  
  delay(5000);
}