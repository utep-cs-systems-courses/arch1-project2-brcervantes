
#include <msp430.h>
#include "led.h"
#include "state_machine.h"
#include "switches.h"


unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;
unsigned char dim_on = 0;

static int IncDec_PWM = 1;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_changed = 1;
  dim_on = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed | led_changed | dim_on) {    
    
    char ledFlags = greenVal[green_on] | redVal[red_on];
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;     // set bit for on leds
  }
  switch_state_changed = 0;
  led_changed = 0;
  dim_on = 0;
}

void dim_led() {
  
  //WDTCTL = WDTPW +WDTHOLD;
  DCOCTL = 0;
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;

  P1DIR |= BIT6;
  P1SEL |= BIT6;

  // Timer0_A Set-Up
  TA0CCR0 |= 1000-1;
  TA0CCR1 |= 1;
  TA0CCTL1 |= OUTMOD_7;
  TA0CTL |= TASSEL_2 + MC_1;

  // Timer1_A Set-Up
  TA1CCR0 |= 4000-1;
  TA1CCTL0 |= CCIE;
  TA1CTL |= TASSEL_2 + MC_1;

  _BIS_SR(LPM0_bits + GIE);

}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer1_A0 (void) {

  while (1) {
    TA0CCR1 += IncDec_PWM*2;

    if (TACCR1 > 998 || TA0CCR1 < 2)
      IncDec_PWM = -IncDec_PWM;
  }
}
