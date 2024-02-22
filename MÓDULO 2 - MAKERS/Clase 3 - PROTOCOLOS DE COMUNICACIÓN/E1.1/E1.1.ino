/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 3
  Ejercicio: 1 (configuración previa)
---------------------------------------------*/

#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

void setup() {
  Serial.begin(9600);

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("Configuración de hora del RTC DS1307 completa.");
}

void loop() {
  // Este sketch no hace nada en el bucle principal.
}