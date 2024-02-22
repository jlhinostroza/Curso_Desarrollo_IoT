/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 4
  Ejercicio: 2

  PINOUT:
  BUZZER (+) -> D13
  BOTON DO -> D2
  BOTON RE -> D3
  BOTON MI -> D4
  BOTON FA -> D5
  BOTON SOL -> D6
  BOTON LA -> D7
  BOTON SI -> D8
---------------------------------------------*/

int ZumbadorPin = 13;

int c = 261;
int d = 294;
int e = 329;
int f = 349;
int g = 391;
int gS = 415;
int a = 440;
int aS = 455;
int b = 466;
int cH = 523;
int cSH = 554;
int dH = 587;
int dSH = 622;
int eH = 659;
int fH = 698;
int fSH = 740;
int gH = 783;
int gSH = 830;
int aH = 880;


void setup() {

  pinMode(ZumbadorPin, OUTPUT);  // definimos la variable ZumbadorPin como una salida.
}

void loop() {
  tone(ZumbadorPin, a, 500);
  delay(500 + 50);
  tone(ZumbadorPin, a, 500);
  delay(500 + 50);
  tone(ZumbadorPin, a, 500);
  delay(500 + 50);
  tone(ZumbadorPin, f, 350);
  delay(350 + 50);
  tone(ZumbadorPin, cH, 150);
  delay(150 + 50);

  tone(ZumbadorPin, a, 500);
  delay(500 + 50);
  tone(ZumbadorPin, f, 350);
  delay(350 + 50);
  tone(ZumbadorPin, cH, 150);
  delay(150 + 50);
  tone(ZumbadorPin, a, 1000);
  delay(1000 + 50);

  tone(ZumbadorPin, eH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, eH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, eH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, fH, 350);
  delay(350 + 50);
  tone(ZumbadorPin, cH, 150);
  delay(150 + 50);

  tone(ZumbadorPin, gS, 500);
  delay(500 + 50);
  tone(ZumbadorPin, f, 350);
  delay(350 + 50);
  tone(ZumbadorPin, cH, 150);
  delay(150 + 50);
  tone(ZumbadorPin, a, 1000);
  delay(1000 + 50);

  tone(ZumbadorPin, aH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, a, 350);
  delay(350 + 50);
  tone(ZumbadorPin, a, 150);
  delay(150 + 50);
  tone(ZumbadorPin, aH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, gSH, 250);
  delay(250 + 50);
  tone(ZumbadorPin, gH, 250);
  delay(250 + 50);

  tone(ZumbadorPin, fSH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, fH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, fSH, 250);
  delay(250 + 50);
  delay(250);
  tone(ZumbadorPin, aS, 250);
  delay(250 + 50);
  tone(ZumbadorPin, dSH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, dH, 250);
  delay(250 + 50);
  tone(ZumbadorPin, cSH, 250);
  delay(250 + 50);

  tone(ZumbadorPin, cH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, b, 125);
  delay(125 + 50);
  tone(ZumbadorPin, cH, 250);
  delay(250 + 50);
  delay(250);
  tone(ZumbadorPin, f, 125);
  delay(125 + 50);
  tone(ZumbadorPin, gS, 500);
  delay(500 + 50);
  tone(ZumbadorPin, f, 375);
  delay(375 + 50);
  tone(ZumbadorPin, a, 125);
  delay(125 + 50);

  tone(ZumbadorPin, cH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, a, 375);
  delay(375 + 50);
  tone(ZumbadorPin, cH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, eH, 1000);
  delay(1000 + 50);


  tone(ZumbadorPin, aH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, a, 350);
  delay(350 + 50);
  tone(ZumbadorPin, a, 150);
  delay(150 + 50);
  tone(ZumbadorPin, aH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, gSH, 250);
  delay(250 + 50);
  tone(ZumbadorPin, gH, 250);
  delay(250 + 50);

  tone(ZumbadorPin, fSH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, fH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, fSH, 250);
  delay(250 + 50);
  delay(250);
  tone(ZumbadorPin, aS, 250);
  delay(250 + 50);
  tone(ZumbadorPin, dSH, 500);
  delay(500 + 50);
  tone(ZumbadorPin, dH, 250);
  delay(250 + 50);
  tone(ZumbadorPin, cSH, 250);
  delay(250 + 50);


  tone(ZumbadorPin, cH, 125);
  delay(125 + 50);
  tone(ZumbadorPin, b, 125);
  delay(125 + 50);
  tone(ZumbadorPin, cH, 250);
  delay(250 + 50);
  delay(250);
  tone(ZumbadorPin, f, 250);
  delay(250 + 50);
  tone(ZumbadorPin, gS, 500);
  delay(500 + 50);
  tone(ZumbadorPin, f, 375);
  delay(375 + 50);
  tone(ZumbadorPin, cH, 125);
  delay(125 + 50);

  tone(ZumbadorPin, a, 500);
  delay(500 + 50);
  tone(ZumbadorPin, f, 375);
  delay(375 + 50);
  tone(ZumbadorPin, c, 125);
  delay(125 + 50);
  tone(ZumbadorPin, a, 1000);
  delay(1000 + 50);

  delay(2000);  // dos segundos para volver a empezar.
}