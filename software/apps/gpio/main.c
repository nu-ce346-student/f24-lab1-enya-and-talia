// GPIO app
//
// Uses MMIO to control GPIO pins

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf.h"
#include "nrf_delay.h"

#include "microbit_v2.h"
#include "gpio.h"

uint32_t gpio = 0x50000000;
uint32_t out = 0x504;
uint32_t dir = 0x514;

int main(void) {
  printf("Board started!\n");

  // Turn on all LEDs on the back of the Microbit
  // Add code here

  // Control LED with raw MMIO
  // Microphone LED is P0.20 and active high
  // Add code here
  *(uint32_t*) (gpio+dir) = 1<<20;
  *(uint32_t*) (gpio+out) = 1<<20;

  // loop forever
  printf("Looping\n");
  while (1) {

    // Control LED with buttons
    // Button A is P0.14 and active low
    // Button B is P0.23 and active low
    // Add code here

    nrf_delay_ms(100);
  }
}

