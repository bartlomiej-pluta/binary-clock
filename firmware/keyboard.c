#include <avr/io.h>
#include "config.h"
#include "keyboard.h"
#include "debounce.h"
#include "rtc.h"
#include "led.h"

uint8_t k_inc_hour, k_inc_minute, k_inc_second, k_inc_brightness;

void inc_hour(void)
{
  led_hour = (led_hour + 1) % 24;
  rtc_set_time(HOUR, led_hour);
}

void inc_minute(void)
{
  led_minute = (led_minute + 1) % 60;
  rtc_set_time(MINUTE, led_minute);
}

void inc_second(void)
{
  led_second = (led_second + 1) % 60;
  rtc_set_time(SECOND, led_second);
}

void inc_brightness(void)
{
  ram_cfg.led_brightness <<= 1;
  if(!ram_cfg.led_brightness) ram_cfg.led_brightness = 1;
  dump_ram2eem();
}

void keyboard_init(void)
{
  KEYBOARD_DIR &= ~(KEY_INC_HOUR | KEY_INC_MINUTE | KEY_INC_SECOND | KEY_INC_BRIGHTNESS);
  PORTB |= KEY_INC_HOUR | KEY_INC_MINUTE | KEY_INC_SECOND | KEY_INC_BRIGHTNESS;
}

void keyboard_handle_input(void)
{
  SuperDebounce(&k_inc_hour, &KEYBOARD_PIN, KEY_INC_HOUR, 20, 500, &inc_hour, &inc_hour);
  SuperDebounce(&k_inc_minute, &KEYBOARD_PIN, KEY_INC_MINUTE, 20, 500, &inc_minute, &inc_minute);
  SuperDebounce(&k_inc_second, &KEYBOARD_PIN, KEY_INC_SECOND, 20, 500, &inc_second, &inc_second);
  SuperDebounce(&k_inc_brightness, &KEYBOARD_PIN, KEY_INC_BRIGHTNESS, 20, 500, &inc_brightness, &inc_brightness);
}