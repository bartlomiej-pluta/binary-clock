#ifndef __LED_H__
#define __LED_H__

#define LED0_PORT PORTA
#define LED0_DIR DDRA
#define LED0 (1<<0)
#define LED1_PORT PORTA
#define LED1_DIR DDRA
#define LED1 (1<<1)
#define LED2_PORT PORTA
#define LED2_DIR DDRA
#define LED2 (1<<2)
#define LED3_PORT PORTA
#define LED3_DIR DDRA
#define LED3 (1<<3)
#define LED4_PORT PORTA
#define LED4_DIR DDRA
#define LED4 (1<<4)
#define LED5_PORT PORTA
#define LED5_DIR DDRA
#define LED5 (1<<5)

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