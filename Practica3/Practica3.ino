int rojo = 1;
int amarillo = 4;
int verde = 7;

void setup() {
  pinMode(verde,OUTPUT);
  pinMode(amarillo,OUTPUT);
  pinMode(rojo,OUTPUT);
}

void loop() {

  //Encendido del LED verde
  digitalWrite(verde,HIGH);
  delay(3000);
  
  //Inicia Parpadeo de LED
  digitalWrite(verde,LOW);
  delay(500);
  digitalWrite(verde,HIGH);
  delay(500);
  digitalWrite(verde,LOW);
  delay(500);
  digitalWrite(verde,HIGH);
  delay(500);
  digitalWrite(verde,LOW);
  delay(500);
  digitalWrite(verde,HIGH);
  delay(500);
  digitalWrite(verde,LOW);

  //Apaga el led
  delay(4000);

  digitalWrite(amarillo,HIGH);
  delay(3000);
  digitalWrite(amarillo,LOW);
  delay(4000);

  digitalWrite(rojo,HIGH);
  delay(3000);
  digitalWrite(rojo,LOW);
  delay(5000);
}
