/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Masters
  Clase: 1
  Ejercicio: 1

  PINOUT:
  (SIM800L)
  TX -> D4
  RX -> D2

  (LM35)
  VOUT -> D15
---------------------------------------------*/

#include <SoftwareSerial.h>

// Configuración de pines 
const int sim800TxPin = 4;
const int sim800RxPin = 2;
const int lm35Pin = 15;
const int ledVerde = 18;
const int ledRojo = 19;

// Número de teléfono al que se enviarán los mensajes SMS
const char* numeroDestino = "+51*********"; //CAMBIAR

// Variable para almacenar el estado del sensor
bool sensorActivo = false;

// Objeto para comunicación con el módulo SIM800L
SoftwareSerial sim800(sim800TxPin, sim800RxPin);

void setup() {
  // Inicialización de la comunicación serial con velocidad de 9600 baudios
  Serial.begin(115200);
  sim800.begin(9600);
  
  pinMode(lm35Pin, INPUT);
}

void loop() {
  // Verificar si se ha recibido un mensaje SMS
  if (sim800.available()) {
    String sms = sim800.readString();
    sms.trim(); // Eliminar espacios en blanco al principio y al final
    
    // Procesar el mensaje SMS recibido
    if (sms.equalsIgnoreCase("On")) {
      sensorActivo = true;
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledRojo, LOW);
    } 
    
    else if (sms.equalsIgnoreCase("Off")) {
      sensorActivo = false;
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledRojo, HIGH);
    }
  }
  
  // Si el sensor está activo, enviar los valores cada 5 segundos
  if (sensorActivo) {
    float temperatura = leerTemperatura();
    enviarSMS(numeroDestino, "Temperatura: " + String(temperatura) + " °C");
    delay(5000); // Esperar 5 segundos
  }
}

// Función para leer la temperatura del sensor LM35
float leerTemperatura() {
  int lectura = analogRead(lm35Pin);
  float temperatura = (lectura * 3.3) / 4095 * 100; // Convertir lectura a temperatura en grados Celsius
  return temperatura;
}

// Función para enviar un mensaje SMS
void enviarSMS(const char* numero, const String& mensaje) {
  sim800.println("AT+CMGF=1"); // Configurar modo de texto para enviar mensajes SMS
  delay(100);
  sim800.print("AT+CMGS=\"");
  sim800.print(numero);
  sim800.println("\"");
  delay(100);
  sim800.println(mensaje);
  delay(100);
  sim800.println((char)26); // CTRL+Z para enviar el mensaje
  delay(1000);
}