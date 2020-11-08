#include <avr/io.h>
#include <avr/interrupt.h>
#include "i2c.h"
#include "led.h"

#define I2C_BITRATE 100000UL // 100kHz

int main() 
{
  i2c_init(I2C_BITRATE); 
  led_init();

  sei();

  led_hour = 0;
  led_minute = 0;
  led_second = 0;

  while(1) 
  {

  }
}