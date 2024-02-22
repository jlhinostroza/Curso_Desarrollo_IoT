/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 4
  Ejercicio: 2

  PINOUT:
  (Módulo lector Micro SD)
  CS -> D10
  MOSI -> D11
  MISO -> D12
  SCK -> D13

  (HC-SR04)
  TRIG -> D2
  ECHO -> D3
---------------------------------------------*/

#include <Wire.h>
#include <SD.h>
#include <SPI.h>

const int PIN_TRIG = 2;
const int PIN_ECHO = 3;

const int PIN_CS = 10;
const int PIN_MOSI = 11;
const int PIN_MISO = 12;
const int PIN_SCK = 13;

File archivoDatos;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  if (!SD.begin(PIN_CS)) {
    Serial.println("Error al inicializar la tarjeta SD.");
    return;
  }

  Serial.println("Inicialización completa.");
}

void loop() {
  unsigned long duracion, distancia;

  // Realizar la medición del sensor HC-SR04
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  duracion = pulseIn(PIN_ECHO, HIGH);
  distancia = duracion * 0.034 / 2;

  // Guardar la distancia en la tarjeta SD
  guardarDistancia(distancia);

  // Esperar 2 segundos antes de la siguiente medición
  delay(2000);
}

void guardarDistancia(unsigned long distancia) {
  archivoDatos = SD.open("distancias.txt", FILE_WRITE);

  if (archivoDatos) {
    archivoDatos.println(distancia);
    archivoDatos.close();
    Serial.println("Distancia guardada en la tarjeta SD: " + String(distancia) + " cm");
  } else {
    Serial.println("Error al abrir el archivo en la tarjeta SD.");
  }
}
