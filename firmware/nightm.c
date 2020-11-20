#include "nightm.h"
#include "ptimer.h"
#include "led.h"
#include "rtc.h"

#define TIMER_FREQ 100  // ptimer works with 100Hz so it's going to reduce time to 1Hz = 1s

void nightm_config(struct NIGHTM_CFG* cfg)
{  
  ram_cfg.night_mode = *cfg;  
}

void nightm_handle(struct RTC_DATA* rtc)
{  
  if(ram_cfg.night_mode.led_btnes >= 0)
  {
    uint16_t current = TIME_2_INT(rtc->time);  
    uint16_t begin = TIME_2_INT(ram_cfg.night_mode.begin);
    uint16_t end = TIME_2_INT(ram_cfg.night_mode.end);

    led_set_btnes((begin <= current && current < end) ? ram_cfg.night_mode.led_btnes : ram_cfg.led_btnes);    
  }
}