/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 3
  Ejercicio: 1
  Mini proyecto: Reloj digital
---------------------------------------------*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

#define botonPin 2

RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int estadoBotonAnterior = HIGH;
int estadoBotonActual;
bool mostrarHora = true;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();
  
  if (!rtc.begin()) {
    Serial.println("No se pudo encontrar el RTC");
    while (1);
  }

  pinMode(botonPin, INPUT);
}

void loop() {
  DateTime now = rtc.now();
  estadoBotonActual = digitalRead(botonPin);

  if (estadoBotonActual == LOW && estadoBotonAnterior == HIGH) {
    mostrarHora = !mostrarHora;  // Cambiar el estado al pulsar el botón
    delay(250);  // Pequeño retardo para evitar rebotes
  }

  estadoBotonAnterior = estadoBotonActual;

  if (mostrarHora) {
    mostrarHoraLCD(now);
  } else {
    mostrarFechaLCD(now);
  }

  delay(500);  // Ajusta este valor según sea necesario
}

void mostrarHoraLCD(DateTime now) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hora: ");
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  lcd.print(now.minute(), DEC);
  lcd.print(":");
  lcd.print(now.second(), DEC);
}

void mostrarFechaLCD(DateTime now) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fecha: ");
  lcd.print(now.day(), DEC);
  lcd.print("/");
  lcd.print(now.month(), DEC);
  lcd.print("/");
  lcd.print(now.year(), DEC);
}
