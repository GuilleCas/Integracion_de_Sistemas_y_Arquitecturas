//Entradas digitales con boton
void setup() {
  Serial.begin(9600);

  pinMode(8,INPUT);
}

void loop() {
  bool estado_pulsador = digitalRead(8);
  String estado;

  if(estado_pulsador == true)
  {
    estado = "PRESIONADO";
  }else{
    estado = "NO PRESIONADO";
  }

  Serial.println(estado);
}
