/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Starters
  Clase: 6
  Ejercicio: 2

  PINOUT:
  (PCF8574)
  SDA -> A4
  SCL -> A5

  (HC-SR04)
  TRIG -> D3
  ECHO -> D2
---------------------------------------------*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int PIN_TRIG = 3  // Pin de control TRIG del sensor HC-SR04
int PIN_ECHO = 2  // Pin de lectura ECHO del sensor HC-SR04

// CONFIGURACIÓN LCD
int DIRECCION_I2C = 0x27;
int COLUMNAS_LCD = 16;
int FILAS_LCD = 2;

// Crear una instancia de LiquidCrystal_I2C
LiquidCrystal_I2C lcd(DIRECCION_I2C, COLUMNAS_LCD, FILAS_LCD);

void setup() {
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  lcd.begin(16, 2);  // Inicialización del LCD 1602

  lcd.backlight();  // Encender retroiluminación
  lcd.setCursor(0, 0);
  lcd.print("Sensor HC-SR04:");
}

void loop() {
  // Generar un pulso corto en el pin TRIG para activar el sensor
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  // Medir la duración del pulso en el pin ECHO
  long duracionPulso = pulseIn(PIN_ECHO, HIGH);

  // Calcular la distancia en centímetros (la velocidad del sonido es de 343 m/s)
  float distancia = duracionPulso * 0.034 / 2;

  // Mostrar la distancia en el LCD
  lcd.setCursor(0, 1);
  lcd.print("Distancia: " + String(distancia) + " cm   ");

  delay(500);  // Esperar medio segundo antes de la siguiente lectura
}