#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "led.h"

volatile struct TIME_HMS led_display = { 0, 0, 0 };
volatile uint8_t led_btnes;

void led_init(void) 
{
  // Set brightness
  led_btnes = 1<<(ram_cfg.led_brightness);

  // Set outputs
  ANODES_DIR |= HOUR_ANODE | MINUTE_ANODE | SECOND_ANODE; 
  LED_DIR |= 0x3F; // 0b00111111

  // Clear LEDs
  ANODES_PORT = HOUR_ANODE | MINUTE_ANODE | SECOND_ANODE;
  LED_PORT |= 0x3F; // 0b00111111
  
  TCCR0 |= (1<<CS00);
  TIMSK |= (1<<TOIE0);
}

void led_set_btness(uint8_t btnes)
{
  if(btnes > 7) btnes = 0;
  led_btnes = 1<<btnes;  
  ram_cfg.led_brightness = btnes;
  dump_ram2eem();
}

void led_inc_btness(void)
{
  if(++(ram_cfg.led_brightness) > 7) ram_cfg.led_brightness = 0;
  led_btnes = 1<<(ram_cfg.led_brightness);
  dump_ram2eem();
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
      LED_PORT = ~led_display.hour;   
      ANODES_PORT = led_btnes >= pwm_counter ? ~HOUR_ANODE : 0xFF;
      break;
    case 2: 
      LED_PORT = ~led_display.minute;   
      ANODES_PORT = led_btnes >= pwm_counter ? ~MINUTE_ANODE : 0xFF;  
      break;
    case 4: 
      LED_PORT = ~led_display.second;
      ANODES_PORT = led_btnes >= pwm_counter ? ~SECOND_ANODE : 0xFF; 
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