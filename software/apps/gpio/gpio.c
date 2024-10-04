#include "gpio.h"
#include <stdio.h>

typedef struct {
	uint32_t _unused_A[0x504/4];
	uint32_t OUT;
	uint32_t OUTSET;
	uint32_t OUTCLR;
	uint32_t IN;
	uint32_t DIR;
	uint32_t DIRSET;
	uint32_t DIRCLR;
	uint32_t LATCH;
	uint32_t DETECTMODE;
	uint32_t _unused_B[(0x700-0x524)/4-1];
	uint32_t PIN_CNF[32];
} gpio_regs_t;

volatile gpio_regs_t* gpio_p0 = (gpio_regs_t*) (0x50000000);
volatile gpio_regs_t* gpio_p1 = (gpio_regs_t*) (0x50000300);

// Inputs: 
//  gpio_num - gpio number 0-31 OR (32 + gpio number)
//  dir - gpio direction (INPUT, OUTPUT)
void gpio_config(uint8_t gpio_num, gpio_direction_t dir) {
  // Implement me
  // This function should configure the pin as an input/output
  // Hint: Use proper PIN_CNF instead of DIR
  if (gpio_num<32) {
  	gpio_p0->DIRSET=dir;
  }
  else {
  	gpio_p1->DIRSET=dir;
  }
}

// Inputs: 
//  gpio_num - gpio number 0-31 OR (32 + gpio number)
void gpio_set(uint8_t gpio_num) {
  // Implement me
  // This function should make the pin high
  // It can assume that the pin has already been configured
}

// Inputs: 
//  gpio_num - gpio number 0-31 OR (32 + gpio number)
void gpio_clear(uint8_t gpio_num) {
  // Implement me
  // This function should make the pin low
  // It can assume that the pin has already been configured
}

// Inputs: 
//  gpio_num - gpio number 0-31 OR (32 + gpio number)
// Output:
//  bool - pin state (true == high)
bool gpio_read(uint8_t gpio_num) {
  // Implement me
  // This function should read the value from the pin
  // It can assume that the pin has already been configured

  return true;
}

// prints out some information about the GPIO driver. Can be called from main()
void gpio_print(void) {
  // Use this function for debugging purposes
  // For example, you could print out struct field addresses
  // You don't otherwise have to write anything here
  printf("DIR %p\n", &gpio_p0->DIR);
  printf("OUT %p\n", &gpio_p0->OUT);
}

