#include <avr/io.h>
#include <avr/interrupt.h>
#include "ptimer.h"

volatile uint16_t tim_debounce;

void ptimer_init(void)
{
  tim_debounce = 0;

  TCCR2 |= (1<<WGM21);
  TCCR2 |= (1<<CS22) | (1<<CS21) | (1<<CS20);
  OCR2 = 8000000UL/1024UL/100UL; // 8 MHz / prescaler / f (==100 Hz)
  TIMSK |= (1<<OCIE2);
}

// ~100 Hz
ISR(TIMER2_COMP_vect)
{
  if(tim_debounce) --tim_debounce;
}