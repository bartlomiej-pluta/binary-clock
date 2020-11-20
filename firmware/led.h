#ifndef __LED_H__
#define __LED_H__

#define LED_PORT PORTA
#define LED_DIR DDRA

#define ANODES_PORT PORTD
#define ANODES_DIR DDRD
#define DIG0_ANODE (1<<PD5)
#define DIG1_ANODE (1<<PD6)
#define DIG2_ANODE (1<<PD7)

struct LED_DIGS
{
  uint8_t dig0;
  uint8_t dig1;
  uint8_t dig2;
};

void led_init(void);
void led_display(struct LED_DIGS* digits);
void led_set_btnes(uint8_t btnes);

#endif