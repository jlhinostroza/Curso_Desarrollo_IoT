/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 5
  Ejercicio: 1

  PINOUT:
  (HC-SR501)
  OUT -> D2

  (Buzzer)
  + -> D3
---------------------------------------------*/

#define pinPIR 2
#define pinBuzzer 3

void setup() {
  pinMode(pinPIR, INPUT);
  pinMode(pinBuzzer, OUTPUT);

  Serial.begin(9600);
  Serial.println("Sistema de Alarma Activado");
}

void loop() {
  int movimiento = digitalRead(pinPIR);

  if (movimiento == HIGH) {
    activarAlarma();
  } else {
    desactivarAlarma();
  }
}

void activarAlarma() {
  Serial.println("¡Movimiento detectado!");
  digitalWrite(pinBuzzer, HIGH);
  delay(500);  // Tiempo que el buzzer está encendido (en milisegundos)
  digitalWrite(pinBuzzer, LOW);
  delay(500);  // Tiempo que el buzzer está apagado (en milisegundos)
}

void desactivarAlarma() {
  Serial.println("No hay movimiento.");
  digitalWrite(pinBuzzer, LOW);
}
