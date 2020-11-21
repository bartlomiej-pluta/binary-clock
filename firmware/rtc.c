#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/io.h>
#include "rtc.h"
#include "i2c.h"

#define DEC_2_BCD(dec) ((((dec) / 10) << 4) | ((dec) % 10))
#define BCD_2_DEC(bcd) (((((bcd) >> 4) & 0x0F) * 10) + ((bcd) & 0x0F))

static const uint16_t days_of_month[] PROGMEM = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
static const char weekday_strings[] PROGMEM = { "mon" "\x00" "tue" "\x00" "wed" "\x00" "thu" "\x00" "fri" "\x00" "sat" "\x00" "sun" };

static volatile struct RTC_DATA clock;
static void (*rtc_handler)(struct RTC_DATA* clock);

void rtc_read_datetime(struct RTC_DATA* data);
uint8_t eval_weekday(struct DATE_YMD* date);

void rtc_int0_init(void)
{
  MCUCR |= (1<<ISC01);
  INT0_DIR &= ~(1<<INT0_PIN);
  INT0_PORT |= (1<<INT0_PIN);  
}

void rtc_bind_handler(void (*handler)(struct RTC_DATA* clock))
{
  rtc_handler = handler;
}

void rtc_set_time(struct TIME_HMS* time)
{  
  clock.buffer[0] = DEC_2_BCD(time->second);
  clock.buffer[1] = DEC_2_BCD(time->minute);
  clock.buffer[2] = DEC_2_BCD(time->hour);
  i2c_writebuf(RTC_I2C_ADDR, 0x02, 3, &clock.buffer);
}

void rtc_set_date(struct DATE_YMD* date)
{
  clock.buffer[3] = ((date->year & 0x03) << 6) | DEC_2_BCD(date->day);
  clock.buffer[4] = (eval_weekday(date) << 5) | DEC_2_BCD(date->month);  
  i2c_writebuf(RTC_I2C_ADDR, 0x05, 2, &clock.buffer[3]);
  i2c_writebuf(RTC_I2C_ADDR, 0x10, 2, (uint8_t*) &date->year);
}

void rtc_inc_time(uint8_t part)
{   
  switch(part)
  {
    case SECOND:
      clock.buffer[0] = clock.time.second + 1;
      if(clock.buffer[0] >= 60) clock.buffer[0] = 0;
    break;
    case MINUTE:
      clock.buffer[0] = clock.time.minute + 1;
      if(clock.buffer[0] >= 60) clock.buffer[0] = 0;
    break;
    case HOUR:
      clock.buffer[0] = clock.time.hour + 1;
      if(clock.buffer[0] >= 24) clock.buffer[0] = 0;
    break;    
  }

  clock.buffer[0] = DEC_2_BCD(clock.buffer[0]);

  i2c_writebuf(RTC_I2C_ADDR, part, 1, &clock.buffer);
  rtc_invoke_handler();
}

void rtc_invoke_handler(void)
{
  if(rtc_handler)
  {
    rtc_read_datetime(&clock);
    rtc_handler(&clock);
  }   
}

void rtc_handle_event(void)
{
  if(GIFR & (1<<INTF0))
  {
    rtc_invoke_handler();
    GIFR |= 1<<INTF0;
  }
}

void rtc_read_datetime(struct RTC_DATA* data)
{
  i2c_readbuf(RTC_I2C_ADDR, 0x02, 5, data->buffer);
  i2c_readbuf(RTC_I2C_ADDR, 0x10, 2, (uint8_t*) &(data->date.year));
  
  char* curr_char = data->time_str;
  for(uint8_t i=0; i<3; ++i)
  {        
    // data->time_str
    *(curr_char++) = ((data->buffer[2-i] & (!i ? 0x3F : 0x7F)) >> 4) + '0'; // Tens
    *(curr_char++) = (data->buffer[2-i] & 0x0F) + '0'; // Ones    
    *(curr_char++) = i==2 ? 0 : ':'; // Separator

    // data->time structure
    *((uint8_t*)(&data->time)+i) = BCD_2_DEC(data->buffer[2-i]);
  }

  // data->date structure
  data->date.day = BCD_2_DEC(data->buffer[3] & 0x3F);
  
  // data->date.year
  uint8_t year = data->buffer[3] >> 6;
  if((data->date.year & 0x03) != year)
  {
    while((data->date.year & 0x03) != year) ++(data->date.year);
    i2c_writebuf(RTC_I2C_ADDR, 0x10, 2, (uint8_t*) &(data->date.year));
  }
  
  data->date.month = BCD_2_DEC(data->buffer[4] & 0x1F);
  data->date.weekday = data->buffer[4] >> 5;  

  // data->date_str
  curr_char = data->date_str;    
  *(curr_char++) = ((data->buffer[3] & 0x3F) >> 4) + '0';
  *(curr_char++) = (data->buffer[3] & 0x0F) + '0';
  *(curr_char++) = DATE_SEPARATOR;
  *(curr_char++) = ((data->buffer[4] & 0x1F) >> 4) + '0';
  *(curr_char++) = (data->buffer[4] & 0x0F) + '0';
  *(curr_char++) = DATE_SEPARATOR;
  itoa(data->date.year, curr_char, 10);
  *(curr_char+4) = 0;  

  // data->weekday_str
  strcpy_P(&data->weekday_str, weekday_strings + data->date.weekday * 4);
}

uint8_t eval_weekday(struct DATE_YMD* date)
{
  uint16_t yy = (date->year-1) % 100;
  uint16_t c = (date->year-1) - yy;
  uint16_t g = yy + yy/4;
  
  uint16_t jan1 = c / 10;
  jan1 %= 4;
  jan1 *= 5;
  jan1 += g;
  jan1 %= 7;

  uint16_t day_of_year = pgm_read_word(&days_of_month[date->month-1]) + date->day;
  if(!(date->year & 0x03) && date->month > 3) ++day_of_year;

  return (jan1 + day_of_year - 1) % 7;
}