#include <avr/io.h>
#include "config.h"
#include "keyboard.h"
#include "debounce.h"
#include "rtc.h"
#include "led.h"

uint8_t k_inc_hour, k_inc_minute, k_inc_second, k_inc_brightness;

void inc_hour(void)
{
  led_display.hour = (led_display.hour + 1) % 24;
  rtc_set_time_part(HOUR, led_display.hour);
}

void inc_minute(void)
{
  led_display.minute = (led_display.minute + 1) % 60;
  rtc_set_time_part(MINUTE, led_display.minute);
}

void inc_second(void)
{
  led_display.second = (led_display.second + 1) % 60;
  rtc_set_time_part(SECOND, led_display.second);
}

void inc_brightness(void)
{
  led_inc_btness();
}

void keyboard_init(void)
{
  KEYBOARD_DIR &= ~(KEY_INC_HOUR | KEY_INC_MINUTE | KEY_INC_SECOND | KEY_INC_BRIGHTNESS);
  PORTB |= KEY_INC_HOUR | KEY_INC_MINUTE | KEY_INC_SECOND | KEY_INC_BRIGHTNESS;
}

void keyboard_handle_input(void)
{
  SuperDebounce(&k_inc_hour, &KEYBOARD_PIN, KEY_INC_HOUR, 20, 0, &inc_hour, 0);
  SuperDebounce(&k_inc_minute, &KEYBOARD_PIN, KEY_INC_MINUTE, 20, 0, &inc_minute, 0);
  SuperDebounce(&k_inc_second, &KEYBOARD_PIN, KEY_INC_SECOND, 20, 0, &inc_second, 0);
  SuperDebounce(&k_inc_brightness, &KEYBOARD_PIN, KEY_INC_BRIGHTNESS, 20, 0, &inc_brightness, 0);
}