/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Masters
  Clase: 5
  Ejercicio: 1

  PINOUT:
  (HC-SR04)
  TRIG -> D26
  ECHO -> D25

  (HC-SR501)
  OUT -> D27

  (Pulsador)
  term -> D33
---------------------------------------------*/

#include <WiFi.h>
#include <HTTPClient.h>
#include <UrlEncode.h>

const char* ssid = "__________________";
const char* password = "__________________";

const String apiKey = "__________________"; // Token de CallMeBot
const String numero = "__________________"; // Número de teléfono para enviar mensajes

const int pinBoton = 33;
const int pinTrig = 26;
const int pinEcho = 25;
const int pinPIR = 27;

bool deteccion = false; // Variable para controlar la detección de movimiento

void setup() {
  Serial.begin(115200);

  pinMode(pinBoton, INPUT);
  pinMode(pinPIR, INPUT);
  pinMode(pinEcho, INPUT);
  pinMode(pinTrig, OUTPUT);

  setup_wifi(); // Inicialización de la conexión Wi-Fi
}

void loop() {
  checarPresencia();
  checarBoton();
  delay(500);
}

void checarPresencia() {
  int valSensor = digitalRead(pinPIR); 
  Serial.println("Presencia valor: " + (String)valSensor);

  if (deteccion == false && valSensor == 1) { // Si se detecta movimiento y no se había detectado previamente
    String msg = "Persona detectada a " + (String)medirDistancia() + " cm";
    enviarMensajeWsp(msg); // Enviar el mensaje por WhatsApp
    deteccion = true; // Actualizar el estado de detección
  } else if (deteccion == true && valSensor == 0) { // Si no hay movimiento y se había detectado previamente
    deteccion = false; // Restablecer el estado de detección
  }
}

void setup_wifi() {
  pinMode(2, OUTPUT);
  Serial.println("Conectando a la red Wi-Fi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) { 
    Serial.print(".");
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    delay(300);
  }

  for (int i = 0; i <= 1; i++) { 
    digitalWrite(2, HIGH);
    delay(50);
    digitalWrite(2, LOW);
    delay(50);
  }

  Serial.println("");
  Serial.println(WiFi.localIP()); 
}

void enviarMensajeWsp(String mensaje) {
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + numero + "&apikey=" + apiKey + "&text=" + urlEncode(mensaje); // Construir la URL para enviar el mensaje

  int httpCode;
  HTTPClient http;
  http.begin(url); // Iniciar la conexión HTTP
  httpCode = http.POST(url); // Enviar el mensaje

  if (httpCode == 200) { // Verificar si la solicitud fue exitosa
    Serial.println("Enviado correctamente");
  } else {
    Serial.println("Error HTTP!"); // Mostrar un mensaje de error en caso de fallo
  }
  http.end(); // Finalizar la conexión HTTP
}

float medirDistancia() {
  digitalWrite(pinTrig, HIGH); // Generar un pulso corto para activar el sensor ultrasónico
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  long duracionPulso = pulseIn(pinEcho, HIGH); // Medir la duración del pulso de eco

  float distancia = duracionPulso * 0.034 / 2; // Calcular la distancia en centímetros
  Serial.println(distancia);
  return distancia;
}

void checarBoton() {
  if (digitalRead(pinBoton) == HIGH) {
    enviarMensajeWsp("¡Alerta, botón de alarma presionado! Llamar al 911"); // Enviar mensaje de alerta
  }
}
