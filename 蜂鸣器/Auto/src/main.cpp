#include "Arduino.h"

#define BUZZER 23
#define CHANNEL 0
#define RESOLUTION 8
#define FREQ 20000


int tone_array[8]={0,262,294,330,350,393,441,495};

int music[]={1,1,5,5,6,6,5,0,
             4,4,3,3,2,2,1,0,
             5,5,4,4,3,3,2,0,
             5,5,4,4,3,3,2,0,
             1,1,5,5,6,6,5,0,
             4,4,3,3,2,2,1,0};


void setup() 
{
  
    pinMode(BUZZER,OUTPUT);
    
    
        

    
    ledcSetup(CHANNEL, FREQ, RESOLUTION);
    ledcAttachPin(BUZZER, CHANNEL);


}
void loop() 
{
   for(int i=0;i<sizeof(music)/sizeof(music[0]);i++)
   {
    ledcWriteTone(CHANNEL, tone_array[music[i]]);
    delay(500);

   }

}
