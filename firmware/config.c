#include "config.h"

struct CFG ram_cfg;
struct CFG eem_cfg EEMEM;
const struct CFG pgm_cfg PROGMEM = {
  LED_BRIGHTNESS,
  NIGHT_MODE
};

void map_eem2ram(void)
{
  eeprom_read_block(&ram_cfg, &eem_cfg, sizeof(ram_cfg));
}

void map_pgm2ram(void)
{
  memcpy_P(&ram_cfg, &pgm_cfg, sizeof(ram_cfg));
}

void dump_ram2eem(void)
{
  eeprom_write_block(&ram_cfg, &eem_cfg, sizeof(ram_cfg));
}

void load_defaults(void)
{
  map_pgm2ram();
  dump_ram2eem();
}

void cfg_init(void)
{
  uint8_t i;
  uint8_t len = sizeof(ram_cfg);
  uint8_t* ram_cfg_byte = (uint8_t*) &ram_cfg;

  map_eem2ram();

  for(i=0; i<len; ++i) if(*ram_cfg_byte++ != 0xFF) break;
  
  if(i == len) load_defaults();
}