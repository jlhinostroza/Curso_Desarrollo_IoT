/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Inventors
  Clase: 1
  Ejercicio: 1
  PINOUT:
  (LED RGB):
  R -> D19
  G -> D18
  B -> D5
---------------------------------------------*/

#define PIN_LED_R 19
#define PIN_LED_G 18
#define PIN_LED_B 5

#define PIN_TOUCH_D4 T0
#define PIN_TOUCH_D2 T2
#define PIN_TOUCH_D15 T3

void setup() {
  Serial.begin(115200);

  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);

  touchAttachInterrupt(PIN_TOUCH_D4, tocarD4, 40);
  touchAttachInterrupt(PIN_TOUCH_D2, tocarD2, 40);
  touchAttachInterrupt(PIN_TOUCH_D15, tocarD15, 40);
}

void loop() {
  // El loop está vacío ya que las funciones de interrupción se encargan del cambio de color
}

void tocarD4() {
  cambiarColor(255, 0, 0);  // Rojo
}

void tocarD2() {
  cambiarColor(0, 255, 0);  // Verde
}

void tocarD15() {
  cambiarColor(0, 0, 255);  // Azul
}

void cambiarColor(int rojo, int verde, int azul) {
  analogWrite(PIN_LED_R, rojo);
  analogWrite(PIN_LED_G, verde);
  analogWrite(PIN_LED_B, azul);
}
