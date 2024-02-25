/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 5
  Ejercicio: 2

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

void setup() {
  lcd.init();      // Inicializar la pantalla LCD con I2C
  lcd.backlight();  // Encender el backlight (si tu módulo LCD I2C tiene retroiluminación)

  // Mostrar un mensaje de bienvenida
  lcd.setCursor(0, 0);
  lcd.print("Hola, LCD con I2C!");

  delay(2000);  // Esperar 2 segundos
  lcd.clear();  // Limpiar la pantalla
}

void loop() {
  // Desplazar el texto hacia la derecha
  lcd.setCursor(0, 0);
  lcd.print("Desplazando ->");
  delay(1000);
  for (int i = 0; i < columnas_lcd; i++) {
    lcd.scrollDisplayRight();
    delay(200);
  }
  delay(1000);
  lcd.clear();

  // Desplazar el texto hacia la izquierda
  lcd.setCursor(0, 1);
  lcd.print("<- Desplazando");
  delay(1000);
  for (int i = 0; i < columnas_lcd; i++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }
  delay(1000);
  lcd.clear();
}
