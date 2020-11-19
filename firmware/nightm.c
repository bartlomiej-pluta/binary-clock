#include "nightm.h"
#include "led.h"

#define TIME2INT(TIME) ((TIME).hour*60 + (TIME).minute)

void nightm_config(struct NIGHTM_CFG* cfg)
{  
  ram_cfg.night_mode = *cfg;
  dump_ram2eem();
}

void nightm_handle(struct TIME_HMS* curr_time)
{  
  if(ram_cfg.night_mode.led_btnes >= 0)
  {
    uint16_t current = TIME2INT(*curr_time);  
    uint16_t begin = TIME2INT(ram_cfg.night_mode.begin);
    uint16_t end = TIME2INT(ram_cfg.night_mode.end);

    led_btnes = (begin <= current && current < end)
    ? 1<<(ram_cfg.night_mode.led_btnes)
    : 1<<(ram_cfg.led_btnes);
  }
}