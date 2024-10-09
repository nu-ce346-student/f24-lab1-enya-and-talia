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

int rows[5] = {21, 22, 15, 24, 19};
int cols[5] = {28, 11, 31, 37, 30};

int main(void) {
  printf("Board started!\n");

  // Turn on all LEDs on the back of the Microbit
  // Add code here
  for (int i=0; i<5; i++) {
  	gpio_config(rows[i], 1);
  	gpio_config(cols[i], 1);
  	gpio_set(rows[i]);
  	gpio_clear(cols[i]);
  }
  printf("LEDs turned on\n");

  gpio_config(14, 0);
  gpio_config(23, 0);


  // Control LED with raw MMIO
  // Microphone LED is P0.20 and active high
  // Add code here
  *(uint32_t*) (gpio+dir) |= 1<<20;
  *(uint32_t*) (gpio+out) |= 1<<20;

  // loop forever
  printf("Looping\n");
  while (1) {

    // Control LED with buttons
    // Button A is P0.14 and active low
    // Button B is P0.23 and active low
    // Add code here
    if (!gpio_read(14)) {
    	gpio_set(20);
    }
    if (!gpio_read(23)) {
    	gpio_clear(20);
    }

    nrf_delay_ms(100);
  }
}

