A simple framework for developing applications on different MCUs. It's being written for the purpose of learning.

## Blinky Example

You can implement a blinky application, on Arduino Nano, with SMCUF as follows:

> NOTE: avr-gcc must be installed first on your machine.

```C
#include "include/nano.h"
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
```
