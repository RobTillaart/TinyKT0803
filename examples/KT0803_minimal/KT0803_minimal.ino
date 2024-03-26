//
//    FILE: KT0803_minimal.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: minimal demo
//     URL: https://github.com/RobTillaart/TinyKT0803


#include "TinyKT0803.h"


TinyKT0803 FM_SEND;


void setup()
{
  //  Serial.begin(115200);
  //  while(!Serial);

  TinyWireM.begin();
  
  FM_SEND.begin();
  FM_SEND.setChannel(2000);  // * 0.05 = 100.00 MHz
  FM_SEND.setMute(false);
}

void loop()
{
}


//  -- END OF FILE --
