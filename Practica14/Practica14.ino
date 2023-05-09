//Se incluye las librerias
#include <OneWire.h>
#include <DallasTemperature.h>

//Se define el pin que vamos a usar con one wire
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor (&oneWire);

int boton = 3;
int ventilador = 5;
float temperatura;

long diferencia;
long tiempo_anterior;

int maxtemp = 25.3;

bool estado;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando Sensor de temperatura Dallas");

  pinMode(boton,INPUT);
  pinMode(ventilador ,OUTPUT);

  attachInterrupt(digitalPinToInterrupt(boton),consulta_estado,CHANGE);
}

void loop() {
  sensor.requestTemperatures();
  temperatura = sensor.getTempCByIndex(0);

  Serial.println("La temperatura es:"+ String(temperatura));
  
  if(temperatura > maxtemp){
      if(estado == true){
        digitalWrite(ventilador,HIGH);
         Serial.println("ENCENDIDO POR TEMPERATURA");
      }
      else { 
        digitalWrite(ventilador,LOW);
        Serial.println("APAGADO POR TEMPERATURA");
        }
  }
}

void consulta_estado(){
  diferencia = millis() - tiempo_anterior;
  tiempo_anterior = millis();

  if(diferencia > 500){
    if(digitalRead(ventilador) == true){
      digitalWrite(ventilador ,LOW);
      Serial.println("VENTILADOR APAGADO");
      estado = false;
      delay(500);
    }else {
      digitalWrite(ventilador,HIGH);
      Serial.println("VENTILADOR ENCENDIDO");
      estado = true;
      delay (500);
    }
  }
}
