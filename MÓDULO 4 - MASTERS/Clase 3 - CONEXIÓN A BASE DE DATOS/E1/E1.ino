/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Masters
  Clase: 3
  Ejercicio: 1

  PINOUT:
  (DHT11)
  S -> 34
---------------------------------------------*/

#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h> 

const int pinDHT = 34;
DHT sensorDHT(pinDHT, DHT11); 

String url = "http://192.168.0.19/dht11_project/test_data.php"; //Cambiar por dirección del archivo PHP

const char* ssid = "____________"; //Cambiar por SSID
const char* contraseña = "____________"; //Cambiar por contraseña

int temperatura = 0;
int humedad = 0;

void setup() {
  Serial.begin(115200);
  sensorDHT.begin(); 
  setup_wifi();
}

void loop() {
  if(WiFi.status() != WL_CONNECTED) {
    conectarWiFi();
  }

  leerDHT11();
  String datosPost = "temperatura=" + String(temperatura) + "&humedad=" + String(humedad);
  
  HTTPClient http;
  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  int códigoHttp = http.POST(datosPost);
  String respuesta = "";

  if(códigoHttp > 0) {
    // archivo encontrado en el servidor
    if(códigoHttp == HTTP_CODE_OK) {
      respuesta = http.getString();
      Serial.println(respuesta);
    } else {
      // Encabezado HTTP enviado y encabezado de respuesta del servidor manejado
      Serial.printf("[HTTP] GET... código: %d\n", códigoHttp);
    }
  } else {
    Serial.printf("[HTTP] GET... falló, error: %s\n", http.errorToString(códigoHttp).c_str());
  }
  
  http.end();  // Cierra la conexión

  Serial.print("URL : "); Serial.println(url); 
  Serial.print("Datos: "); Serial.println(datosPost);
  Serial.print("Código HTTP: "); Serial.println(códigoHttp);
  Serial.print("Respuesta : "); Serial.println(respuesta);
  Serial.println("--------------------------------------------------");
  delay(5000);
}


void leerDHT11() {
  temperatura = sensorDHT.readTemperature(); // Celsius
  humedad = sensorDHT.readHumidity();
  // Verifica si alguna lectura falló.
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("¡Error al leer desde el sensor DHT!");
    temperatura = 0;
    humedad = 0;
  }
  //-----------------------------------------------------------
  Serial.printf("Temperatura: %d °C\n", temperatura);
  Serial.printf("Humedad: %d %%\n", humedad);
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