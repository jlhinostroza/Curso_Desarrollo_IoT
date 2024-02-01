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
#define PIN_LDR A0        // Pin analógico para el LDR
#define PIN_POT A1        // Pin analógico para el potenciómetro
#define PIN_MOSFET 2      // Pin digital para el control del MOSFET

// Variables
int valorLDR = 0;        // Valor del LDR (0-1023)
int valorPot = 0;        // Valor del potenciómetro (0-1023)
int umbral = 0;          // Umbral de iluminación

void setup() {
  pinMode(PIN_LDR, INPUT);
  pinMode(PIN_POT, INPUT);
  pinMode(PIN_MOSFET, OUTPUT);

  // Inicialización del umbral con el valor inicial del potenciómetro
  valorPot = analogRead(PIN_POT);
  umbral = map(valorPot, 0, 1023, 0, 1023);

  Serial.begin(9600);
}

void loop() {
  // Lecturas de los sensores
  valorLDR = analogRead(PIN_LDR);
  valorPot = analogRead(PIN_POT);

  // Actualizar el umbral con el valor actual del potenciómetro
  umbral = map(valorPot, 0, 1023, 0, 1023);

  // Encender o apagar la luz según la iluminación
  if (valorLDR < umbral) {
    digitalWrite(PIN_MOSFET, HIGH);  // Encender la luz
    Serial.println("Luz encendida");
  } else {
    digitalWrite(PIN_MOSFET, LOW);   // Apagar la luz
    Serial.println("Luz apagada");
  }

  delay(1000);  // Pausa para evitar lecturas rápidas
}