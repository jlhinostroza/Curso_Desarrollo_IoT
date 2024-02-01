/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 7
  Ejercicio: 1
  Mini proyecto: Luz con interruptor de sonido

  PINOUT:
  (KY-038):
  AO -> D3

  (Módulo relé):
  S -> D2
---------------------------------------------*/

#define SENSOR_PIN 3    // Pin de salida del sensor KY-038
#define RELAY_PIN 2     // Pin de control del relay

int sonidoDetectado = 0;
int estadoRelay = LOW;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, estadoRelay);  // Asegurar que el relay está apagado al inicio
  Serial.begin(9600);
}

void loop() {
  sonidoDetectado = digitalRead(SENSOR_PIN);

  if (sonidoDetectado == HIGH) {
    if (estadoRelay == LOW) {
      Serial.println("Sonido detectado. Encendiendo el foco.");
      estadoRelay = HIGH;
    } else {
      Serial.println("Sonido detectado nuevamente. Apagando el foco.");
      estadoRelay = LOW;
    }
    digitalWrite(RELAY_PIN, estadoRelay);
    delay(1000);  // Debounce para evitar múltiples cambios rápidos
  }
}