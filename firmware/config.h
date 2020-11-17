#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <avr/eeprom.h>
#include <avr/pgmspace.h>

#define LED_BRIGHTNESS 127

struct CFG
{
  uint8_t led_brightness;
};

extern struct CFG ram_cfg;
extern struct CFG eem_cfg EEMEM;
extern const struct CFG pgm_cfg PROGMEM;

void map_eem2ram(void);
void map_pgm2ram(void);
void dump_ram2eem(void);
void load_defaults(void);
void cfg_init(void);

#endif