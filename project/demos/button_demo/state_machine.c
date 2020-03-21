#include <msp430.h>
#include <stdlib.h>
#include "state_machine.h"
#include "led.h"


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

void reset_state() {
  red_on = 0;
  green_on = 0;
}


