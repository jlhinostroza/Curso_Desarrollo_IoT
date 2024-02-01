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

#define VERDE_PIN 3
#define AMARILLO_PIN 5
#define ROJO_PIN 6
#define POT_PIN A0

void setup() {
  pinMode(VERDE_PIN, OUTPUT);
  pinMode(AMARILLO_PIN, OUTPUT);
  pinMode(ROJO_PIN, OUTPUT);
}

void loop() {
  int valPot = analogRead(POT_PIN); // Leer el valor del potenciómetro

  // Ajustar el brillo de los LEDs basado en el valor del potenciómetro
  int brillo = map(valPot, 0, 1023, 0, 255); // Mapear el valor del potenciómetro al rango de brillo (0-255)

  analogWrite(VERDE_PIN, brillo);
  analogWrite(AMARILLO_PIN, brillo);
  analogWrite(ROJO_PIN, brillo);
  
  delay(10); // Pequeña pausa para estabilidad
}