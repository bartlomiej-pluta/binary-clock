#include <avr/io.h>
#include <avr/interrupt.h>
#include "led.h"

volatile uint8_t led_brightness = 1;
volatile uint8_t led_hour;
volatile uint8_t led_minute;
volatile uint8_t led_second;

void led_init(void) 
{
  // Set outputs
  ANODES_DIR |= HOUR_ANODE | MINUTE_ANODE | SECOND_ANODE; 
  LED_DIR |= 0x3F; // 0b00111111

  // Clear LEDs
  ANODES_PORT = HOUR_ANODE | MINUTE_ANODE | SECOND_ANODE;
  LED_PORT |= 0x3F; // 0b00111111

  TCCR0 |= (1<<CS00);
  TIMSK |= (1<<TOIE0);
}

// ISR(TIMER0_COMP_vect) 
ISR(TIMER0_OVF_vect)
{
  static uint8_t pwm_counter = 0;
  static uint8_t counter = 0;
  static uint8_t curr_anode = 1;    

  switch(curr_anode) 
    {
      case 1: 
        LED_PORT = ~led_hour;   
        ANODES_PORT = led_brightness >= pwm_counter ? ~HOUR_ANODE : 0xFF;
        break;
      case 2: 
        LED_PORT = ~led_minute;   
        ANODES_PORT = led_brightness >= pwm_counter ? ~MINUTE_ANODE : 0xFF;  
        break;
      case 4: 
        LED_PORT = ~led_second;
        ANODES_PORT = led_brightness >= pwm_counter ? ~SECOND_ANODE : 0xFF; 
        break;
    }

  if(!counter)
  {    
    curr_anode <<= 1;

    if(curr_anode > 4) curr_anode = 1;          

    counter = 250;
  }

  --counter;
  ++pwm_counter;
}