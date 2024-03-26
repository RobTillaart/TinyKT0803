//
//    FILE: KT0803_setFrequency.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: minimal demo
//     URL: https://github.com/RobTillaart/TinyKT0803


#include "TinyKT0803.h"


TinyKT0803 FM_SEND;


void setup()
{
  Serial.begin(115200);
  while(!Serial);

  TinyWireM.begin();
  
  FM_SEND.begin();
  FM_SEND.setFrequency(105.75);
  FM_SEND.setMute(false);

  Serial.print("Freq: ");
  Serial.println(FM_SEND.getFrequency());
  Serial.print("Channel: ");
  Serial.println(FM_SEND.getChannel());
}

void loop()
{
}


//  -- END OF FILE --
