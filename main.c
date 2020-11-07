#include <avr/io.h>
#include <avr/interrupt.h>
#include "led.h"

int main() 
{
  led_init();

  sei();

  led_hour = 0;
  led_minute = 0;
  led_second = 0;

  while(1) 
  {

  }
}