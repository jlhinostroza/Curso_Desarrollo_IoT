/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Masters
  Clase: 4
  Ejercicio: 2

  PINOUT:
  (LDR)
  term -> D33
---------------------------------------------*/

#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

const char* ssid = "_______________";
const char* password = "_______________";

char *server = "broker.emqx.io";
int port = 1883;

const char *topicoSalida = "Output/0002";
const char *topicoEntrada = "Input/0002";

int ledpin= 26;
int fotopin=33;

int var = 0;
int ledval = 0;
int fotoval = 0;

char datos[40];
String resultS = "";

void setup() {
  Serial.begin(115200);
  pinMode(ledpin, OUTPUT);
  delay(10);

  setup_wifi();
  client.setServer(server, port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()){
    reconnect();
  }
  client.loop();

  Serial.print("String: ");
  Serial.println(resultS);

  if(var == 0){
    digitalWrite(ledpin,LOW);
  }
  else if (var == 1){
    digitalWrite(ledpin,HIGH);
  }

  fotoval = analogRead(fotopin);
  Serial.print("Foto: ");
  Serial.println(fotoval);

  sprintf(datos, "Valor fotoresistencia: %d ", fotoval);
  client.publish(topicoSalida, datos);
  delay(5000);
}

void callback(char* topic, byte* payload, unsigned int length){
  Serial.print("Mensaje recibido [");
  Serial.print(topic);
  Serial.print("] ");
  
  char payload_string[length + 1];
  
  int resultI;

  memcpy(payload_string, payload, length);
  payload_string[length] = '\0';
  resultI = atoi(payload_string);
  
  var = resultI;

  resultS = "";
  
  for (int i=0;i<length;i++) {
    resultS= resultS + (char)payload[i];
  }
  Serial.println();
}

void reconnect(){
  if (client.connect("ESP32")) {
    Serial.println("Conexión exitosa");
    client.subscribe(topicoEntrada);
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