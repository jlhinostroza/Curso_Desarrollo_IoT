/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Inventors
  Clase: 2
  Ejercicio: 3

  PINOUT:
  (LED RGB):
  R -> D19
  G -> D18
  B -> D5
---------------------------------------------*/

const int pin_led_r = 19;
const int pin_led_g = 18;
const int pin_led_b = 5;

const int pin_touch_d4 = T0;
const int pin_touch_d2 = T2;
const int pin_touch_d15 = T3;

void setup() {
  Serial.begin(115200);

  pinMode(pin_led_r, OUTPUT);
  pinMode(pin_led_g, OUTPUT);
  pinMode(pin_led_b, OUTPUT);

  touchAttachInterrupt(pin_touch_d4, tocar_d4, 40);
  touchAttachInterrupt(pin_touch_d2, tocar_d2, 40);
  touchAttachInterrupt(pin_touch_d15, tocar_d15, 40);
}

void loop() {
  // El loop está vacío ya que las funciones de interrupción se encargan del cambio de color
}

void tocar_d4() {
  cambiar_color(255, 0, 0);  // Rojo
}

void tocar_d2() {
  cambiar_color(0, 255, 0);  // Verde
}

void tocar_d15() {
  cambiar_color(0, 0, 255);  // Azul
}

void cambiar_color(int rojo, int verde, int azul) {
  analogWrite(pin_led_r, rojo);
  analogWrite(pin_led_g, verde);
  analogWrite(pin_led_b, azul);
}
