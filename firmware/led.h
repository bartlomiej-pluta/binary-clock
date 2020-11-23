#ifndef __LED_H__
#define __LED_H__

#define LED_PORT A

#define ANODES_PORT D
#define DIG0_ANODE 5
#define DIG1_ANODE 6
#define DIG2_ANODE 7

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