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

int PIN_FOTORRESISTOR = A0;   // Pin analógico al que está conectado el fotorresistor

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
  lcd.print("Luz Ambiental:");
}

void loop() {
  int lecturaFotorresistor = analogRead(PIN_FOTORRESISTOR);

  // Mapear el valor del fotorresistor a un rango de 0 a 100 (porcentaje)
  int nivelLuz = map(lecturaFotorresistor, 0, 1023, 0, 100);

  // Mostrar el nivel de luz en el LCD
  lcd.setCursor(0, 1);
  lcd.print("Luz: " + String(nivelLuz) + "%   ");

  delay(500);  // Esperar medio segundo antes de la siguiente lectura
}
