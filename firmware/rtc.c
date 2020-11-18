#include <avr/io.h>
#include "rtc.h"
#include "i2c.h"

void rtc_int0_init(void)
{
  INT0_DIR &= ~(1<<INT0_PIN);
  INT0_PORT |= (1<<INT0_PIN);
  GICR |= (1<<INT0);
}

void rtc_int1_init(void)
{
  INT1_DIR &= ~(1<<INT1_PIN);
  INT1_PORT |= (1<<INT1_PIN);
  GICR |= (1<<INT1);
}

void rtc_set_time_part(uint8_t part, uint8_t value) 
{  
  uint8_t bcd = DEC_2_BCD(value);
  i2c_writebuf(RTC_I2C_ADDR, part, 1, &bcd);
}

void rtc_set_time(struct TIME* time)
{  
  uint8_t buf[] = { DEC_2_BCD(time->second), DEC_2_BCD(time->minute), DEC_2_BCD(time->hour) };
  i2c_writebuf(RTC_I2C_ADDR, SECOND, 3, buf); // SECOND is the first memory cell (0x02)
}

struct TIME rtc_read_time(void) 
{
  uint8_t buffer[3];
  i2c_readbuf(RTC_I2C_ADDR, 0x02, 3, buffer);

  struct TIME curr_time = {
    BCD_2_DEC(buffer[2]),
    BCD_2_DEC(buffer[1]),
    BCD_2_DEC(buffer[0])
  };

  return curr_time;
}