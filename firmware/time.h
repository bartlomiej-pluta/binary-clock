#ifndef __TIME_H__
#define __TIME_H__

#define TIME_2_INT(TIME) ((TIME).hour*60 + (TIME).minute)

struct DATE_YMDW
{
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t weekday;
};

struct DATE_YMD
{
  uint16_t year;
  uint8_t month;
  uint8_t day;
};

struct TIME_HMS 
{
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
};

struct TIME_HM
{
  uint8_t hour;
  uint8_t minute;
};

#endif