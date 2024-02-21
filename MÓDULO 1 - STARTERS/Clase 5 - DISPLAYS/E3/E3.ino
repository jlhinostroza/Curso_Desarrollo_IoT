/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 5
  Ejercicio: 3

  PINOUT:
  SDA -> A4
  SCL -> A5
---------------------------------------------*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección I2C de la pantalla LCD
int DIRECCION_I2C = 0x27;

// Número de columnas y filas de la pantalla LCD
int COLUMNAS_LCD = 16;
int FILAS_LCD = 2;

// Crear una instancia de LiquidCrystal_I2C
LiquidCrystal_I2C lcd(DIRECCION_I2C, COLUMNAS_LCD, FILAS_LCD);

byte customChar[] = {
  B00100,
  B00010,
  B01001,
  B00001,
  B00001,
  B01001,
  B00010,
  B00100
};

void setup() {
  lcd.begin();
  lcd.createChar(0, customChar);
  lcd.home();
  lcd.write(0);
}

void loop() {
}