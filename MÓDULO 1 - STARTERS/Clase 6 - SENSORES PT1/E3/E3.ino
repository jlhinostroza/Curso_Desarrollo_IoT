/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 6
  Ejercicio: 3

  PINOUT:
  (PCF8574)
  SDA -> A4
  SCL -> A5

  (LM35)
  OUT -> A0
---------------------------------------------*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int pinSensor = A0;  // Pin analógico al que está conectado el sensor LM35

// Configuración del LCD
int direccion_i2c = 0x27;  // Dirección del dispositivo I2C del LCD
int columnas_lcd = 16;     // Número de columnas del LCD
int filas_lcd = 2;         // Número de filas del LCD

// Crear una instancia de LiquidCrystal_I2C
LiquidCrystal_I2C lcd(direccion_i2c, columnas_lcd, filas_lcd);

void setup() {
  lcd.begin(16, 2);  // Inicialización del LCD 1602
  lcd.backlight();   // Encender retroiluminación
  lcd.setCursor(0, 0);
  lcd.print("Temperatura (C):");
}

void loop() {
  int lecturaSensor = analogRead(pinSensor);

  // Convertir el valor analógico a temperatura en grados Celsius
  float temperaturaC = (lecturaSensor * 5.0 / 1024.0) * 100.0;

  // Mostrar la temperatura en el LCD
  lcd.setCursor(0, 1);
  lcd.print("Temp: " + String(temperaturaC, 1) + " *C   ");

  delay(500);  // Esperar medio segundo antes de la siguiente lectura
}
