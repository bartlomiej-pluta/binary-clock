#include <avr/io.h>
#include "common.h"
#include "config.h"
#include "keyboard.h"
#include "buzzer.h"
#include "debounce.h"
#include "rtc.h"
#include "led.h"

uint8_t k_inc_hour, k_inc_minute, k_inc_second, k_inc_brightness;

void inc_hour(void)
{  
  rtc_inc_time(HOUR);
  buz_on();
}

void inc_minute(void)
{  
  rtc_inc_time(MINUTE);
  buz_on();
}

void inc_second(void)
{  
  rtc_inc_time(SECOND);
  buz_on();
}

void inc_brightness(void)
{  
  if(++ram_cfg.led_btnes > 7) ram_cfg.led_btnes = 0;
  led_set_btnes(ram_cfg.led_btnes);
  dump_ram2eem();
  buz_on();
}

void kbd_init(void)
{
  R_DDR(KEYBOARD_PORT) &= ~(1<<KEY_INC_HOUR | 1<<KEY_INC_MINUTE | 1<<KEY_INC_SECOND | 1<<KEY_INC_BRIGHTNESS);
  R_PORT(KEYBOARD_PORT) |= 1<<KEY_INC_HOUR | 1<<KEY_INC_MINUTE | 1<<KEY_INC_SECOND | 1<<KEY_INC_BRIGHTNESS;
}

void kbd_handle_event(void)
{
  SuperDebounce(&k_inc_hour, &R_PIN(KEYBOARD_PORT), 1<<KEY_INC_HOUR, 20, 0, &inc_hour, 0);
  SuperDebounce(&k_inc_minute, &R_PIN(KEYBOARD_PORT), 1<<KEY_INC_MINUTE, 20, 0, &inc_minute, 0);
  SuperDebounce(&k_inc_second, &R_PIN(KEYBOARD_PORT), 1<<KEY_INC_SECOND, 20, 0, &inc_second, 0);
  SuperDebounce(&k_inc_brightness, &R_PIN(KEYBOARD_PORT), 1<<KEY_INC_BRIGHTNESS, 20, 0, &inc_brightness, 0);
}