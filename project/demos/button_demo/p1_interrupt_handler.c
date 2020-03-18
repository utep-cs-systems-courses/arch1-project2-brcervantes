#include <msp430.h>
#include "switches.h"
#include "buzzer.h"

/* Switch on P2 (S2) */
void __interrupt_vec(PORT2_VECTOR) Port_2() {
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
  
}

void __interrupt_vec(WDT_VECTOR) WDT() {
  static char count = 0;
  if (++count == 100) {
    int i = 0;
    
    while (i < delay) {
      buzzer_set_period(0);
      i++;
      
    }
  }
}

