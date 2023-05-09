//Se incluye las librerias
#include <OneWire.h>
#include <DallasTemperature.h>

//Se define el pin que vamos a usar con one wire
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor (&oneWire);

float temperatura;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando Sensor de temperatura Dallas");
}

void loop() {
  sensor.requestTemperatures();
  temperatura = sensor.getTempCByIndex(0);

  Serial.println("La temperatura es: " + String(temperatura));
}
