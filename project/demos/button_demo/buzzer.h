#ifndef buzzer_included
#define buzzer_included

#define F5 698
#define D6 1175
#define D5 587
#define E6 1319
#define F6 1397
#define C6 1047
#define A5 880
#define G5 784
#define E5 659

extern short frequency;
extern int delay;
extern int duration;

void buzzer_init();
void buzzer_set_period(short cycles);
void play_song();

#endif // included
