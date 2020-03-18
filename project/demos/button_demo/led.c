#include <msp430.h>
#include "led.h"
#include "state_machine.h"
#include "switches.h"


unsigned char red_on = 0, green_on = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed) {
    
    if (sw1_down) {
      // call state machine count to 3 in binary
      toggle();
    }

    else if (sw2_down) {
      // Have LEDS flicker or glow
    }

    else if (sw3_down) {
      // Have LEDS turn green for correct answer red for wrong answer
    }

    else if (sw4_down) {
 
    }
    
    char ledFlags = greenVal[green_on] | redVal[red_on];
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;     // set bit for on leds
  }
  switch_state_changed = 0;
}


