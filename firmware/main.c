#include <avr/interrupt.h>
#include <avr/io.h>
#include "keyboard.h"
#include "ptimer.h"
#include "config.h"
#include "nightm.h"
#include "time.h"
#include "uart.h"
#include "i2c.h"
#include "rtc.h"
#include "led.h"
#include "at.h"

#define I2C_BITRATE 100000UL // 100kHz


int main() 
{
  cfg_init();
  keyboard_init();
  ptimer_init();
  i2c_init(I2C_BITRATE); 
  rtc_int0_init();
  led_init();
  uart_init();
  uart_bind_handler(at_handler);

  sei();

  char uart_buf[20];

  while(1) 
  {
    keyboard_handle_input();
    uart_handle_event(uart_buf);

    if(rtc_handle_timer()) nightm_handle();
  }
}
