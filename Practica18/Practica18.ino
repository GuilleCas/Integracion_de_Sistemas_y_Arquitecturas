/* Libreria para usar nuestro motor Servo */
#include <Servo.h> 

/* Definimos nombre de nuestro Servo */
Servo mi_servo;

/* Declaración de las variables para la entrada */
int potenciometro = 0;

/* Variable que definw la posición del servo */
int valor_potenciometro;    

void setup() {
  Serial.begin(9600);

  /* Entradas */
  mi_servo.attach(9); 
}

void loop() {
  valor_potenciometro = analogRead(potenciometro);
  
  /* Proporcionamos los valores de la escala de nuestro servomotor ( 0 y 180) */
  valor_potenciometro = map(valor_potenciometro, 0, 1023, 0, 180);
  
  mi_servo.write(valor_potenciometro);

  
  delay(10);
}
