#include <Ubidots.h>

//Completamente personales
const char* UBIDOTS_TOKEN = "";
const char* WIFI_SSID = "";
const char* WIFI_PASS = "";

Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

int var_pot;

void setup() {
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  var_pot = 0;
}

void loop() {
  
  var_pot = analogRead(A0);
  Serial.println(var_pot);
  
  ubidots.add("var_pot", var_pot);

  bool bufferSent = false;

  bufferSent = ubidots.send();

  if(bufferSent) {
    Serial.println("Values sent by the device");
  }

  delay(10);

  

}
