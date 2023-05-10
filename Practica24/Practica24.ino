#include <Arduino.h>
#include <Credentials.ino>
#include <PubSubClient.h>
#include <WiFi.h>

// WiFi
const ssid = SSID; // Enter your WiFi name
const password = PASSWORD;  // Enter WiFi password

// MQTT Broker
const mqtt_server = SEVER;
const mqtt_username = USERNAME;
const mqtt_password = MQTT_PASSWORD;
const mqtt_port = PORT;

WiFiClient espClient;
PubSubClient client(espClient);

long lastMsg = 0;
char msg[50];
int value = 0;

void callback(const char *topic, byte* payload, unsigned int lenght){
  Serial.print("Mensaje recibido bajo el topico ->");
  Serial.print(topic);
  Serial.print("\n");

  for (int i = 0; i < lenght; i++){
    Serial.print((char)payload[i]);
  }

  if((char)payload[0]== '0'){
    digitalWrite(BUILTIN_LED, LOW);
    Serial.println("\n Led Apagado");
  } else {
    digitalWrite(BUILTIN_LED, HIGH);
    Serial.println("\n Led Encendido");
  }
  Serial.println();
}

void reconnect(){
  while (!client.connected()){
    Serial.println("Intentando Conexion MQTT");

    String clientId = "iot_1_";
    clientId = clientId + String(random(0xffff), HEX);

    if (client.connect(clientId.c_str(),mqtt_username,mqtt_password)){
      Serial.println("Conexion a MQTT exitosa!!!");
      client.publish("salida_3", "primer mensaje");
      client.subscribe("entrada");
    }else{
      Serial.println("Fallo la conexion");
      Serial.println(client.state());
      Serial.println("Se intentara de nuevo en 5 segundos");
      delay(5000);
    } 
  }
}

void setup_wifi(){
  //Conexión a la red Wifi
  Serial.println();
  Serial.println("Conectando a....");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }

  Serial.println("");
  Serial.println("Conectado a red WiFi");
  Serial.println("Direccion IP: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (client.connected()==false){
    reconnect();
  }
  client.loop();
  
  if (millis() - lastMsg > 2000){
    lastMsg = millis();
    value++;
    String mes = "Valor ->" + String(value);
    mes.toCharArray(msg, 50);
    client.publish("salida_3", msg);
    Serial.println("Mensaje enviado ->" + String(value));
  }  
}