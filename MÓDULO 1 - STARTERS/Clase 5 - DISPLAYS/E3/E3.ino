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

// Configuración del LCD
int direccion_i2c = 0x27;  // Dirección del dispositivo I2C del LCD
int columnas_lcd = 16;     // Número de columnas del LCD
int filas_lcd = 2;         // Número de filas del LCD

// Crear una instancia de LiquidCrystal_I2C
LiquidCrystal_I2C lcd(direccion_i2c, columnas_lcd, filas_lcd);

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
  lcd.init();
  lcd.backlight();
  
  lcd.createChar(0, customChar);
  lcd.write(0);
}

void loop() {
}