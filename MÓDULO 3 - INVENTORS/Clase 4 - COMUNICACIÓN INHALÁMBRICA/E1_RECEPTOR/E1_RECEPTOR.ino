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

const int pinAzul = 4;
const int pinVerde = 3;

void setup() {
    pinMode(pinAzul, OUTPUT);
    pinMode(pinVerde, OUTPUT);
    rf_driver.init();
}

void loop() {
    uint8_t buf[1];
    uint8_t buflen = sizeof(buf);

    if (rf_driver.recv(buf, &buflen)) {
        char comando = (char)buf[0];

        switch (comando) {
            case '1':
                digitalWrite(pinAzul, !digitalRead(pinAzul));
                break;
            case '2':
                digitalWrite(pinVerde, HIGH);
                delay(5000);
                digitalWrite(pinVerde, LOW);
                break;
        }
    }
}