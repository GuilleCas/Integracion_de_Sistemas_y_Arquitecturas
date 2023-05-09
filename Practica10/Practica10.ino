int estadoBoton=0;     //Guardará el estado del botón (HIGH ó LOW)
int cambio_estado = 0;

void setup(){
    pinMode(5,OUTPUT);     //Donde está conectado el LED
    pinMode(3,INPUT);     //Donde está conectado el pulsador
}
void loop() {
    estadoBoton=digitalRead(3);

    //Comprueba si el botón esta pulsado
    if(estadoBoton == HIGH)
    {
      cambio_estado = !cambio_estado;
      delay(300);
    }

    if(cambio_estado == HIGH){
      digitalWrite(5,HIGH);
      Serial.println(">> APAGADO <<");
    }else{
      digitalWrite(5,LOW);
      Serial.println(">> ENCENDIDO <<");
    }
}
