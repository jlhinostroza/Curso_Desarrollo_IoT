/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Inventors
  Clase: 3
  Ejercicio: 1
  PINOUT:
  (Receptor):
  DATA -> D11
---------------------------------------------*/

//// lado Receptor ////

#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;

#define LED_AZUL 4
#define LED_VERDE 3

void setup() {
    pinMode(LED_AZUL, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    rf_driver.init();
}

void loop() {
    uint8_t buf[1];
    uint8_t buflen = sizeof(buf);

    if (rf_driver.recv(buf, &buflen)) {
        char comando = (char)buf[0];

        switch (comando) {
            case '1':
                digitalWrite(LED_AZUL, !digitalRead(LED_AZUL));
                break;
            case '2':
                digitalWrite(LED_VERDE, HIGH);
                delay(5000);
                digitalWrite(LED_VERDE, LOW);
                break;
        }
    }
}