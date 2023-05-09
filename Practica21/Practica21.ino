/* Librerias para usar display ssd1306 */
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(-1);

/* Variables del Sensor */
const byte trigg = 3;
const byte echo = 2;

int i;

void setup() {
  Serial.begin(9600);
  pinMode(trigg, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigg,LOW);

  /* Inicio el display para la AxAA dirección */
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  /* Resetea al llegar al limite de la pantalla */
  if(i==128){
    display.clearDisplay();
    i=0;
  }
  /* Resetea si da un valor alto imposible de medir */
  if(mide_distancia()>350){
    display.clearDisplay();
    i=0;
  }

  i++;
  display.drawPixel(i,(54-mide_distancia()),WHITE);
  display.fillRect(0,0,128,5,BLACK);
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20,0);
  display.println("Distancia: " + String(mide_distancia()));
  display.display();
}

int mide_distancia(){
  gatillo();
  long tiempo = pulseIn(echo,HIGH);
  int distancia = tiempo / 58;
  return distancia;
}

void gatillo(){
  digitalWrite(trigg,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigg,LOW);
}
