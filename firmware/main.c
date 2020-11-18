#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "keyboard.h"
#include "ptimer.h"
#include "time.h"
#include "i2c.h"
#include "rtc.h"
#include "led.h"

#define I2C_BITRATE 100000UL // 100kHz

int main() 
{
  cfg_init();
  keyboard_init();
  ptimer_init();
  i2c_init(I2C_BITRATE); 
  rtc_int0_init();
  led_init();

  sei();

  while(1) 
  {
    keyboard_handle_input();
  }
}

ISR(INT0_vect)
{
  led_display = rtc_read_time();
}