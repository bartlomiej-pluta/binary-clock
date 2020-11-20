#ifndef __AT_H__
#define __AT_H__

#include <avr/pgmspace.h>
#include "rtc.h"

#define M_SET 0
#define M_GET 1
#define M_NORM 2

struct AT_CMD
{
  char cmd[7];
  int8_t (*handler)(uint8_t mode, char* arg);
};

void at_handler(char* cmd);
void at_update_rtc_data(struct RTC_DATA* rtc);

#endif