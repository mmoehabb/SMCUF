#ifndef MCU_NANO_H
#define MCU_NANO_H

#include "mcu.h"
#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 16000000UL // Define the CPU clock frequency (e.g., 16 MHz)
#endif

enum RST_PIN{
  // Port C
  RST1=1,
  RST2=2,
};

enum DIGITAL_PIN {
  // Port D
  RX=3,
  TX=4,
  D0=5,
  D1=6,
  D2=7,
  D3=8,
  D4=9,
  D5=10,
  D6=11,
  D7=12,
  // Port B
  D8=13,
  D9=14,
  D10=15,
  D11=16,
  D12=17,
  D13=18,
  // Port C
  D14=19,
  D15=20,
  D16=21,
  D17=22,
  D18=23,
  D19=24,
};

enum ANALOG_PIN {
  // Port C
  A0=25,
  A1=26,
  A2=27,
  A3=28,
  A4=29,
  A5=30,
};

enum LED {
  // Port B
  LED1=31,
};

union PIN {
  enum RST_PIN rpin;
  enum DIGITAL_PIN dpin;
  enum ANALOG_PIN apin;
  enum LED led;
};

#endif
