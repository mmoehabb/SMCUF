#ifndef MCU_NANO_IMPL
#define MCU_NANO_IMPL

#include "nano.h"
#include "mcu.h"
#include <stdint.h>

volatile uint8_t* mcu_pin_DDRP(union PIN pin) {
  switch (pin.led) {
    case LED1: return &DDRB;
  }
  switch (pin.rpin) {
    case RST1: return &DDRC;
    case RST2: return &DDRC;
  }
  switch (pin.apin) {
    case A0: return &DDRC;
    case A1: return &DDRC;
    case A2: return &DDRC;
    case A3: return &DDRC;
    case A4: return &DDRC;
    case A5: return &DDRC;
  }
  switch (pin.dpin) {
    case RX: return &DDRD;
    case TX: return &DDRD;
    case D0: return &DDRD;
    case D1: return &DDRD;
    case D2: return &DDRD;
    case D3: return &DDRD;
    case D4: return &DDRD;
    case D5: return &DDRD;
    case D6: return &DDRD;
    case D7: return &DDRD;
    case D8: return &DDRB;
    case D9: return &DDRB;
    case D10: return &DDRB;
    case D11: return &DDRB;
    case D12: return &DDRB;
    case D13: return &DDRB;
    case D14: return &DDRC;
    case D15: return &DDRC;
    case D16: return &DDRC;
    case D17: return &DDRC;
    case D18: return &DDRC;
    case D19: return &DDRC;
  }
  return 0;
}

volatile uint8_t* mcu_pin_port(union PIN pin) {
  switch (pin.led) {
    case LED1: return &PORTB;
  }
  switch (pin.rpin) {
    case RST1: return &PORTC;
    case RST2: return &PORTC;
  }
  switch (pin.apin) {
    case A0: return &PORTC;
    case A1: return &PORTC;
    case A2: return &PORTC;
    case A3: return &PORTC;
    case A4: return &PORTC;
    case A5: return &PORTC;
  }
  switch (pin.dpin) {
    case RX: return &PORTD;
    case TX: return &PORTD;
    case D0: return &PORTD;
    case D1: return &PORTD;
    case D2: return &PORTD;
    case D3: return &PORTD;
    case D4: return &PORTD;
    case D5: return &PORTD;
    case D6: return &PORTD;
    case D7: return &PORTD;
    case D8: return &PORTB;
    case D9: return &PORTB;
    case D10: return &PORTB;
    case D11: return &PORTB;
    case D12: return &PORTB;
    case D13: return &PORTB;
    case D14: return &PORTC;
    case D15: return &PORTC;
    case D16: return &PORTC;
    case D17: return &PORTC;
    case D18: return &PORTC;
    case D19: return &PORTC;
  }
  return 0;
}

uint8_t mcu_pin_num(union PIN pin) {
  switch (pin.led) {
    case LED1: return PB5;
  }
  switch (pin.rpin) {
    case RST1: return PC6;
    case RST2: return PC6;
  }
  switch (pin.apin) {
    case A0: return PC0;
    case A1: return PC1;
    case A2: return PC2;
    case A3: return PC3;
    case A4: return PC4;
    case A5: return PC5;
  }
  switch (pin.dpin) {
    case RX: return PD0;
    case TX: return PD1;
    case D0: return PD0;
    case D1: return PD1;
    case D2: return PD2;
    case D3: return PD3;
    case D4: return PD4;
    case D5: return PD5;
    case D6: return PD6;
    case D7: return PD7;
    case D8: return PB0;
    case D9: return PB1;
    case D10: return PB2;
    case D11: return PB3;
    case D12: return PB4;
    case D13: return PB5;
    case D14: return PC0;
    case D15: return PC1;
    case D16: return PC2;
    case D17: return PC3;
    case D18: return PC4;
    case D19: return PC5;
  }
  return 0;
}

void mcu_pin_dir(union PIN pin, enum DIR dir) {
  volatile uint8_t* ddr = mcu_pin_DDRP(pin);
  uint8_t pin_num = mcu_pin_num(pin);
  if (dir == OUTPUT) *ddr |= (1 << pin_num);
  else if (dir == INPUT) *ddr &= ~(1 << pin_num);
}

void mcu_dpin_write(enum DIGITAL_PIN pin, enum DVAL digital_value) {
  union PIN p = { .dpin =  pin };
  switch (digital_value) {
    case LOW:
      PORTB |= (1 << mcu_pin_num(p));
      break;
    case HIGH:
      PORTB &= ~(1 << mcu_pin_num(p));
      break;
  }
}

void mcu_apin_write(enum ANALOG_PIN pin, AVAL analog_value);

enum DVAL mcu_dpin_read(enum DIGITAL_PIN pin) {
  int shifted = PORTB >> pin;
  int high = 1 & shifted;
  return high > 0 ? HIGH : LOW;
}

AVAL mcu_apin_read(enum ANALOG_PIN pin);

void mcu_led_on(enum LED pin) {
  union PIN p = { .led =  pin };
  volatile uint8_t* port = mcu_pin_port(p);
  uint8_t pnum = mcu_pin_num(p);
  *port &= ~(1 << pnum);
}

void mcu_led_off(enum LED pin) {
  union PIN p = { .led =  pin };
  volatile uint8_t* port = mcu_pin_port(p);
  uint8_t pnum = mcu_pin_num(p);
  *port |= (1 << pnum);
}

#endif
