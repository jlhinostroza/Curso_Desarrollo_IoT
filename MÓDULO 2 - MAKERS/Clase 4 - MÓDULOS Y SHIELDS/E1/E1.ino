/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 4
  Ejercicio: 1
  Mini proyecto: Calculadora

  PINOUT:
  (PCF8574)
  SDA -> A4
  SCL -> A5
---------------------------------------------*/

#include <Keypad_I2C.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuración del LCD
int direccion_i2c = 0x27;  // Dirección del dispositivo I2C del LCD
int columnas_lcd = 16;     // Número de columnas del LCD
int filas_lcd = 2;         // Número de filas del LCD

// Crear una instancia de LiquidCrystal_I2C
LiquidCrystal_I2C lcd(direccion_i2c, columnas_lcd, filas_lcd);

// Definir el teclado numérico y sus pines
const int filas = 4;
const int columnas = 4;
char teclado[filas][columnas] = {
  { '1', '2', '3', '+' },
  { '4', '5', '6', '-' },
  { '7', '8', '9', '*' },
  { 'C', '0', '=', '/' }
};
byte pines_filas[filas] = { 0, 1, 2, 3 };
byte pines_columnas[columnas] = { 4, 5, 6, 7 };

int direccion_teclado = 0x20; // Dirección del dispositivo I2C del teclado

Keypad_I2C kpd = Keypad_I2C(makeKeymap(teclado), pines_filas, pines_columnas, filas, columnas, direccion_teclado);

// Variables para almacenar números y operaciones
String num1, num2;
char op;

void setup() {
  // Inicializar el teclado y el LCD
  kpd.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  char key = kpd.getKey(); // Leer la tecla presionada

  // Si se presionó un número, agregarlo al número actual que se está formando
  if (key != NO_KEY && isDigit(key)) {
    if (op == '\0') {
      num1 += key;
    } else {
      num2 += key;
    }
    actualizar_lcd();
  }
  
  // Si se presionó una operación, guardarla y mostrarla en el LCD
  if (key != NO_KEY && strchr("+-*/", key)) {
    op = key;
    lcd.setCursor(15, 0);
    lcd.print(op);
  }
  
  // Si se presionó la tecla de igual, calcular el resultado y mostrarlo en el LCD
  if (key != NO_KEY && key == '=') {
    calcular_resultado();
  }
  
  // Si se presionó la tecla de limpiar (C), reiniciar todos los valores
  if (key != NO_KEY && key == 'C') {
    reiniciar_calculadora();
  }
}

// Función para actualizar el contenido del LCD con los números actuales
void actualizar_lcd() {
  lcd.setCursor(15 - num1.length(), 0);
  lcd.print(num1);
  lcd.setCursor(15 - num2.length(), 1);
  lcd.print(num2);
}

// Función para calcular el resultado y mostrarlo en el LCD
void calcular_resultado() {
  int resultado = 0;
  int n1 = num1.toInt();
  int n2 = num2.toInt();
  
  switch (op) {
    case '+':
      resultado = n1 + n2;
      break;
    case '-':
      resultado = n1 - n2;
      break;
    case '*':
      resultado = n1 * n2;
      break;
    case '/':
      if (n2 != 0) {
        resultado = n1 / n2;
      } else {
        lcd.clear();
        lcd.print("Error: Div/0");
        delay(2000);
        reiniciar_calculadora();
        return;
      }
      break;
  }
  
  lcd.clear();
  lcd.print(resultado);
}

// Función para reiniciar todos los valores de la calculadora
void reiniciar_calculadora() {
  num1 = "";
  num2 = "";
  op = '\0';
  lcd.clear();
}
