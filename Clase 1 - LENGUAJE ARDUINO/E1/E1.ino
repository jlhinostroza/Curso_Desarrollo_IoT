/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 1
  Ejercicio: 1
---------------------------------------------*/

const int numeroDeTemperaturas = 5;  // Definimos el número de temperaturas
int temperaturas[numeroDeTemperaturas];  // Declaramos el array

void setup() {
  Serial.begin(9600);

  // Inicializamos el array con algunos valores de ejemplo
  temperaturas[0] = 25;
  temperaturas[1] = 28;
  temperaturas[2] = 22;
  temperaturas[3] = 30;
  temperaturas[4] = 26;

  // Imprimimos las temperaturas en el Monitor Serie
  Serial.println("Temperaturas registradas:");
  for (int i = 0; i < numeroDeTemperaturas; ++i) {
    Serial.print("Temperatura ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(temperaturas[i]);
  }
}

void loop() {
  // Nada en el loop
}
