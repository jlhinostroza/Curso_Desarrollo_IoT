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

#define PIN_SENSOR A0        // Pin analógico al que está conectado el sensor LM35
#define DIRECCION_LCD 0x27   // Dirección I2C del LCD 1602

LiquidCrystal_I2C lcd(DIRECCION_LCD, 16, 2);  // Inicialización del LCD 1602

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
