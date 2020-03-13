#include <msp430.h>
#include "switches.h"
#include "led.h"

//booleans
char sw1_down, sw2_down, sw3_down, sw4_down, switch_state_changed; 

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  sw1_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  sw2_down = (p2val & SW2) ? 0 : 1;
  sw3_down = (p2val & SW3) ? 0 : 1;
  sw4_down = (p2val & SW4) ? 0 : 1;
  switch_state_changed = 1;

  if (sw1_down) {
    // count to 3 binary
    led_update();
  }

  if (sw2_down) {
    // play zelda melody
  }

  if (sw3_down) {
    // play simon says
  }

  if (sw4_down) {
    // turn off buzzer
  }
}
