//
//    FILE: KT0803_register_dumper.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: debugger
//     URL: https://github.com/RobTillaart/TinyKT0803
//
//  one must make the protected function public to have this work.

#include "TinyKT0803.h"
#include "SoftwareSerial.h"

TinyKT0803 FM_SEND;

uint8_t tx = 3;
uint8_t rx = 255;  //  not needed here

SoftwareSerial ser(tx, rx);


void setup()
{
  ser.begin(9600);
  ser.println("\nKT0803_register_dump\n");

  TinyWireM.begin();
  //  give I2C time to initialize
  delay(500);

  FM_SEND.begin();
  FM_SEND.setChannel(2000);  // * 0.05 = 100.00 MHz
  FM_SEND.setMute(false);

  FM_SEND.setChannel(2000);
  registerDump();
  FM_SEND.setChannel(2001);
  registerDump();
  FM_SEND.setChannel(2002);
  registerDump();
  FM_SEND.setChannel(2003);
  registerDump();
  FM_SEND.setChannel(2004);
  registerDump();
  FM_SEND.setChannel(2005);
  registerDump();
}

void loop()
{
}


void registerDump()
{
  ser.println();
  for (int reg = 0x00; reg <= 0x16; reg++)
  {
    int data = FM_SEND.readData(reg);
    ser.print(reg);
    ser.print("\t");
    if (data < 0x10) ser.print("0");
    ser.print(data, HEX);
    ser.print("\t");
    ser.print(data, BIN);
    ser.println();
  }
}

//  -- END OF FILE --
