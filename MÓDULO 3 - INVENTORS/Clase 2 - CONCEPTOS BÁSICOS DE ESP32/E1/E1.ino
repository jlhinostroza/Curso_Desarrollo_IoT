/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Inventors
  Clase: 2
  Ejercicio: 1
  
  PINOUT:
  (LED):
  + -> D32
---------------------------------------------*/

const int pinLED = 32;

int frecuencia = 5000;
int canal = 0;
int resolucion = 8;
int dutyCycle = 50;

void setup(){
  //Configuramos la funcionalidad PWM
  ledcSetup(canal, frecuencia, resolucion);
  //Asociamos el canal al pin GPIO 32
  ledcAttachPin(pinLED, canal);
}

void loop(){
  ledcWrite(canal, dutyCycle);
}