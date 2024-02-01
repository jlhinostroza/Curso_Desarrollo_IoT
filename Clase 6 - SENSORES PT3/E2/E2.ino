/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 6
  Ejercicio: 2
  PINOUT:
  (MPU6050):
  SCL -> A5
  SDA -> A4
  INT -> D2
---------------------------------------------*/

#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

MPU6050 sensor;

int ax, ay, az;

// Definición de pines para LEDs RGB
#define LED_X_POS  4  // Cambiado a azul
#define LED_X_NEG  3  // Cambiado a rojo
#define LED_Y_POS  6  // Cambiado a amarillo
#define LED_Y_NEG  5  // Cambiado a verde

void setup() {
  Serial.begin(57600);
  Wire.begin();
  sensor.initialize();

  if (sensor.testConnection()) 
    Serial.println("Sensor iniciado correctamente");
  else 
    Serial.println("Error al iniciar el sensor");

  // Configuración de pines para LEDs RGB
  pinMode(LED_X_POS, OUTPUT);
  pinMode(LED_X_NEG, OUTPUT);
  pinMode(LED_Y_POS, OUTPUT);
  pinMode(LED_Y_NEG, OUTPUT);
}

void loop() {
  sensor.getAcceleration(&ax, &ay, &az);

  // Calcular los ángulos de inclinación
  float accel_ang_x = atan(ax / sqrt(pow(ay, 2) + pow(az, 2))) * (180.0 / 3.14);
  float accel_ang_y = atan(ay / sqrt(pow(ax, 2) + pow(az, 2))) * (180.0 / 3.14);

  // Mostrar los ángulos
  Serial.print("Inclinacion en X: ");
  Serial.print(accel_ang_x);
  Serial.print("\tInclinacion en Y: ");
  Serial.println(accel_ang_y);

  // Encender LEDs según la inclinación
  digitalWrite(LED_X_POS, accel_ang_x > 10);  // Azul
  digitalWrite(LED_X_NEG, accel_ang_x < -10);  // Rojo
  digitalWrite(LED_Y_POS, accel_ang_y > 10);  // Amarillo
  digitalWrite(LED_Y_NEG, accel_ang_y < -10);  // Verde

  delay(500);
}