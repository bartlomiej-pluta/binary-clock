#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include "time.h"

#define AUTO_BTNES_SIZE 4

#define LED_BRIGHTNESS 7
#define NIGHT_MODE { -1, { 0, 0 }, { 0, 0 } }

struct NIGHTM_CFG
{
  int8_t led_btnes;
  struct TIME_HM begin;
  struct TIME_HM end;
};

struct CFG
{
  uint8_t led_btnes;
  struct NIGHTM_CFG night_mode;
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