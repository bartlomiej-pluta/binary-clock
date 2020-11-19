#ifndef __AT_H__
#define __AT_H__

#include <avr/pgmspace.h>

#define M_SET 0
#define M_GET 1
#define M_NORM 2

struct AT_CMD
{
  char cmd[8];
  int8_t (*handler)(uint8_t mode, char* arg);
};

void at_handler(char* cmd);

int8_t cmd_at_handler(uint8_t mode, char* arg);
int8_t cmd_ati_handler(uint8_t mode, char* arg);
int8_t cmd_at_rst_handler(uint8_t mode, char* arg);
int8_t cmd_at_time_handler(uint8_t mode, char* arg);
int8_t cmd_at_btnes_handler(uint8_t mode, char* arg);
int8_t cmd_at_ngt_handler(uint8_t mode, char* arg);

#define AT_NUM 6
extern const struct AT_CMD at_commands[AT_NUM] PROGMEM;

#endif