/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 5
  Ejercicio: 3

  PINOUT:
  (Sensor de pulso)
  S -> A0
---------------------------------------------*/

#include <PulseSensorPlayground.h>

const int PinPulso = A0;
const int PinLED13 = 13;

int Umbral = 550;

PulseSensorPlayground sensorPulso;

void setup() {
  Serial.begin(9600);

  sensorPulso.analogInput(PinPulso);
  sensorPulso.blinkOnPulse(PinLED13);
  sensorPulso.setThreshold(Umbral);

  if (sensorPulso.begin()) {
    Serial.println("SENSOR DE PULSO CARDIACO");
  }
}

void loop() {
  int miBPM = sensorPulso.getBeatsPerMinute();

  if (sensorPulso.sawStartOfBeat()) {
    Serial.println("♥ Tu corazón está latiendo  ");
    Serial.print("PPM: ");
    Serial.println(miBPM);
  }

  delay(10);
}