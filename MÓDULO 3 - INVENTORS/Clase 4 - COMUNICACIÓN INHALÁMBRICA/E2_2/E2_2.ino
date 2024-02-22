/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Inventors
  Clase: 3
  Ejercicio: 2
  PINOUT:
  (Receptor IR):
  DATA -> D35

  (7 segmentos - Cátodo común):
  SEG A -> D5
  SEG B -> D18
  SEG C -> D19
  SEG D -> D21
  SEG E -> D22
  SEG F -> D13
  SEG G -> D12
---------------------------------------------*/

#include <IRremote.h>
#include <SevSeg.h>

const int pinIR = 35;         // Pin del módulo receptor infrarrojo
const int numDigitos = 1;     // Número de dígitos en el display
const int pinDigito = 34;     // Pin para controlar el display entero

const int PIN_SEG_A = 5;        // Pin A del display de 7 segmentos
const int PIN_SEG_B = 18;       // Pin B del display de 7 segmentos
const int PIN_SEG_C = 19;       // Pin C del display de 7 segmentos
const int PIN_SEG_D = 21;       // Pin D del display de 7 segmentos
const int PIN_SEG_E = 22;       // Pin E del display de 7 segmentos
const int PIN_SEG_F = 13;       // Pin F del display de 7 segmentos
const int PIN_SEG_G = 12;       // Pin G del display de 7 segmentos

SevSeg sevseg;             // Objeto para controlar el display de 7 segmentos
IRrecv receptorIR(pinIR);  // Objeto para recibir señales infrarrojas
decode_results resultados; // Almacena los resultados del decodificador IR

void setup() {
  byte digitosPins[] = {pinDigito};
  byte segmentPins[] = {PIN_SEG_A, PIN_SEG_B, PIN_SEG_C, PIN_SEG_D, PIN_SEG_E, PIN_SEG_F, PIN_SEG_G};  // Puedes ajustar estos pines según la conexión específica de tu display
  sevseg.begin(COMMON_CATHODE, numDigitos, digitosPins, segmentPins, false);
  sevseg.setBrightness(90);

  receptorIR.enableIRIn();
  
  Serial.begin(9600);
}

void loop() {
  if (receptorIR.decode(&resultados)) {
    switch (resultados.value) {
      case /*CAMBIAR*/:  // Botón 1
        sevseg.setNumber(1);
        break;
      case /*CAMBIAR*/:  // Botón 2
        sevseg.setNumber(2);
        break;
      case /*CAMBIAR*/:  // Botón 3
        sevseg.setNumber(3);
        break;
      case /*CAMBIAR*/:  // Botón 4
        sevseg.setNumber(4);
        break;
      case /*CAMBIAR*/:  // Botón 5
        sevseg.setNumber(5);
        break;
      case /*CAMBIAR*/:  // Botón 6
        sevseg.setNumber(6);
        break;
      case /*CAMBIAR*/:  // Botón 7
        sevseg.setNumber(7);
        break;
      case /*CAMBIAR*/:  // Botón 8
        sevseg.setNumber(8);
        break;
      case /*CAMBIAR*/:  // Botón 9
        sevseg.setNumber(9);
        break;
      case /*CAMBIAR*/:  // Botón 0
        sevseg.setNumber(0);
        break;
    }

    receptorIR.resume();  // Reiniciar el receptor IR para escuchar más señales
  }

  sevseg.refreshDisplay();
  delay(10);
}