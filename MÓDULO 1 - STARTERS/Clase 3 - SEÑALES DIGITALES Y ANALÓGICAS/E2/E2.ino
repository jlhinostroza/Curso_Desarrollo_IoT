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

int pinPot = A0;
int pinVerde = 2;
int pinAmarillo = 3;
int pinRojo = 4;

void setup() {
  //Serial.begin(9600);

  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinRojo, OUTPUT);
}

void loop() {
  int valPot = analogRead(pinPot); // Leer el valor del potenciómetro

  // Encender o apagar el LED verde
  if (valPot >= 341) {
    digitalWrite(pinVerde, HIGH);
  } else {
    digitalWrite(pinVerde, LOW);
  }
  
  // Encender o apagar el LED amarillo
  if (valPot >= 682) {
    digitalWrite(pinAmarillo, HIGH);
  } else {
    digitalWrite(pinAmarillo, LOW);
  }
  
  // Encender o apagar el LED rojo
  if (valPot >= 1023) {
    digitalWrite(pinRojo, HIGH);
  } else {
    digitalWrite(pinRojo, LOW);
  }

  //Serial.println(valPot);
  
}