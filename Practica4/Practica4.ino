int ledPin = 3; //Salida LED en el PIN 10
int parpadeo[]={180,30,255,200,10,90,150,60}; //array de 8 valores diferentes
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); //Configura la salida PIN 3
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<8; i++)
  {
    analogWrite(ledPin,parpadeo[i]);
    delay(200);
  }
}
