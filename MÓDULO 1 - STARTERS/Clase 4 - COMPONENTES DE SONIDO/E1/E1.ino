/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 4
  Ejercicio: 1
  Mini proyecto: Teclado Arduino

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

int BUZZER_PIN = 13;
int BOTON_DO = 2;
int BOTON_RE = 3;
int BOTON_MI = 4;
int BOTON_FA = 5;
int BOTON_SOL = 6;
int BOTON_LA = 7;
int BOTON_SI = 8;

int duracion = 200;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BOTON_DO, INPUT);
  pinMode(BOTON_RE, INPUT);
  pinMode(BOTON_MI, INPUT);
  pinMode(BOTON_FA, INPUT);
  pinMode(BOTON_SOL, INPUT);
  pinMode(BOTON_LA, INPUT);
  pinMode(BOTON_SI, INPUT);
}

void loop() {
  if (digitalRead(BOTON_DO) == HIGH) {
    tone(BUZZER_PIN, 262, duracion);
    delay(500);
    noTone(BUZZER_PIN);
  }

  if (digitalRead(BOTON_RE) == HIGH) {
    tone(BUZZER_PIN, 294, duracion);
    delay(500);
    noTone(BUZZER_PIN);
  }

  if (digitalRead(BOTON_MI) == HIGH) {
    tone(BUZZER_PIN, 330, duracion);
    delay(500);
    noTone(BUZZER_PIN);
  }

  if (digitalRead(BOTON_FA) == HIGH) {
    tone(BUZZER_PIN, 349, duracion);
    delay(500);
    noTone(BUZZER_PIN);
  }

  if (digitalRead(BOTON_SOL) == HIGH) {
    tone(BUZZER_PIN, 392, duracion);
    delay(500);
    noTone(BUZZER_PIN);
  }

  if (digitalRead(BOTON_LA) == HIGH) {
    tone(BUZZER_PIN, 440, duracion);
    delay(500);
    noTone(BUZZER_PIN);
  }

  if (digitalRead(BOTON_SI) == HIGH) {
    tone(BUZZER_PIN, 494, duracion);
    delay(500);
    noTone(BUZZER_PIN);
  }
}