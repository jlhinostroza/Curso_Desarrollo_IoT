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

const int pinPulsador1 = 2;
const int pinPulsador2 = 3;

void setup() {
    pinMode(pinPulsador1, INPUT_PULLUP);
    pinMode(pinPulsador2, INPUT_PULLUP);
    rf_driver.init();
}

void loop() {
    if (digitalRead(pinPulsador1) == LOW) {
        enviarMensaje("1");
    } else if (digitalRead(pinPulsador2) == LOW) {
        enviarMensaje("2");
    }

    delay(200);
}

void enviarMensaje(const char *mensaje) {
    rf_driver.send((uint8_t *)mensaje, strlen(mensaje));
    rf_driver.waitPacketSent();
}
