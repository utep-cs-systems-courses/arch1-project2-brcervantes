#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

short frequency = 0;
int delay= 0;
int duration = 0;

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}


void play_song()
{
  int notes[43] = {D5, F5, D6, D5, F5, D6, E6, F6, E6, F6, E6, C6, A5, A5, D5, F5, G5, A5, A5,
		     D5, F5, G5, E5, D5, F5, D6, D5, F5, D6, E6, F6, E6, F6, E6, C6, A5, A5, D5,
		     F5, G5, A5, A5, D5};

  int note_duration[43] = {100, 100, 200, 100, 100, 200, 200, 100, 100, 100, 100, 100, 100, 200,
			  200, 100, 100, 100, 200, 200, 100, 100, 100, 100, 100, 200, 100, 100,
			  200, 200, 100, 100, 100, 100, 100, 100, 200, 200, 100, 100, 300, 200,
			  300};

  int delay_time[43] = {80, 80, 250, 80, 80, 250, 200, 100, 80, 80, 80, 80, 300, 100, 100, 100,
			100, 500, 100, 100, 100, 100, 500, 80, 80, 250, 80, 80, 250, 200, 100, 80,
			80, 80, 80, 300, 100, 100, 100, 100, 100, 100, 2000};

  duration = 100; 
  delay = 80;
  buzzer_set_period(D5);

  duration = 100;
  delay = 80;
  buzzer_set_period(F5);

  duration = 200;
  delay = 250;
  buzzer_set_period(D6);

  duration = 100;
  buzzer_set_period(D5);
  duration = 100;
  delay = 80;

}


    
    
  

