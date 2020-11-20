#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "led.h"

static volatile uint8_t led_btnes;

static struct LED_DIGS display;

void led_init(void) 
{
  // Set outputs
  ANODES_DIR |= DIG0_ANODE | DIG1_ANODE | DIG2_ANODE; 
  LED_DIR |= 0x3F; // 0b00111111

  // Clear LEDs
  ANODES_PORT = DIG0_ANODE | DIG1_ANODE | DIG2_ANODE;
  LED_PORT |= 0x3F; // 0b00111111
  
  TCCR0 |= (1<<CS00);
  TIMSK |= (1<<TOIE0);
}

void led_display(struct LED_DIGS* digits)
{
  display = *digits;
}

void led_set_btnes(uint8_t btnes)
{
  led_btnes = 1<<btnes;  
}

// 8 MHz / 256 = 31.25 kHz
ISR(TIMER0_OVF_vect)
{
  static uint8_t pwm_counter = 0;
  static uint8_t counter = 0;
  static uint8_t curr_anode = 1;    

  switch(curr_anode) 
  {
    case 1: 
      LED_PORT = ~display.dig0;   
      ANODES_PORT = led_btnes >= pwm_counter ? ~DIG0_ANODE : 0xFF;
      break;
    case 2: 
      LED_PORT = ~display.dig1;   
      ANODES_PORT = led_btnes >= pwm_counter ? ~DIG1_ANODE : 0xFF;  
      break;
    case 4: 
      LED_PORT = ~display.dig2;
      ANODES_PORT = led_btnes >= pwm_counter ? ~DIG2_ANODE : 0xFF; 
      break;
  }

  // 31.25 kHz / 250 = 125 Hz
  if(!counter)
  {    
    curr_anode <<= 1;

    if(curr_anode > 4) curr_anode = 1;          

    counter = 250;
  }

  --counter;
  ++pwm_counter;
}