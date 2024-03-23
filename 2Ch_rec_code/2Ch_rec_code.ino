#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(7, 8); // CE, CSN
const byte address[] = "node1";

struct datapack {
  int joystickLeft_x;
  int joystickLeft_y;
};

datapack data;

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&data, sizeof(data));

    // Process received data
    int joystickLeft_x = data.joystickLeft_x;
    int joystickLeft_y = data.joystickLeft_y;

    // Print received data
 

    if (joystickLeft_x < 125 ) {
     analogWrite(A0,map( joystickLeft_x,0,124,255,0));
   Serial.print(map( joystickLeft_x,0,124,255,0));
    }

     if (joystickLeft_x > 130 ) {
     analogWrite(A0,map( joystickLeft_x,131,255,0,255));
   Serial.print(map( joystickLeft_x,131,255,0,255));
    }

     if (joystickLeft_x == 130) {
      int x = 0;
     analogWrite(A0,x); 
     Serial.print("\t" + x);   
       }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   if (joystickLeft_y < 125 ) {
     analogWrite(A5,map( joystickLeft_y,0,124,255,0));
   Serial.print(map( joystickLeft_y,0,124,255,0));
    }

     if (joystickLeft_y > 130 ) {
     analogWrite(A5,map( joystickLeft_y,131,255,0,255));
   Serial.print(map( joystickLeft_y,131,255,0,255));
    }

     if (joystickLeft_y == 127) {
      int y = 0;
     analogWrite(A5,y);    
     Serial.print("\t" + y);
     }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    Serial.print("\tJoystick Left X: ");
    Serial.print(joystickLeft_x);
    Serial.print("\tJoystick Left Y: ");
    Serial.println(joystickLeft_y);

  }
}
