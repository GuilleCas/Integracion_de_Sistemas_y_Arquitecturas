int rojo = 2;
int amarillo = 4;
int verde = 7;


void setup() {
  pinMode(verde,OUTPUT);
  pinMode(amarillo,OUTPUT);
  pinMode(rojo,OUTPUT);
}

void loop() {
  encendido_verde();
  delay(500);
  apagado();
  delay(500);
  encendido_verde();
  delay(500);
  apagado();
  delay(500);
  encendido_verde();
  delay(500);
  apagado();

  delay(4000);

  encendido_amarillo();
  delay(4000);

  encendido_rojo();
  delay(4000);
}

void apagado(){
  digitalWrite(verde,LOW);
  digitalWrite(amarillo,LOW);
  digitalWrite(rojo,LOW);
}

void encendido_verde(){
  digitalWrite(verde,HIGH);
  digitalWrite(amarillo,LOW);
  digitalWrite(rojo,LOW);
}

void encendido_amarillo(){
  digitalWrite(verde,LOW);
  digitalWrite(amarillo,HIGH);
  digitalWrite(rojo,LOW);
}

void encendido_rojo(){
  digitalWrite(verde,LOW);
  digitalWrite(amarillo,LOW);
  digitalWrite(rojo,HIGH);
}
