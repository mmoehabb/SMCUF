#include "mcu.h"
#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 16000000UL // Define the CPU clock frequency (e.g., 16 MHz)
#endif

enum RST_PIN{
  RST1=PC6,
  RST2=PC6,
};

enum DIGITAL_PIN {
  RX=PD0,
  TX=PD1,
  D0=PD0,
  D1=PD1,
  D2=PD2,
  D3=PD3,
  D4=PD4,
  D5=PD5,
  D6=PD6,
  D7=PD7,
  D8=PB0,
  D9=PB1,
  D10=PB2,
  D11=PB3,
  D12=PB4,
  D13=PB5,
  D14=PC0,
  D15=PC1,
  D16=PC2,
  D17=PC3,
  D18=PC4,
  D19=PC5,
};

enum LED {
  LED1=PB5,
};

enum ANALOG_PIN {
  A0=PC0,
  A1=PC1,
  A2=PC2,
  A3=PC3,
  A4=PC4,
  A5=PC5,
};
