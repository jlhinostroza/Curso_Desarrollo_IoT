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

#define DHT_PIN 2
#define BOTON_PIN 3

DHT dht(DHT_PIN, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

enum ModoPantalla {
  TEMPERATURA,
  HUMEDAD
};

ModoPantalla modoActual = TEMPERATURA;

void setup() {
  Serial.begin(9600);

  pinMode(BOTON_PIN, INPUT);

  lcd.begin(16, 2);
  lcd.backlight();

  dht.begin();

  mostrarTemperatura();  // Mostrar la temperatura al inicio
}

void loop() {
  if (digitalRead(BOTON_PIN) == LOW) {
    cambiarModo();
    delay(500); // Debounce para evitar múltiples detecciones del botón con un solo toque
  }
}

void cambiarModo() {
  if (modoActual == TEMPERATURA) {
    mostrarHumedad();
    modoActual = HUMEDAD;
  } else {
    mostrarTemperatura();
    modoActual = TEMPERATURA;
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
