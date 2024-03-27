//
//    FILE: KT0803_register_dumper.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: debugger
//     URL: https://github.com/RobTillaart/TinyKT0803
//
//  one must make the protected functions public to have this work.

#include "TinyKT0803.h"
#include <Tiny4kOLED.h>

TinyKT0803 FM_SEND;

void oledInit() 
{
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
  oled.setFont(FONT8X16P);
  oled.on();
}

void oledDebug(uint8_t reg) 
{
  oled.clear();
  oled.setCursor(20, 2);
  oled.print(FM_SEND.readData(reg));
}

void setup()
{
  oledInit();

  TinyWireM.begin();
  //  give I2C time to initialize
  delay(500);

  FM_SEND.begin();
  FM_SEND.setChannel(2000);  // * 0.05 = 100.00 MHz
  FM_SEND.setMute(false);

  oledDebug(0);
  delay(3000);
  oledDebug(1);
  delay(3000);
  oledDebug(2); 
}

void loop()
{
}


//  -- END OF FILE --
