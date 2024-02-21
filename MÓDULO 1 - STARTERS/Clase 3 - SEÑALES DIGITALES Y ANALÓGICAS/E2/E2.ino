/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 3
  Ejercicio: 2

  PINOUT:
  POTENCIOMETRO -> A0

  LED VERDE -> D2
  LED AMARILLO -> D3
  LED ROJO -> D4
---------------------------------------------*/

int POT_PIN = A0;
int VERDE_PIN = 2;
int AMARILLO_PIN = 3;
int ROJO_PIN = 4;

void setup() {
  //Serial.begin(9600);

  pinMode(VERDE_PIN, OUTPUT);
  pinMode(AMARILLO_PIN, OUTPUT);
  pinMode(ROJO_PIN, OUTPUT);
}

void loop() {
  int valPot = analogRead(POT_PIN); // Leer el valor del potenciómetro

  // Encender o apagar el LED verde
  if (valPot >= 341) {
    digitalWrite(VERDE_PIN, HIGH);
  } else {
    digitalWrite(VERDE_PIN, LOW);
  }
  
  // Encender o apagar el LED amarillo
  if (valPot >= 682) {
    digitalWrite(AMARILLO_PIN, HIGH);
  } else {
    digitalWrite(AMARILLO_PIN, LOW);
  }
  
  // Encender o apagar el LED rojo
  if (valPot >= 1023) {
    digitalWrite(ROJO_PIN, HIGH);
  } else {
    digitalWrite(ROJO_PIN, LOW);
  }

  //Serial.println(valPot);
  
}