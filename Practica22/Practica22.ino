#include <WiFi.h>
#include <Credentials.ino>

const ssid = SSID;
const password = PASSWORD;
void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println("");
  Serial.println("");

  Serial.println("Conectado a ->");
  Serial.println(ssid);

  //me conecto a la red WiFi
  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(250);
  }

  Serial.println("");
  Serial.println("Conexión Exitosa");

  Serial.println("Mi ip es ->");
  Serial.println("Conexión Exitosa!");
  
  Serial.println("Mi ip es ->");
  Serial.println(WiFi.localIP());
}

void loop() {
  
}
