#include <avr/io.h>
#include "i2c.h"

void i2c_init(uint32_t bitrate) 
{
    uint8_t prescaler_options[] = {1, 4, 16, 64};
    uint8_t prescaler_value = prescaler_options[TWSR & 0x03]; // 0x03 (hex) = 0b00000011 (bin)
    TWBR = (uint8_t)((F_CPU / bitrate - 16) / (2 * prescaler_value));
}

void i2c_start(void) 
{
  TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
  while(!(TWCR & (1<<TWINT)));  
}

void i2c_stop(void)
{
  TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
  while(TWCR & (1<<TWSTO));  
}

uint8_t i2c_read(uint8_t ack) 
{
  TWCR = (1<<TWINT) | (ack<<TWEA) | (1<<TWEN);
  while(!(TWCR & (1<<TWINT)));
  return TWDR;
}

void i2c_write(uint8_t byte) 
{
  TWDR = byte;
  TWCR = (1<<TWINT) | (1<<TWEN);
  while(!(TWCR & (1<<TWINT)));
}

void i2c_readbuf(uint8_t sla, uint8_t adr, uint8_t len, uint8_t* buf) 
{
  i2c_start();
  i2c_write(sla);
  i2c_write(adr);
  i2c_start();
  i2c_write(sla + I2C_READ);
  while(len--) *buf++ = i2c_read(len ? I2C_ACK : I2C_NACK);
  i2c_stop();
}

void i2c_writebuf(uint8_t sla, uint8_t adr, uint8_t len, uint8_t* buf) 
{
  i2c_start();
  i2c_write(sla);
  i2c_write(adr);

  while (len--) 
  {
    i2c_write(*buf++);
  }

  i2c_stop();
}