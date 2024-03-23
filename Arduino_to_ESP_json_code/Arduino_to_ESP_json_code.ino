#include <SoftwareSerial.h>
#include <ArduinoJson.h>

const int trigPin = 2;
const int echoPin = 3;
long duration ;
int distanceCm;

float m;
float cm ;

SoftwareSerial nodemcu(5,6); //(RX PIN,TX PIN)

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);

  nodemcu.begin(9600);
  delay(1000);

  Serial.println("Program started");
}

void loop() {
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.createObject(); //Here Object "data" is created

readings(); /// to collect data 

data["Meter"] = m;
data["Centimeter"] = cm;

 data.printTo(nodemcu);
  jsonBuffer.clear();

  delay(2000);
}

void readings() {

  // put your main code here, to run repeatedly:
 digitalWrite(trigPin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(2);
 digitalWrite(trigPin,LOW);

 duration = pulseIn(echoPin,HIGH);
 
cm = duration*0.034/2;
m  = duration*0.01*0.034/2; 

 Serial.print("Meter: ");
  Serial.println(m);
  Serial.print("Centimeter: ");
  Serial.println(cm);


}