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

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const byte Filas = 4;
const byte Columnas = 4;
char Teclado[Filas][Columnas] = {
  { '1', '2', '3', '+' },
  { '4', '5', '6', '-' },
  { '7', '8', '9', '*' },
  { 'C', '0', '=', '/' }
};
byte PinesFilas[Filas] = { 0, 1, 2, 3 };
byte PinesColumnas[Columnas] = { 4, 5, 6, 7 };

int direccion_teclado = 0x20;

Keypad_I2C kpd = Keypad_I2C(makeKeymap(Teclado), PinesFilas, PinesColumnas, Filas, Columnas, direccion_teclado);

boolean presentValue = false;
boolean next = false;
boolean final = false;
String num1, num2;
int answer;
char op;

void setup() {
  kpd.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  char key = kpd.getKey();
  if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0')) {
    if (presentValue != true) {
      num1 = num1 + key;
      int numLength = num1.length();
      lcd.setCursor(15 - numLength, 0);
      lcd.print(num1);
    } else {
      num2 = num2 + key;
      int numLength = num2.length();
      lcd.setCursor(15 - numLength, 1);
      lcd.print(num2);
      final = true;
    }
  } else if (presentValue == false && key != NO_KEY && (key == '/' || key == '*' || key == '-' || key == '+')) {
    if (presentValue == false) {
      presentValue = true;
      op = key;
      lcd.setCursor(15, 0);
      lcd.print(op);
    }
  } else if (final == true && key != NO_KEY && key == '=') {
    if (op == '+') {
      answer = num1.toInt() + num2.toInt();
    } else if (op == '-') {
      answer = num1.toInt() - num2.toInt();
    } else if (op == '*') {
      answer = num1.toInt() * num2.toInt();
    } else if (op == '/') {
      answer = num1.toInt() / num2.toInt();
    }
    lcd.clear();
    lcd.setCursor(15, 0);
    lcd.autoscroll();
    lcd.print(answer);
    lcd.noAutoscroll();
  } else if (key != NO_KEY && key == 'C') {
    lcd.clear();
    presentValue = false;
    final = false;
    num1 = "";
    num2 = "";
    answer = 0;
    op = ' ';
  }
}