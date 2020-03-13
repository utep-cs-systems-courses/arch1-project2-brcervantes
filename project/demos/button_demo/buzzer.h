#ifndef buzzer_included
#define buzzer_included

short frequency;

void buzzer_init();
void buzzer_set_period(short cycles);
void play_song();

#endif // included
