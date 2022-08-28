
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;


void sound_setup()
{
    mySoftwareSerial.begin(9600);
    if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
        Serial.println(F("Unable to begin:"));
        myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms
    
        //----Set volume----
        myDFPlayer.volume(30);  //Set volume value (0~30).  
    }
}

void sound_play(int id)
{
    myDFPlayer.play(id);
}