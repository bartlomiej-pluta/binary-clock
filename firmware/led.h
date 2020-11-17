#ifndef __LED_H__
#define __LED_H__

#define LED_PORT PORTA
#define LED_DIR DDRA

#define ANODES_PORT PORTD
#define ANODES_DIR DDRD
#define HOUR_ANODE (1<<PD5)
#define MINUTE_ANODE (1<<PD6)
#define SECOND_ANODE (1<<PD7)

extern volatile uint8_t led_hour;
extern volatile uint8_t led_minute;
extern volatile uint8_t led_second;

void led_init(void);

#endif