#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial nodemcu(D6,D5);// (RX,TX)


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  nodemcu.begin(9600);
  while (!Serial) continue;


}

void loop() {
  // put your main code here, to run repeatedly:
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.parseObject(nodemcu);

   if (data == JsonObject::invalid()) {
    //Serial.println("Invalid Json Object");
    jsonBuffer.clear();
    return;
  }

   Serial.println("JSON Object Recieved");
  Serial.print("Recieved Meter data:  ");
  float m = data["Meter"];
  Serial.println(m);
  Serial.print("Recieved Centimeter data:  ");
  float cm = data["Centimeter"];
  Serial.println(cm);
  Serial.println("-----------------------------------------");
}
