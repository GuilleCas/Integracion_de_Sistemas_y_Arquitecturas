/* Librerias para usar display ssd1306 */
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(-1);

/* Declaración de las variables para la entrada */
int boton = 3;
int potenciometro = 0;

/* Variables auxiliares  */
int vida;
int nivel;
int puntos;
int movimiento;
int limite;
boolean bajada=false;
boolean inicio=false;
int pixelInicio;

void setup() {
  Serial.begin(9600);
  
  /* Inicio el display para la AxAA dirección */
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(35,22);
  display.println("PRESS START");
  display.display();

  /* Entradas */
  pinMode(boton,INPUT);
  
  attachInterrupt(digitalPinToInterrupt(boton),iniciar,CHANGE);
}

void loop() {
  if(inicio){
    
    if(vida < 1){
      inicio = false;
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(35,22);
      display.println("GAME OVER");
      display.display();
      delay(5000);
      reiniciar();
    }
      
    else{
      cambiar_nivel();
      if(!bajada){
        limite=10;
        pixelInicio = random(5,125);
        bajada = true;
      }
      else{
        pixelInicio = random(pixelInicio-5,pixelInicio+5);
      }
     
      display.clearDisplay();
  
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println(" P:" + String(puntos) + "    N:" + String(nivel) + "    V:" + String(vida));
      display.drawPixel(pixelInicio,limite,WHITE);
  
      limite+=2*nivel;
    
      movimiento = analogRead(potenciometro)/10;
    
      display.drawLine(movimiento, 60, movimiento+22, 60, WHITE);
  
      if(limite >= 60){
        if(pixelInicio >= movimiento && (pixelInicio <= (movimiento+22))){
          puntos++;
        }
        else{
          vida--;
        }
        bajada = false;
      }    
      display.display(); 
    }
  }
}

void iniciar(){
  if(inicio==false){
    vida = 4;
    puntos = 0;
    nivel = 1;
    inicio=true;
  }
}

void reiniciar(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(35,22);
  display.println("PRESS START");
  display.display();
}

void cambiar_nivel(){
  switch(puntos){
    case 3:
      nivel=2;
      break;
    case 6:
      nivel=3;
      break;
    case 9:
      nivel=4;
      break;
  }
}
