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

int pinTrig = 3;  // Pin de control TRIG del sensor HC-SR04
int pinEcho = 2;  // Pin de lectura ECHO del sensor HC-SR04

// Configuración del LCD
int direccion_i2c = 0x27;  // Dirección del dispositivo I2C del LCD
int columnas_lcd = 16;     // Número de columnas del LCD
int filas_lcd = 2;         // Número de filas del LCD

// Crear una instancia de LiquidCrystal_I2C
LiquidCrystal_I2C lcd(direccion_i2c, columnas_lcd, filas_lcd);

void setup() {
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);

  lcd.begin(16, 2);  // Inicialización del LCD 1602

  lcd.backlight();  // Encender retroiluminación
  lcd.setCursor(0, 0);
  lcd.print("Sensor HC-SR04:");
}

void loop() {
  // Generar un pulso corto en el pin TRIG para activar el sensor
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  // Medir la duración del pulso en el pin ECHO
  long duracionPulso = pulseIn(pinEcho, HIGH);

  // Calcular la distancia en centímetros (la velocidad del sonido es de 343 m/s)
  float distancia = duracionPulso * 0.034 / 2;

  // Mostrar la distancia en el LCD
  lcd.setCursor(0, 1);
  lcd.print("Distancia: " + String(distancia) + " cm   ");

  delay(500);  // Esperar medio segundo antes de la siguiente lectura
}