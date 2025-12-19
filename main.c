#ifndef F_CPU
#define F_CPU 16000000UL // Define the CPU clock frequency (e.g., 16 MHz)
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // --- Setup Phase ---

  // Set Pin PB5 as an output pin
  // DDRB is the Data Direction Register for Port B
  // (1 << PB5) sets the 5th bit (PB5) to 1 (OUTPUT)
  DDRB |= (1 << PB5);

  while (1) {
    // Turn LED on (Set PB5 HIGH)
    // PORTB is the Port B data register (controls output state)
    PORTB |= (1 << PB5);

    _delay_ms(500);

    // Turn LED off (Set PB5 LOW)
    PORTB &= ~(1 << PB5);

    _delay_ms(500);
  }
}
