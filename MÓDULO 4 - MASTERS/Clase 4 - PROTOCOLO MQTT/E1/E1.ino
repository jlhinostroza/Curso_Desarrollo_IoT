/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Masters
  Clase: 4
  Ejercicio: 1
---------------------------------------------*/

#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

const char* ssid = "_______________";
const char* password = "_______________";

char *server = "broker.emqx.io";
int port = 1883;

const char *topicoSalida = "Output/0001";
const char *topicoEntrada = "Input/0001";

void setup() {
  Serial.begin(115200);
  pinMode(ledpin,OUTPUT);
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

  client.publish(topicoSalida,"Hola-esp");
  delay(5000);
}

void callback(char* topic, byte* payload, unsigned int length){
  payload[length] = '\0';
  String val = String((char*)payload);
  Serial.println(val);
}
void reconnect(){
  if (client.connect("ESP32"))
    {
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