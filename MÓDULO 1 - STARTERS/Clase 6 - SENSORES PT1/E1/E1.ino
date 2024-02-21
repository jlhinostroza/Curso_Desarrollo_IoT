/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 6
  Ejercicio: 1

  PINOUT:
  (PCF8574)
  SDA -> A4
  SCL -> A5

  (KY-037)
  AO -> A0
---------------------------------------------*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int SENSOR_PIN = A0  // Pin analógico al que está conectado el sensor KY037

// CONFIGURACIÓN LCD
int DIRECCION_I2C = 0x27;
int COLUMNAS_LCD = 16;
int FILAS_LCD = 2;

// Crear una instancia de LiquidCrystal_I2C
LiquidCrystal_I2C lcd(DIRECCION_I2C, COLUMNAS_LCD, FILAS_LCD);

void setup() {
  lcd.begin(16, 2);  // Inicialización del LCD 1602
  lcd.backlight();  // Encender retroiluminación
  lcd.setCursor(0, 0);
  lcd.print("Sensor KY037:");
}

void loop() {
  int valorSensor = analogRead(SENSOR_PIN);
  int porcentaje = map(valorSensor, 0, 1023, 0, 100);  // Mapear el valor a un rango de 0 a 100

  lcd.setCursor(0, 1);
  lcd.print("Valor: " + String(porcentaje) + "%   ");

  delay(500);  // Esperar medio segundo antes de la siguiente lectura
}
