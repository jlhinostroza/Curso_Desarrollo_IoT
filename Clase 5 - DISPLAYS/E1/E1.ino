/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 5
  Ejercicio: 1

  PINOUT:
  RS -> D0
  E -> D1
  DB4 -> D2
  DB5 -> D3
  DB6 -> D4
  DB7 -> D5
---------------------------------------------*/

#include <LiquidCrystal.h>

// Definición de pines para la conexión al LCD
#define RS 0
#define E 1
#define D4 2
#define D5 3
#define D6 4
#define D7 5

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

int contador = 0;

void setup() {
  lcd.begin(16, 2); // Inicializar la pantalla LCD 16x2
  lcd.print("Hola, Mundo!");
}

void loop() {
  lcd.setCursor(0, 1); // Establecer el cursor en la segunda línea
  lcd.print("Contador: ");
  
  lcd.setCursor(10, 1); // Establecer el cursor en la posición del contador
  lcd.print(contador);
  
  delay(1000); // Esperar 1 segundo
  lcd.clear(); // Limpiar la pantalla antes de imprimir el siguiente valor del contador
  
  contador++; // Aumentar el contador
}
