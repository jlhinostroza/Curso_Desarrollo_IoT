/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Inventors
  Clase: 5
  Ejercicio: 1
---------------------------------------------*/


#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <WebSocketsServer.h>

#define ledPin_1 13
#define ledPin_2 12
#define ledPin_3 14

const char *ssid = "WIFI_AP_ESP32";
const char *password = "";

AsyncWebServer server(80);
WebSocketsServer websockets(81);


void setup() {
  
  Serial.begin(115200);
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);

  WiFi.softAP(ssid, password);  //SSID Y CONTRA
  Serial.println("\nsoftAP");
  Serial.println(WiFi.softAPIP());


  if(!SPIFFS.begin(true)){
    Serial.println("Error al montar SPIFFS!");
  } else {
    Serial.println("Todo OK con el SPIFFS!");
  }

  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.html", "text/html");
  });

  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/style.css", "text/css");
  });

  
  
  server.onNotFound(notFound);
  server.begin();

  websockets.begin();
  websockets.onEvent(webSocketEvent);
}


void loop() {
  websockets.loop();
}

//CALLBACKS
void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Desconectado!\n", num);
      break;

    case WStype_CONNECTED: {
      IPAddress ip = websockets.remoteIP(num);
      websockets.sendTXT(num, "Conectado en servidor:");
    }
    break;

    case WStype_TEXT: {
      Serial.printf("[%u] Mensaje recibido: %s\n", num, payload);
      String msg = String((char *)(payload));

      if (msg.equalsIgnoreCase("LedOn1")) {
        Serial.println("Led 1 on");
        digitalWrite(ledPin_1, HIGH);
      }

      if (msg.equalsIgnoreCase("LedOff1")) {
        Serial.println("Led 1 off");
        digitalWrite(ledPin_1, LOW);
      }

      if (msg.equalsIgnoreCase("LedOn2")) {
        Serial.println("Led 2 on");
        digitalWrite(ledPin_2, HIGH);
      }

      if (msg.equalsIgnoreCase("LedOff2")) {
        Serial.println("Led 2 off");
        digitalWrite(ledPin_2, LOW);
      }

      if (msg.equalsIgnoreCase("LedOn3")) {
        Serial.println("Led 3 on");
        digitalWrite(ledPin_3, HIGH);
      }

      if (msg.equalsIgnoreCase("LedOff3")) {
        Serial.println("Led 3 off");
        digitalWrite(ledPin_3, LOW);
      }
    }
    break;
  }
}
void notFound(AsyncWebServerRequest *request){
  request->send(404, "text/plain", "Pagina no encontrada!");
}
