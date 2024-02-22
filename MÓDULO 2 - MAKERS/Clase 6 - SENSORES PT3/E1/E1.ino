/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 6
  Ejercicio: 1

  PINOUT:
  (TCS230):
  S0 -> D4
  S1 -> D5
  S2 -> D6
  S3 -> D7
  OUT -> D8

  (Led RGB):
  R -> D12
  G -> D11
  B -> D10
---------------------------------------------*/

// Definición de pines para el sensor TCS230
const int S0 = 4;
const int S1 = 5;
const int S2 = 6;
const int S3 = 7;
const int OUT = 8;

// Definición de pines para el LED RGB
const int pinRojo = 12;
const int pinVerde = 11;
const int pinAzul = 10;

void setup() {
  // Configuración de pines para el sensor TCS230
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  // Configuración de pines para el LED RGB
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);

  // Configuración de la frecuencia de muestreo para el sensor (opcional)
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
}

void loop() {
  // Leer el valor del sensor para obtener el color
  int valorRojo = obtenerColor(LOW, LOW);
  int valorVerde = obtenerColor(HIGH, HIGH);
  int valorAzul = obtenerColor(LOW, HIGH);

  // Encender el LED RGB con el color detectado
  analogWrite(pinRojo, valorRojo);
  analogWrite(pinVerde, valorVerde);
  analogWrite(pinAzul, valorAzul);
}

// Función para obtener el valor de color del sensor
int obtenerColor(int estadoS2, int estadoS3) {
  digitalWrite(S2, estadoS2);
  digitalWrite(S3, estadoS3);
  
  return pulseIn(OUT, HIGH);
}
