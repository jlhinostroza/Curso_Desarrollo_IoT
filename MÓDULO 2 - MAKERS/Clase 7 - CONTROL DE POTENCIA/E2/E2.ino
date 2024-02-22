/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 7
  Ejercicio: 2
  Mini proyecto: Luces con interruptor crepuscular

  PINOUT:
  (Módulo MOSFET):
  SIG -> D2

  (Potenciometro):
  S -> A1

  (LDR):
  S -> A0
---------------------------------------------*/

// Definición de pines
const int pinLDR = A0;        // Pin analógico para el LDR
const int pinPot = A1;        // Pin analógico para el potenciómetro
const int pinMOSFET = 2;      // Pin digital para el control del MOSFET

// Variables
int valorLDR = 0;        // Valor del LDR (0-1023)
int valorPot = 0;        // Valor del potenciómetro (0-1023)
int umbral = 0;          // Umbral de iluminación

void setup() {
  pinMode(pinLDR, INPUT);
  pinMode(pinPot, INPUT);
  pinMode(pinMOSFET, OUTPUT);

  // Inicialización del umbral con el valor inicial del potenciómetro
  valorPot = analogRead(pinPot);
  umbral = map(valorPot, 0, 1023, 0, 1023);

  Serial.begin(9600);
}

void loop() {
  // Lecturas de los sensores
  valorLDR = analogRead(pinLDR);
  valorPot = analogRead(pinPot);

  // Actualizar el umbral con el valor actual del potenciómetro
  umbral = map(valorPot, 0, 1023, 0, 1023);

  // Encender o apagar la luz según la iluminación
  if (valorLDR < umbral) {
    digitalWrite(pinMOSFET, HIGH);  // Encender la luz
    Serial.println("Luz encendida");
  } else {
    digitalWrite(pinMOSFET, LOW);   // Apagar la luz
    Serial.println("Luz apagada");
  }

  delay(1000);  // Pausa para evitar lecturas rápidas
}