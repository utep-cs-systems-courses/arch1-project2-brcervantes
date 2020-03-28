#include <msp430.h>
#include <stdlib.h>
#include "state_machine.h"
#include "led.h"
#include "toggle.h"

/*
method toggle turned into assembly

see toggle.s for assembly part

void toggle() {

  static char state = 0;
  
  switch (state) {

  case 0:
    red_on   = 0;
    green_on = 0;
    state    = 1;
    break;

  case 1:
    red_on   = 1;
    green_on = 0;
    state    = 2;
    break;

  case 2:
    red_on   = 0;
    green_on = 1;
    state    = 3;
    break;

  case 3:
    red_on   = 1;
    green_on = 1;
    state    = 0;
    break;
  }
}
*/

/*
  method to reset current state of LEDS
 */
void reset_state() {
  red_on = 0;
  green_on = 0;
  led_update();
}

/*
  method to assign the state of the LEDS
 */
void led_state(unsigned char g, unsigned char r) {
  green_on = g;
  red_on = r;
  led_changed = 1;
  led_update();
}

/*
  method to delay action for specific time
 */
void delay(unsigned int t) {
  unsigned int i;
  for (i = t; i > 0; i--) {
    __delay_cycles(1);
  }
}

/*
  method to alternate and dim both LEDS
 */
void dim() {
  while (dim_on) {
    unsigned int i;
    for (i = 1; i < 1200; i++) {
      led_state(1,0);
      delay(i);
      
      led_state(0,1);
      delay(1200-i);
    }
    for (i = 1200; i > 1; i--) {
      led_state(1,0);
      delay(i);
      
      led_state(0,1);
      delay(1200-i);
    }
    
  }
}
