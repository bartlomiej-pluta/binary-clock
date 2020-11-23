#ifndef __RTC_H__
#define __RTC_H__

#include "time.h"

#define RTC_I2C_ADDR 0xA2

#define DATE_SEPARATOR '.'

#define INT0_PORT D
#define INT0_IN 2

#define SECOND 0x02
#define MINUTE 0x03
#define HOUR 0x04

struct RTC_DATA
{
  struct TIME_HMS time;
  struct DATE_YMDW date;
  char time_str[9];
  char date_str[11];
  char weekday_str[4];  
  uint8_t buffer[5];
};

void rtc_int0_init(void);
void rtc_bind_handler(void (*handler)(struct RTC_DATA* clock));
void rtc_set_time(struct TIME_HMS* time);
void rtc_set_date(struct DATE_YMD* date);
void rtc_inc_time(uint8_t part);
void rtc_handle_event(void);

#endif