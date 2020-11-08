#include <avr/io.h>
#include <avr/interrupt.h>
#include "ptimer.h"
#include "i2c.h"
#include "rtc.h"
#include "led.h"

#define I2C_BITRATE 100000UL // 100kHz
#define RTC_I2C_ADDR 0xA2


int main() 
{
  ptimer_init();
  i2c_init(I2C_BITRATE); 
  rtc_int0_init();
  led_init();

  sei();

  led_hour = 0;
  led_minute = 0;
  led_second = 0;

  while(1) 
  {

  }
}

ISR(INT0_vect)
{
  struct time curr_time = rtc_read_time(RTC_I2C_ADDR);
  led_hour = curr_time.hour;
  led_minute = curr_time.minute;
  led_second = curr_time.second;
}