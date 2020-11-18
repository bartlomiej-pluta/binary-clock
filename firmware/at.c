#include <stdlib.h>
#include <string.h>
#include <avr/version.h>
#include <avr/wdt.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "at.h"
#include "uart.h"
#include "config.h"
#include "time.h"
#include "led.h"
#include "rtc.h"

#define UNUSED(X) (void)(X)

const struct AT_CMD at_commands[AT_NUM] PROGMEM = {
  { "AT", cmd_at_handler },
  { "ATI", cmd_ati_handler },
  { "AT+RST", cmd_at_rst_handler },
  { "AT+TIME", cmd_at_time_handler },
  { "AT+BTNES", cmd_at_btnes_handler }
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

  if(!ok) uart_puts("ERROR\n\r");
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

  uart_puts("OK\r\n");

  return 0;
}

int8_t cmd_ati_handler(uint8_t mode, char* arg)
{
  UNUSED(arg);

  if(mode != M_NORM) return -1;

  uart_puts("Binary Clock v1.0 :: Bartlomiej Pluta 2020\r\n");
  uart_puts("compilation ");
  uart_puts(__DATE__);
  uart_putc(' ');
  uart_puts(__TIME__);
  uart_puts("\n\r");
  uart_puts("avr-libc v");
  uart_puts(__AVR_LIBC_VERSION_STRING__);
  uart_putc(' ');
  uart_puts(__AVR_LIBC_DATE_STRING__);
  uart_puts("\n\r");

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
  struct TIME time;
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

      uart_puts("+TIME=");
      uart_puti(time.hour, 10);
      uart_puts(",");
      uart_puti(time.minute, 10);
      uart_puts(",");
      uart_puti(time.second, 10);
      uart_puts("\n\r");
      break;

    case M_NORM:
      uart_puts("AT+TIME=(0-23),(0-59),(0-59)\r\n");
  }

  return 0;
}

int8_t cmd_at_btnes_handler(uint8_t mode, char* arg)
{
  uint8_t btness;

  switch(mode)
  {
    case M_GET:    
      for(btness=0; btness<8; ++btness) if(ram_cfg.led_brightness & (1<<btness)) break;
      uart_puti(btness, 10);
      uart_puts("\n\r");

      break;
    
    case M_SET:
      if(!strlen(arg)) return -1;

      btness = atoi(arg);
      if(btness >= 8) return -1;
      led_set_btness(btness);

      uart_puts("+BTNES=");
      uart_puts(arg);
      uart_puts("\n\r");

      break;

    case M_NORM:
      uart_puts("AT+BTNES=(0-7)\n\r");
  }

  return 0;
}
