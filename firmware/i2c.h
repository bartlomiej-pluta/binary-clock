#ifndef __I2C_H__
#define __I2C_H__

#define I2C_ACK 1
#define I2C_NACK 0
#define I2C_READ 1

void i2c_init(uint32_t bitrate);
void i2c_start(void);
void i2c_stop(void);
uint8_t i2c_read(uint8_t ack);
void i2c_write(uint8_t byte);
void i2c_readbuf(uint8_t sla, uint8_t adr, uint8_t len, uint8_t* buf);
void i2c_writebuf(uint8_t sla, uint8_t adr, uint8_t len, uint8_t* buf);

#endif