#include <avr/io.h>
#include "common.h"
#include "buzzer.h"
#include "ptimer.h"
#include "config.h"


void buz_init(void)
{
  R_DDR(BUZZER_PORT) |= 1<<BUZZER;
  R_PORT(BUZZER_PORT) &= ~(1<<BUZZER);
}

void buz_on(void)
{
  if(ram_cfg.buz_en) tim_buz = BUZZER_DURATION;
}

void buz_handle_event(void)
{
  if(tim_buz) R_PORT(BUZZER_PORT) |= 1<<BUZZER;
  else R_PORT(BUZZER_PORT) &= ~(1<<BUZZER);
}