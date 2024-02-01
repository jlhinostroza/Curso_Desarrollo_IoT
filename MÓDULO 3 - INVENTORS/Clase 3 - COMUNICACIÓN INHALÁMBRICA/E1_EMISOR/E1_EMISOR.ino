/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Inventors
  Clase: 3
  Ejercicio: 1
  PINOUT:
  (Emisor):
  DATA -> D12
---------------------------------------------*/

//// lado Emisor ////

#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;

#define PULSADOR_1 2
#define PULSADOR_2 3

void setup() {
    pinMode(PULSADOR_1, INPUT_PULLUP);
    pinMode(PULSADOR_2, INPUT_PULLUP);
    rf_driver.init();
}

void loop() {
    if (digitalRead(PULSADOR_1) == LOW) {
        enviarMensaje("1");
    } else if (digitalRead(PULSADOR_2) == LOW) {
        enviarMensaje("2");
    }

    delay(200);
}

void enviarMensaje(const char *mensaje) {
    rf_driver.send((uint8_t *)mensaje, strlen(mensaje));
    rf_driver.waitPacketSent();
}
