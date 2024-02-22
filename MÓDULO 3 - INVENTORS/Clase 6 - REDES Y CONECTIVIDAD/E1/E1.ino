/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Inventors
  Clase: 6
  Ejercicio: 1
---------------------------------------------*/

#include <WiFi.h>

const char* ssid = "TuSSID";            // Nombre de tu red Wi-Fi
const char* password = "TuContraseña";  // Contraseña de tu red Wi-Fi

void setup() {
  Serial.begin(115200);

  setup_wifi();

  // Conexión exitosa, muestra la información de la conexión
  Serial.println("Conexión exitosa");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Máscara de subred: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Puerta de enlace (Gateway): ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("Dirección del servidor DNS: ");
  Serial.println(WiFi.dnsIP());
}

void loop() {
  // Nada en el bucle principal
}

void setup_wifi(){
  // Conexión a la red Wi-Fi
  Serial.println("Conectando a la red Wi-Fi...");

  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED)
    {
      delay(300);
      Serial.print(".");
    }
  Serial.println("");
  Serial.println(WiFi.localIP());
}