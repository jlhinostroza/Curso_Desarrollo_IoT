/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 3
  Ejercicio: 1

  PINOUT:
  BOTON 1 -> D5
  BOTON 2 -> D6
  BOTON 3 -> D7

  LED VERDE -> D2
  LED AMARILLO -> D3
  LED ROJO -> D4
---------------------------------------------*/

//Declaración de pines
int bot1 = 5;
int bot2 = 6;
int bot3 = 7;

int verde = 2;
int amarillo = 3;
int rojo = 4;

//Setup
void setup() {
  pinMode(bot1, INPUT);
  pinMode(bot2, INPUT);
  pinMode(bot3, INPUT);

  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);
}

//Loop
void loop() {
  if (digitalRead(bot1) == HIGH) {
    digitalWrite(verde, HIGH);
  } else {
    digitalWrite(verde, LOW);
  }
  
  if (digitalRead(bot2) == HIGH) {
    digitalWrite(amarillo, HIGH);
  } else {
    digitalWrite(amarillo, LOW);
  }
  
  if (digitalRead(bot3) == HIGH) {
    digitalWrite(rojo, HIGH);
  } else {
    digitalWrite(rojo, LOW);
  }
}