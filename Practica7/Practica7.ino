const int led = 3;
int brillo;
int potencia;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  brillo = analogRead(potencia)/4;
  analogWrite(led,brillo);
}
