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

#include <IRremote.h>		// importa libreria IRremote

#define PIN_IR 35          // Pin del módulo receptor infrarrojo 
 
void setup() { 
  Serial.begin(9600);     				// inicializa comunicacion serie a 9600 bps
  IrReceiver.begin(PIN_IR, DISABLE_LED_FEEDBACK);    	// inicializa recepcion de datos
} 

void loop() { 
  if (IrReceiver.decode()) {   				// si existen datos ya decodificados
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // imprime valor en hexadecimal en monitor
    IrReceiver.resume();      				// resume la adquisicion de datos
  }
  delay (100);        					// breve demora de 100 ms.
}