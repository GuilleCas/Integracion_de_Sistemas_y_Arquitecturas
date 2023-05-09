//includes para usar display ssd1306
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//si tu display no usa pin reset, aqui pon -1 
Adafruit_SSD1306 display(-1);

void setup() {
  Serial.begin(9600);

  //Inicio el display para la AxAA dirección
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  //Esto genera el splash screen
  display.display();
  delay(2000);

  //Borrar display
  display.clearDisplay();

  //Dibuja un pixel en la posición X Y COLOE
  display.drawPixel(10,10,WHITE);
  
  /* Dibuja rectángulo vacio
  display.drawRect(0,0,100,64,WHITE);*/
  
  /* Dibuja rectángulo lleno
  display.fillRect(0,0,100,64,WHITE);*/

  /* Dibuja rectángulo redondeado
  display.drawRoundRect(0,0,100,64,20,WHITE);*/

  /* Dibuja triangulo vacio
  display.drawTriangle(10,10,45,60,60,60,WHITE);*/

  /* Dibuja triangulo lleno
  display.fillTriangle(10,10,45,60,60,60,WHITE);*/

  
  /* Dibuja Texto en pantalla
  display.setTextSize(2);
  display.setTextColor(BLACK,WHITE);
  display.setCursor(0,0);
  display.println("Hello world!");
  display.println("Hello, world2");*/
  
  display.display();
}

void loop() {

}
