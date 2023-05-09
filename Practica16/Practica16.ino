/* Librerias para el sensor de temperatura */
#include <OneWire.h>
#include <DallasTemperature.h>

/* Librerias para usar display ssd1306 */
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(-1);

/* Definimos el pin que vamos a usar con one wire */
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

/* Declaración de las variables para la entrada */
int boton = 3;
int boton2 = 4;
int ventilador = 5;

/* Valores de temperatura */
float temp;
bool ventilador_activado = false;

/* Umbral de Temperatura parametros de encendido u apagado */
int temperatura_max = 28;

int estado=0;
int estado2=0;

int i;

void setup(){
  Serial.begin(9600);
   
  /* Inicio el display para la AxAA dirección */
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  Serial.println("Iniciando Sensor de Temperatura Dallas");

  /* Entradas */
  pinMode(ventilador,OUTPUT);
  pinMode(boton,INPUT);
  pinMode(boton2,INPUT);
  
  attachInterrupt(digitalPinToInterrupt(boton),consulta_estado,CHANGE);
  attachInterrupt(digitalPinToInterrupt(boton2),consulta_estado2,CHANGE);
  sensors.begin();
  
}

void loop(void){ 
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);

  if(temp > temperatura_max){
    digitalWrite(ventilador,HIGH);
    ventilador_activado = true;
    Serial.println("VENTILADOR ACTIVADO -> " + String(temp));
  }
  else{
    digitalWrite(ventilador,LOW);
    ventilador_activado = false;
    Serial.println("VENTILADOR DESACTIVADO -> " + String(temp));
  }



  /* Fila */
  display.drawPixel(5, 40, WHITE);
  display.drawPixel(10, 40, WHITE);
  display.drawPixel(15, 40, WHITE);
  display.drawPixel(20, 40, WHITE);
  display.drawPixel(25, 40, WHITE);
  display.drawPixel(30, 40, WHITE);
  display.drawPixel(35, 40, WHITE);
  display.drawPixel(40, 40, WHITE);
  display.drawPixel(45, 40, WHITE);
  display.drawPixel(50, 40, WHITE);
  display.drawPixel(55, 40, WHITE);
  display.drawPixel(60, 40, WHITE);
  display.drawPixel(65, 40, WHITE);
  display.drawPixel(70, 40, WHITE);
  display.drawPixel(75, 40, WHITE);
  display.drawPixel(80, 40, WHITE);
  display.drawPixel(85, 40, WHITE);
  display.drawPixel(90, 40, WHITE);
  display.drawPixel(95, 40, WHITE);
  display.drawPixel(100, 40, WHITE);
  display.drawPixel(105, 40, WHITE);
  display.drawPixel(110, 40, WHITE);
  display.drawPixel(115, 40, WHITE);
  display.drawPixel(120, 40, WHITE);
  display.drawPixel(125, 40, WHITE);
  display.drawPixel(128, 40, WHITE);


  if(i==128){
    display.clearDisplay();
    i=0;
    }
    /*  Resetea al llegar al limite de la pantalla */
  if(temperatura_max !=temp){
    i++;
    display.drawPixel(i,(64-temp),WHITE);//imprime un punto
    display.fillRect(0,0,128,5,BLACK);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Temperayuta= " + String(temp) + " \nTemp_max=" + String(temperatura_max));
   
  }
  display.display();
}


void consulta_estado(){
  if(ventilador_activado == true || ventilador_activado == false){
    temperatura_max += 1;
    Serial.println("Boton1=" + String(temperatura_max));
    delay(7000);
  }
}

void consulta_estado2(){
  if(ventilador_activado == true || ventilador_activado == false){
    temperatura_max -= 1;
    Serial.println("Boton1=" + String(temperatura_max));
    delay(7000);
  }
}
