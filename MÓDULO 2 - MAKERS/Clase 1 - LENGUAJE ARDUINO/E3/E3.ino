/*---------------------------------------------
  Curso de Desarrollo IoT
  Módulo: Makers
  Clase: 1
  Ejercicio: 3
---------------------------------------------*/

void setup() {
  Serial.begin(9600);

  Serial.println("Usando for:");
  // Estructura cíclica for
  for (int i = 1; i <= 5; ++i) {
    Serial.println(i);
  }

  Serial.println("\nUsando while:");
  // Estructura cíclica while
  int j = 1;
  while (j <= 5) {
    Serial.println(j);
    ++j;
  }

  Serial.println("\nUsando do-while:");
  // Estructura cíclica do-while
  int k = 1;
  do {
    Serial.println(k);
    ++k;
  } while (k <= 5);
}

void loop() {
  // Nada en el loop por ahora
}
