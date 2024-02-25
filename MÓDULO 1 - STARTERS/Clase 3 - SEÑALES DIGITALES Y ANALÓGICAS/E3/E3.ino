/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 3
  Ejercicio: 3
  
  PINOUT:
  POTENCIOMETRO -> A0
  LED VERDE -> D2
  LED AMARILLO -> D3
  LED ROJO -> D4
---------------------------------------------*/

int pinVerde = 3;
int pinAmarillo = 5;
int pinRojo = 6;
int pinPot = A0;

void setup() {
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinRojo, OUTPUT);
}

void loop() {
  int valPot = analogRead(pinPot); // Leer el valor del potenciómetro

  // Ajustar el brillo de los LEDs basado en el valor del potenciómetro
  int brillo = map(valPot, 0, 1023, 0, 255); // Mapear el valor del potenciómetro al rango de brillo (0-255)

  analogWrite(pinVerde, brillo);
  analogWrite(pinAmarillo, brillo);
  analogWrite(pinRojo, brillo);
  
  delay(10); // Pequeña pausa para estabilidad
}