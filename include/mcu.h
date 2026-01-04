#ifndef MCU_H
#define MCU_H

#include <stdint.h>

#define mcu_delay_ms(ms) _delay_ms(ms)

// The direction of data from which it goes through the pin: in or out.
// For example: if you want to set a value to a pin, you should first
// set its direction to OUTPUT.
enum DIR {
  OUTPUT=1,
  INPUT=2,
};

// Digital value: 0 or 1, low or high.
enum DVAL {
  LOW=0,
  HIGH=1,
};

// Analog value ranges from 0 to 255.
typedef uint8_t AVAL;

// Enum of the reset pins on the chip.
enum RST_PIN;

// Enum of the digital pins on the chip.
enum DIGITAL_PIN;

// Enum of the leds on the chip.
enum LED;

// Enum of the analog pins on the chip.
enum ANALOG_PIN;

// Combination of all the pins, with different types, on the chip.
union PIN;

/*
* Get the DDRP of any pin.
*/
volatile uint8_t* mcu_pin_DDRP(union PIN pin);

/*
* Get the PORT of any pin.
*/
volatile uint8_t* mcu_pin_port(union PIN pin);

/*
* Get the pin number in its port.
*/
uint8_t mcu_pin_num(union PIN pin);

/*
* Set the data direction of a specific pin.
* NOTE: the data direction register port is detected automatically.
*/
void mcu_pin_dir(union PIN pin, enum DIR dir);

/*
* Write a value to a digital pin.
* NOTE: the pin direction should be set to OUTPUT first.
*/
void mcu_dpin_write(enum DIGITAL_PIN pin, enum DVAL digital_value);

/*
* Write a value to an analog pin.
* NOTE: the pin direction should be set to OUTPUT first.
*/
void mcu_apin_write(enum ANALOG_PIN pin, AVAL analog_value);

/*
* Read the digital value of a digital pin.
* NOTE: the pin direction should be set to INPUT first.
*/
enum DVAL mcu_dpin_read(enum DIGITAL_PIN pin);

/*
* Read the analog value of an analog pin.
* NOTE: the pin direction should be set to INPUT first.
*/
AVAL mcu_apin_read(enum ANALOG_PIN pin);

/*
* Light a led on.
* NOTE: the led pin direction should be set to OUTPUT first.
*/
void mcu_led_on(enum LED pin);

/*
* Light a led off.
* NOTE: the led pin direction should be set to OUTPUT first.
*/
void mcu_led_off(enum LED pin);

#endif
