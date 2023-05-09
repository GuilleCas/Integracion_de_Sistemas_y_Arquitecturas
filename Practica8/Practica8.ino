//Entradas digitales con boton
void setup() {
  Serial.begin(9600);

  pinMode(8,INPUT);
}

void loop() {
  bool estado_pulsador = digitalRead(4);
  String estado;

  if(estado_pulsador == true)
  {
    estado = "NO PRESIONADO";
  }else{
    estado = "PRESIONADO";
  }

  Serial.println(estado);
}
