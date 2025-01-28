#include "DHT.h"        // inclui a biblioteca
#define dht_type DHT11  // define o modelo (tipo) do sensor

int dht_pin = A5;                    // nomeia o pino A5 conectado ao sensor
DHT dht_1 = DHT(dht_pin, dht_type);  // cria o sensor dht_1 e envia para a biblioteca suas informações de modelo e pino

void setup() {         // só acontece uma vez
  Serial.begin(9600);  // inicia o Serial.Monitor com uma taxa de 9600 baud rates
  dht_1.begin();       // inicia o sensor dht_1
}

void loop() {
  float umidade = dht_1.readHumidity();  // %

  float temperatura = dht_1.readTemperature();  // C°
  
  ///////////////////////////////////////////////////////////////
  if (isnan(temperatura) or isnan(umidade)) {
    Serial.println("Erro ao ler");
  }

  else {
    Serial.print(temperatura);
    Serial.print(";");
    Serial.println(umidade);
  }
  delay(20000);  // faz uma leitura a cada 20 segundo
}