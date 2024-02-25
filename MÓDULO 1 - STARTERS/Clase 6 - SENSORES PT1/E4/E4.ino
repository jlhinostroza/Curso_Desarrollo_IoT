/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 6
  Ejercicio: 4

  PINOUT:
  (PCF8574)
  SDA -> A4
  SCL -> A5

  (LDR)
  OUT -> A0
---------------------------------------------*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int pinFoto = A0;   // Pin analógico al que está conectado el fotorresistor

// Configuración del LCD
int direccion_i2c = 0x27;  // Dirección del dispositivo I2C del LCD
int columnas_lcd = 16;     // Número de columnas del LCD
int filas_lcd = 2;         // Número de filas del LCD

// Crear una instancia de LiquidCrystal_I2C
LiquidCrystal_I2C lcd(direccion_i2c, columnas_lcd, filas_lcd);

void setup() {
  lcd.init();  // Inicialización del LCD 1602
  lcd.backlight();   // Encender retroiluminación

  lcd.setCursor(0, 0);
  lcd.print("Luz Ambiental:");
}

void loop() {
  int valFotorresistor = analogRead(pinFoto);

  // Mapear el valor del fotorresistor a un rango de 0 a 100 (porcentaje)
  int nivelLuz = map(valFotorresistor, 0, 1023, 0, 100);

  // Mostrar el nivel de luz en el LCD
  lcd.setCursor(0, 1);
  lcd.print("Luz: " + String(nivelLuz) + "%   ");

  delay(500);  // Esperar medio segundo antes de la siguiente lectura
}
