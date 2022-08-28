//----------------------------------------------------------------
//-- Otto All moves test
//-- Otto DIY invests time and resources providing open source code and hardware, 
//-- please support by purchasing kits from https://www.ottodiy.com/
//-- Make sure to have installed all libraries: https://github.com/OttoDIY/OttoDIYLib
//-----------------------------------------------------------------
#include "Arduino.h"
#include "printf.h"
#include <Otto.h>
#include "pin.h"
#include "eye.h"
#include "sound.h"

#define DEBUG
Otto Otto;  //This is Otto!


void setup(){

  Serial.begin(115200);
  //eye_setup();
  //eye_run(1);  

  sound_setup();
  sound_play(3);
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true); //Set the servo pins and Buzzer pin
  Otto.home();
  
  delay(50);
  
}

///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop() { 
  Otto.walk(2,1000,1); //2 steps, "TIME". IF HIGHER THE VALUE THEN SLOWER (from 600 to 1400), 1 FORWARD
  Otto.walk(2,1000,-1); //2 steps, T, -1 BACKWARD 
  Otto.turn(2,1000,1);//3 steps turning LEFT
    Otto.home();
    sound_play(3);
    delay(100);  
  Otto.turn(2,1000,-1);//3 steps turning RIGHT 
  Otto.bend (1,500,1); //usually steps =1, T=2000
  Otto.bend (1,2000,-1);     
  Otto.shakeLeg (1,1500, 1);
    Otto.home();
    sound_play(3);
    delay(100);
  Otto.shakeLeg (1,2000,-1);
  Otto.moonwalker(3, 1000, 25,1); //LEFT
  Otto.moonwalker(3, 1000, 25,-1); //RIGHT  
  Otto.crusaito(2, 1000, 20,1);
  Otto.crusaito(2, 1000, 20,-1);
  sound_play(3);
    delay(100); 
  Otto.flapping(2, 1000, 20,1);
  Otto.flapping(2, 1000, 20,-1);
  sound_play(3);
    delay(100);        
  Otto.swing(2, 1000, 20);
  Otto.tiptoeSwing(2, 1000, 20);
  Otto.jitter(2, 1000, 20); //(small T)
  Otto.updown(2, 1500, 20);  // 20 = H "HEIGHT of movement"T 
  Otto.ascendingTurn(2, 1000, 50);
  Otto.jump(1,500); // It doesn't really jumpl ;P
  Otto.home();
  sound_play(3);
     delay(100); 

}
