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

// Dirección I2C de la pantalla LCD
int DIRECCION_I2C = 0x27;

// Número de columnas y filas de la pantalla LCD
int COLUMNAS_LCD = 16;
int FILAS_LCD = 2;

// Crear una instancia de LiquidCrystal_I2C
LiquidCrystal_I2C lcd(DIRECCION_I2C, COLUMNAS_LCD, FILAS_LCD);

void setup() {
  lcd.begin();      // Inicializar la pantalla LCD con I2C
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
  for (int i = 0; i < COLUMNAS_LCD; i++) {
    lcd.scrollDisplayRight();
    delay(200);
  }
  delay(1000);
  lcd.clear();

  // Desplazar el texto hacia la izquierda
  lcd.setCursor(0, 1);
  lcd.print("<- Desplazando");
  delay(1000);
  for (int i = 0; i < COLUMNAS_LCD; i++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }
  delay(1000);
  lcd.clear();
}
