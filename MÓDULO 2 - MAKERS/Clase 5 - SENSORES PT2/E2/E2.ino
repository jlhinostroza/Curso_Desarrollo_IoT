/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 5
  Ejercicio: 2

  PINOUT:
  (DHT11)
  S -> D2

  (Pulsador)
  Term -> D3
---------------------------------------------*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

const int pinDHT = 2;
const int pinBoton = 3;

DHT dht(pinDHT, DHT11);

// Configuración del LCD
int direccion_i2c = 0x27;  // Dirección del dispositivo I2C del LCD
int columnas_lcd = 16;     // Número de columnas del LCD
int filas_lcd = 2;         // Número de filas del LCD

// Crear una instancia de LiquidCrystal_I2C
LiquidCrystal_I2C lcd(direccion_i2c, columnas_lcd, filas_lcd);

const int MODO_TEMPERATURA = 0;
const int MODO_HUMEDAD = 1;

int modoActual = MODO_TEMPERATURA;

void setup() {
  Serial.begin(9600);

  pinMode(pinBoton, INPUT);

  lcd.init();
  lcd.backlight();

  dht.begin();

  mostrarTemperatura();  // Mostrar la temperatura al inicio
}

void loop() {
  if (digitalRead(pinBoton) == LOW) {
    cambiarModo();
    delay(500); // Debounce para evitar múltiples detecciones del botón con un solo toque
  }
}

void cambiarModo() {
  if (modoActual == MODO_TEMPERATURA) {
    mostrarHumedad();
    modoActual = MODO_HUMEDAD;
  } else {
    mostrarTemperatura();
    modoActual = MODO_TEMPERATURA;
  }
}

void mostrarTemperatura() {
  float temperatura = dht.readTemperature();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");
  lcd.setCursor(0, 1);
  lcd.print(temperatura);
  lcd.print(" C");
}

void mostrarHumedad() {
  float humedad = dht.readHumidity();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humedad:");
  lcd.setCursor(0, 1);
  lcd.print(humedad);
  lcd.print(" %");
}
