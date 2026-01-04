#include "include/nano.h"
#include "mcu.h"
#include <util/delay.h>

void setup() {
  union PIN p = { .led = LED1 };
  mcu_pin_dir(p, OUTPUT);
}

void loop() {
  mcu_led_on(LED1);
  mcu_delay_ms(600);
  mcu_led_off(LED1);
  mcu_delay_ms(300);
}

int main(void) {
  setup();
  while (1) loop();
}
