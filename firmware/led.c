#include <avr/io.h>
#include <avr/interrupt.h>
#include "led.h"

#define SET_LED(PORT, IDX, NUM) PORT = ((PORT & ~(1<<(IDX))) | (~(NUM) & 1<<(IDX)))

volatile uint8_t led_hour;
volatile uint8_t led_minute;
volatile uint8_t led_second;

void led_init(void) 
{
  // Set outputs
  ANODES_DIR |= HOUR_ANODE | MINUTE_ANODE | SECOND_ANODE; 
  LED0_DIR |= LED0; 
  LED1_DIR |= LED1; 
  LED2_DIR |= LED2; 
  LED3_DIR |= LED3; 
  LED4_DIR |= LED4; 
  LED5_DIR |= LED5; 

  // Clear LEDs
  ANODES_PORT = HOUR_ANODE | MINUTE_ANODE | SECOND_ANODE;
  LED0_PORT |= LED0;
  LED1_PORT |= LED1;
  LED2_PORT |= LED2;
  LED3_PORT |= LED3;
  LED4_PORT |= LED4;
  LED5_PORT |= LED5;

  TCCR0 |= (1<<WGM01); // CTC Mode
  TCCR0 |= (1<<CS02) | (1<<CS00); // Prescaler 1024
  OCR0 = 38; // 200Hz
  TIMSK |= (1<<OCIE0); // Enable CTC interruptions
}

ISR(TIMER0_COMP_vect) 
{
  static uint8_t counter = 1;    

  switch(counter) {
    case 1: 
      ANODES_PORT = ~HOUR_ANODE;
      SET_LED(LED0_PORT, 0, led_hour);
      SET_LED(LED1_PORT, 1, led_hour);
      SET_LED(LED2_PORT, 2, led_hour);
      SET_LED(LED3_PORT, 3, led_hour);
      SET_LED(LED4_PORT, 4, led_hour);
      SET_LED(LED5_PORT, 5, led_hour);
      break;
    case 2: 
      ANODES_PORT = ~MINUTE_ANODE;
      SET_LED(LED0_PORT, 0, led_minute);
      SET_LED(LED1_PORT, 1, led_minute);
      SET_LED(LED2_PORT, 2, led_minute);
      SET_LED(LED3_PORT, 3, led_minute);
      SET_LED(LED4_PORT, 4, led_minute);
      SET_LED(LED5_PORT, 5, led_minute);
      break;
    case 4: 
      ANODES_PORT = ~SECOND_ANODE;
      SET_LED(LED0_PORT, 0, led_second);
      SET_LED(LED1_PORT, 1, led_second);
      SET_LED(LED2_PORT, 2, led_second);
      SET_LED(LED3_PORT, 3, led_second);
      SET_LED(LED4_PORT, 4, led_second);
      SET_LED(LED5_PORT, 5, led_second);
      break;
  }

  counter <<= 1;

  if(counter > 4) 
  {
    counter = 1;        
  }
}