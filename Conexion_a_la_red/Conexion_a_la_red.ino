#include <ESP8266WiFi.h>
#include <Ticker.h>

String ssid = "";
String password = "";

Ticker tic_led;

byte cont = 0;
byte max_intentos = 50;

void parpadeoLed() {
  byte estate = digitalRead(LED_BUILTIN);
  digitalWrite (LED_BUILTIN, !estate);
}

void setup() {
  //Conexion serial
  Serial.begin(115200);
  Serial.println('\n');

  tic_led.attach(0.2, parpadeoLed);
  
  //Conexión WiFi
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED and cont < max_intentos) {
    cont++;
    delay(500);
    Serial.println(WiFi.status());
  }

  Serial.println("");

  if(cont < max_intentos) { //Se conecto con exito
    Serial.println("**********************************");
    Serial.print("Conectado a la red: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("macAdress: ");
    Serial.println(WiFi.macAddress());
    Serial.println("**********************************");
  }
  else {  //No se pudo conectar
    Serial.println("----------------------------------");
    Serial.println("Error de conexion");
    Serial.println("----------------------------------");
  }
  
  tic_led.detach();
  digitalWrite(LED_BUILTIN, HIGH); 
}

void loop() {
  // put your main code here, to run repeatedly:

}
