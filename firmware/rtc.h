#ifndef __RTC_H__
#define __RTC_H__

#include "time.h"

#define RTC_I2C_ADDR 0xA2

#define SECOND 0x02
#define MINUTE 0x03
#define HOUR 0x04

#define INT0_PORT PORTD
#define INT0_DIR DDRD
#define INT0_PIN PD2
#define INT1_PORT PORTD
#define INT1_DIR DDRD
#define INT1_PIN PD3

#define DEC_2_BCD(dec) ((((dec) / 10) << 4) | ((dec) % 10))
#define BCD_2_DEC(bcd) (((((bcd) >> 4) & 0x0F) * 10) + ((bcd) & 0x0F))

void rtc_int0_init(void);
void rtc_int1_init(void);
void rtc_set_time(struct TIME* time);
void rtc_set_time_part(uint8_t part, uint8_t value);
struct TIME rtc_read_time(void);

#endif