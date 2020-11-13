#include <avr/io.h>
#include <avr/interrupt.h>
#include "ptimer.h"

volatile uint16_t timers[TIMERS_COUNT];

void ptimer_init(void)
{
  for(uint8_t i=0; i<TIMERS_COUNT; ++i) timers[i] = 0;

  TCCR2 |= (1<<WGM21); // CTC Mode
	TCCR2 |= (1<<CS22) | (1<<CS21) | (1<<CS20); // Prescaler 1024
	OCR2 = 78; // ~100Hz
	TIMSK |= (1<<OCIE2); // Enable CTC interruptions
}

ISR(TIMER2_COMP_vect)
{
  for(uint8_t i=0; i<TIMERS_COUNT; ++i)
  {
    if(timers[i]) --timers[i];
  }  
}