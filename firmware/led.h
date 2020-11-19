#ifndef __LED_H__
#define __LED_H__

#include "time.h"

#define LED_PORT PORTA
#define LED_DIR DDRA

#define ANODES_PORT PORTD
#define ANODES_DIR DDRD
#define HOUR_ANODE (1<<PD5)
#define MINUTE_ANODE (1<<PD6)
#define SECOND_ANODE (1<<PD7)

extern volatile struct TIME_HMS led_display;
extern volatile uint8_t led_btnes;

void led_init(void);
void led_set_btnes(uint8_t btnes);
void led_inc_btnes(void);

#endif