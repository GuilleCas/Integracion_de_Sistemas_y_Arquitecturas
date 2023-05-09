const byte motorIzquierdoA = 3;
const byte motorIzquierdoB = 4;
const byte motorDerechoA = 5;
const byte motorDerechoB = 6;
const byte enableIzquierdo = 10;
const byte enableDerecho = 11;

byte velocidad_inicial = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(motorDerechoA,OUTPUT);
  pinMode(motorDerechoB,OUTPUT);
  pinMode(motorIzquierdoA,OUTPUT);
  pinMode(motorIzquierdoB,OUTPUT);

  analogWrite (enableIzquierdo,velocidad_inicial);
  analogWrite (enableDerecho, velocidad_inicial);
}

void loop() {
  control_izq(true, 254);
  delay(2000);
  control_izq(true, 0);
  delay(2000);
  control_izq(false, 254);
  delay(2000);
  control_izq(true, 0);
  delay(2000);
}

void control_izq(bool sentido, byte vel){
  if(sentido == true){
    digitalWrite(motorIzquierdoA, HIGH);
    digitalWrite(motorIzquierdoB, LOW);
  } else {
    digitalWrite(motorIzquierdoA, LOW);
    digitalWrite(motorIzquierdoB, HIGH);
  }
  analogWrite (enableIzquierdo,vel);
}
