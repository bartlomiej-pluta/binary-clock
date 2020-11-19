#include <stdlib.h>
#include <string.h>
#include <avr/version.h>
#include <avr/wdt.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "at.h"
#include "uart.h"
#include "config.h"
#include "nightm.h"
#include "time.h"
#include "led.h"
#include "rtc.h"

#define UNUSED(X) (void)(X)

const struct AT_CMD at_commands[AT_NUM] PROGMEM = {
  { "AT", cmd_at_handler },
  { "ATI", cmd_ati_handler },
  { "AT+RST", cmd_at_rst_handler },
  { "AT+TIM", cmd_at_time_handler },
  { "AT+BTS", cmd_at_btnes_handler },
  { "AT+NGT", cmd_at_ngt_handler }
};

void parse_at(char* at_cmd, char* arg, uint8_t mode)
{  
  uint8_t ok = 0;
  int8_t (*at_handler)(uint8_t mode, char* arg);
  uint8_t at_len = strlen(at_cmd);

  if(at_len)
  {
    for(uint8_t i=0; i<AT_NUM; ++i)
    {
      if(strncasecmp_P(at_cmd, at_commands[i].cmd, at_len) == 0)
      {
        at_handler = (void*) pgm_read_word(&at_commands[i].handler);
        if(at_handler)
        {          
          if(at_handler(mode, arg) >= 0) ok = 1; 
        }        
        break;
      }
    }
  }

  if(!ok) uart_puts_P(PSTR("ERROR\n\r"));
}

void at_handler(char* cmd)
{    
  if(strpbrk(cmd, "?"))
  {
    char* arg;
    char* at = strtok_r(cmd, "?", &arg);
    parse_at(at, arg, M_GET);
  }

  else if(strpbrk(cmd, "="))
  {
    char* arg;
    char* at = strtok_r(cmd, "=", &arg);
    parse_at(at, arg, M_SET);
  }

  else
  {
    parse_at(cmd, NULL, M_NORM);
  }
}

int8_t cmd_at_handler(uint8_t mode, char* arg)
{
  UNUSED(arg);

  if(mode != M_NORM) return -1;

  uart_puts_P(PSTR("OK\r\n"));

  return 0;
}

int8_t cmd_ati_handler(uint8_t mode, char* arg)
{
  UNUSED(arg);

  if(mode != M_NORM) return -1;

  uart_puts_P(PSTR("Binary Clock v1.0 :: Bartlomiej Pluta 2020\r\n"));
  uart_puts_P(PSTR("compilation " __DATE__ " " __TIME__ "\n\r"));
  uart_puts_P(PSTR("avr-libc v" __AVR_LIBC_VERSION_STRING__ " " __AVR_LIBC_DATE_STRING__ "\n\r"));

  return 0;
}

int8_t cmd_at_rst_handler(uint8_t mode, char* arg)
{
  UNUSED(arg);

  if(mode != M_NORM) return -1;

  cli();
  wdt_enable(0);
  while(1);

  return 0;
}

int8_t cmd_at_time_handler(uint8_t mode, char* arg)
{
  struct TIME_HMS time;
  char* val;
  char* tail;

  switch(mode)
  {
    case M_GET:
      time = rtc_read_time();
      uart_puti(time.hour, 10);
      uart_putc(':');
      uart_puti(time.minute, 10);
      uart_putc(':');
      uart_puti(time.second, 10);
      uart_puts("\n\r");
      break;
    
    case M_SET:
      if(!strlen(arg)) return -1;

      val = strtok_r(arg, ",", &tail);
      time.hour = atoi(val);
      if(time.hour >= 24) return -1;

      val = strtok_r(NULL, ",", &tail);
      time.minute = atoi(val);
      if(time.minute >= 60) return -1;

      val = strtok_r(NULL, ",", &tail);
      time.second = atoi(val);
      if(time.second >= 60) return -1;

      rtc_set_time(&time);

      uart_puts_P(PSTR("+TIM="));
      uart_puti(time.hour, 10);
      uart_puts(",");
      uart_puti(time.minute, 10);
      uart_puts(",");
      uart_puti(time.second, 10);
      uart_puts("\n\r");
      break;

    case M_NORM:
      uart_puts_P(PSTR("AT+TIM=(0-23),(0-59),(0-59)\r\n"));
  }

  return 0;
}

int8_t cmd_at_btnes_handler(uint8_t mode, char* arg)
{
  uint8_t btnes;

  switch(mode)
  {
    case M_GET:    
      uart_puti(ram_cfg.led_btnes, 10);
      uart_puts("\n\r");

      break;
    
    case M_SET:
      if(!strlen(arg)) return -1;

      btnes = atoi(arg);
      if(btnes >= 8) return -1;
      led_set_btnes(btnes);

      uart_puts_P(PSTR("+BTS="));
      uart_puts(arg);
      uart_puts("\n\r");

      break;

    case M_NORM:
      uart_puts_P(PSTR("AT+BTS=(0-7)\n\r"));
  }

  return 0;
}

int8_t cmd_at_ngt_handler(uint8_t mode, char* arg)
{
  struct NIGHTM_CFG nightm_cfg;
  char* val;
  char* tail;

  switch(mode)
  {
    case M_GET:
      uart_puti(ram_cfg.night_mode.led_btnes, 10);
      uart_puts_P(ram_cfg.night_mode.led_btnes >= 0 ? PSTR(" (EN)\n\r") : PSTR(" (DIS)\n\r"));
      uart_puti(ram_cfg.night_mode.begin.hour, 10);
      uart_puts(":");
      uart_puti(ram_cfg.night_mode.begin.minute, 10);
      uart_puts("\n\r");
      uart_puti(ram_cfg.night_mode.end.hour, 10);
      uart_puts(":");
      uart_puti(ram_cfg.night_mode.end.minute, 10);
      uart_puts("\n\r");
      break;
    
    case M_SET:
      if(!strlen(arg)) return -1;

      val = strtok_r(arg, ",", &tail);
      nightm_cfg.led_btnes = atoi(val);
      if(nightm_cfg.led_btnes < -1 && 7 < nightm_cfg.led_btnes) return -1;

      val = strtok_r(NULL, ",", &tail);
      nightm_cfg.begin.hour = atoi(val);
      if(nightm_cfg.begin.hour > 23) return -1;

      val = strtok_r(NULL, ",", &tail);
      nightm_cfg.begin.minute = atoi(val);
      if(nightm_cfg.begin.minute > 59) return -1;

      val = strtok_r(NULL, ",", &tail);
      nightm_cfg.end.hour = atoi(val);
      if(nightm_cfg.end.hour > 23) return -1;

      val = strtok_r(NULL, ",", &tail);
      nightm_cfg.end.minute = atoi(val);
      if(nightm_cfg.end.minute > 59) return -1;

      nightm_config(&nightm_cfg);

      uart_puts_P(PSTR("+NGT="));
      uart_puti(nightm_cfg.led_btnes, 10);
      uart_puts(",");
      uart_puti(nightm_cfg.begin.hour, 10);
      uart_puts(",");
      uart_puti(nightm_cfg.begin.minute, 10);
      uart_puts(",");
      uart_puti(nightm_cfg.end.hour, 10);
      uart_puts(",");
      uart_puti(nightm_cfg.end.minute, 10);
      uart_puts("\n\r");
      break;

    case M_NORM:
      uart_puts_P(PSTR("AT+NGT=(-1|0-7),(0-23),(0-59),(0-23),(0-59)\n\r"));
  }

  return 0;
}