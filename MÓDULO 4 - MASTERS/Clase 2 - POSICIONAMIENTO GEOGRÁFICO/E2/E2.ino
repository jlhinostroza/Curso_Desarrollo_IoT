/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Masters
  Clase: 2
  Ejercicio: 2

  PINOUT:
  (PCF8574)
  SDA -> D21
  SCL -> D22

  (NEO 6M)
  TX -> RX2
  RX -> TX2
---------------------------------------------*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TinyGPS++.h>

const int pinRX = 16;
const int pinTX = 17;

HardwareSerial neogps(1);

// Configuración del LCD
int direccion_i2c = 0x27;
int columnas_lcd = 16;
int filas_lcd = 2;

// Crear una instancia de LiquidCrystal_I2C
LiquidCrystal_I2C lcd(direccion_i2c, columnas_lcd, filas_lcd);

// Crear una instancia de TinyGPS++
TinyGPSPlus gps;

void setup() {
  Serial.begin(115200);
  neogps.begin(9600, SERIAL_8N1, pinRX, pinTX);

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  lcd.clear();
  lcd.print("LAT: ");
  lcd.print(gps.location.lat(), 6);
  lcd.setCursor(0, 1);
  lcd.print("LON: ");
  lcd.print(gps.location.lng(), 6);
  delay(2000);

  lcd.clear();
  lcd.print("VEL: ");
  lcd.print(gps.speed.kmph());
  lcd.print("Km/h");
  lcd.setCursor(0, 1);
  lcd.print("SAT: ");
  lcd.print(gps.satellites.value());
  delay(2000);

  lcd.clear();
  lcd.print("ALT: ");
  lcd.print(gps.altitude.meters(), 0);
  delay(2000);

  lcd.clear();
  lcd.print("HOR: ");
  lcd.print(gps.time.hour());
  lcd.print(":");
  lcd.print(gps.time.minute());
  lcd.print(":");
  lcd.print(gps.time.second());
  lcd.setCursor(0, 1);
  lcd.print("FEC: ");
  lcd.print(gps.date.day());
  lcd.print("/");
  lcd.print(gps.date.month());
  lcd.print("/");
  lcd.print(gps.date.year());
  delay(2000);
}