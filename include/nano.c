#include "nano.h"

void set_dir(enum PIN pin, enum DIR dir) {
  if (dir == OUTPUT) DDRB |= (1 << pin);
  else if (dir == INPUT) DDRB &= ~(1 << pin);
}

void pin_write(enum PIN pin, enum PVAL val) {
  switch (val) {
    case LOW:
      PORTB |= (1 << pin);
      break;
    case HIGH:
      PORTB &= ~(1 << pin);
      break;
  }
}

enum PVAL pin_read(enum PIN pin) {
  int shifted = PORTB >> pin;
  int high = 1 & shifted;
  return high > 0 ? HIGH : LOW;
}
