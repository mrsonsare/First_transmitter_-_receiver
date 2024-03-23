#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

int joystickLeft_x;
int joystickLeft_y;

RF24 radio(7,8); //(CE,CSN)
const byte address[] = "node1";

void setup() {
  // put your setup code here, to run once:
radio.begin();
radio.openWritingPipe(address);
radio.setPALevel(RF24_PA_MAX);
radio.stopListening();
}

struct datapack {

int joystickLeft_x;
int joystickLeft_y;

};

datapack data;

void loop() {
  // put your main code here, to run repeatedly:
data.joystickLeft_x = map(analogRead(A0),0,1023,0,255);

data.joystickLeft_y = map(analogRead(A1),0,1023,0,255);

////////////////////////////////////////////////////////Switch///////////////////////////////////////////////////////// 
radio.write(&data,sizeof(data));

}
