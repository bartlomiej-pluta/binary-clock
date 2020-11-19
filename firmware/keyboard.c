#include <avr/io.h>
#include "config.h"
#include "keyboard.h"
#include "debounce.h"
#include "rtc.h"
#include "led.h"

uint8_t k_inc_hour, k_inc_minute, k_inc_second, k_inc_brightness;

void inc_hour(void)
{
  rtc_set_time_part(HOUR, (time.hour + 1) % 24);
}

void inc_minute(void)
{
  rtc_set_time_part(MINUTE, (time.minute + 1) % 60);
}

void inc_second(void)
{
  rtc_set_time_part(SECOND, (time.second + 1) % 60);
}

void inc_brightness(void)
{
  led_inc_btnes();
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