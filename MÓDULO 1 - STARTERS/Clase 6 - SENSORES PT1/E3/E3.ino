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

int PIN_SENSOR = A0        // Pin analógico al que está conectado el sensor LM35

// CONFIGURACIÓN LCD
int DIRECCION_I2C = 0x27;
int COLUMNAS_LCD = 16;
int FILAS_LCD = 2;

// Crear una instancia de LiquidCrystal_I2C
LiquidCrystal_I2C lcd(DIRECCION_I2C, COLUMNAS_LCD, FILAS_LCD);

void setup() {
  lcd.begin(16, 2);  // Inicialización del LCD 1602
  lcd.backlight();   // Encender retroiluminación
  lcd.setCursor(0, 0);
  lcd.print("Temperatura (C):");
}

void loop() {
  int lecturaSensor = analogRead(PIN_SENSOR);

  // Convertir el valor analógico a temperatura en grados Celsius
  float temperaturaC = (lecturaSensor * 5.0 / 1024.0) * 100.0;

  // Mostrar la temperatura en el LCD
  lcd.setCursor(0, 1);
  lcd.print("Temp: " + String(temperaturaC, 1) + " *C   ");

  delay(500);  // Esperar medio segundo antes de la siguiente lectura
}
