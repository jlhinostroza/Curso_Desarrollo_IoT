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

int buzzer_pin = 13;
int boton_do = 2;
int boton_re = 3;
int boton_mi = 4;
int boton_fa = 5;
int boton_sol = 6;
int boton_la = 7;
int boton_si = 8;

int duracion = 200;

void setup() {
  pinMode(buzzer_pin, OUTPUT);
  pinMode(boton_do, INPUT);
  pinMode(boton_re, INPUT);
  pinMode(boton_mi, INPUT);
  pinMode(boton_fa, INPUT);
  pinMode(boton_sol, INPUT);
  pinMode(boton_la, INPUT);
  pinMode(boton_si, INPUT);
}

void loop() {
  if (digitalRead(boton_do) == HIGH) {
    tone(buzzer_pin, 262, duracion);
    delay(500);
    noTone(buzzer_pin);
  }

  if (digitalRead(boton_re) == HIGH) {
    tone(buzzer_pin, 294, duracion);
    delay(500);
    noTone(buzzer_pin);
  }

  if (digitalRead(boton_mi) == HIGH) {
    tone(buzzer_pin, 330, duracion);
    delay(500);
    noTone(buzzer_pin);
  }

  if (digitalRead(boton_fa) == HIGH) {
    tone(buzzer_pin, 349, duracion);
    delay(500);
    noTone(buzzer_pin);
  }

  if (digitalRead(boton_sol) == HIGH) {
    tone(buzzer_pin, 392, duracion);
    delay(500);
    noTone(buzzer_pin);
  }

  if (digitalRead(boton_la) == HIGH) {
    tone(buzzer_pin, 440, duracion);
    delay(500);
    noTone(buzzer_pin);
  }

  if (digitalRead(boton_si) == HIGH) {
    tone(buzzer_pin, 494, duracion);
    delay(500);
    noTone(buzzer_pin);
  }
}