#include <util/delay.h>
#include "include/nano.h"

void setup() {
  set_dir(LED1, OUTPUT);
}

int main(void) {
  setup();

  while (1) {
    pin_write(LED1, HIGH);
    _delay_ms(500);
    pin_write(LED1, LOW);
    _delay_ms(500);
  }
}
