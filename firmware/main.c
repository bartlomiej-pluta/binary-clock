#include <avr/interrupt.h>
#include <avr/io.h>
#include "keyboard.h"
#include "ptimer.h"
#include "config.h"
#include "nightm.h"
#include "buzzer.h"
#include "time.h"
#include "uart.h"
#include "i2c.h"
#include "rtc.h"
#include "led.h"
#include "at.h"

#define I2C_BITRATE 100000UL // 100kHz

void update_time(struct RTC_DATA* rtc);

int main() 
{
  cfg_init();
  kbd_init();
  ptimer_init();
  i2c_init(I2C_BITRATE); 
  rtc_int0_init();
  led_init();
  uart_init();
  buz_init();
  
  uart_bind_handler(at_handler);
  rtc_bind_handler(update_time);

  led_set_btnes(ram_cfg.led_btnes);

  char uart_buf[20];

  sei();  
  
  while(1) 
  {
    kbd_handle_event();
    uart_handle_event(uart_buf);
    rtc_handle_event();    
    buz_handle_event();
  }
}

void update_time(struct RTC_DATA* rtc)
{
  led_display((struct LED_DIGS*) &rtc->time);
  at_update_rtc_data(rtc);
  nightm_handle(rtc);
}