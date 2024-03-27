#pragma once
//
//    FILE: TinyKT0803.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: Arduino Library for KT0803 and KT0803K FM transmitter. Tiny edition.
//     URL: https://github.com/RobTillaart/TinyKT0803


#include "Arduino.h"
#include "TinyWireM.h"
#include "USI_TWI_Master.h"

#define TINY_KT0803_LIB_VERSION          (F("0.1.0"))


class TinyKT0803
{
public:
  TinyKT0803();

  bool begin(float freq = 90.0, bool mute = true);
  bool isConnected();


  //  FM FREQUENCY
  bool     setFrequency(float MHz);
  float    getFrequency();
  bool     setChannel(uint16_t channel);
  uint16_t getChannel();


  //  GAIN
  bool setPGA(uint8_t pga);  //  0-3 = 0..-12dB   4-7 = 0..12dB
  // 111: 12dB
  // 110: 8dB
  // 101: 4dB
  // 100: 0dB
  // 000: 0dB
  // 001: -4dB
  // 010: -8dB
  // 011: -12dB
  uint8_t getPGA();

  bool setRFGain(uint8_t rfgain);  //  0-15
  uint8_t getRFgain();


  //  REGION SELECTION
  //  first four are wrappers
  void setEurope()    { setPHTCNST(true); };
  void setAustralia() { setPHTCNST(true); };
  void setUSA()       { setPHTCNST(false); };
  void setJapan()     { setPHTCNST(false); };
  bool setPHTCNST(bool on);
  bool getPHTCNST();


  //  PILOT TONE ADJUST (PLTADJ)
  bool setPilotToneAdjust(uint8_t mode);  //  HIGH = 1 LOW = 0
  uint8_t getPilotToneAdjust();


  //  MUTE software
  bool setMute(bool mute);  //  true == muted
  bool getMute();           //  isMuted().


protected:

  bool writeData(uint8_t reg, uint8_t data);
  int readData(uint8_t reg);

  uint8_t _address = 0x3E;  //  fixed address for KT0803.
};


/////////////////////////////////////////////////////////////////////////////
//
//  DERIVED CLASSES
//
class TinyKT0803K : public TinyKT0803
{
public:
  TinyKT0803K();

  //  CHANNEL
  bool     setChannel(uint16_t channel);
  uint16_t getChannel();
};


//  -- END OF FILE --

