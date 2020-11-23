#ifndef __PTIMER_H__
#define __PTIMER_H__

extern volatile uint16_t tim_debounce;
extern volatile uint8_t tim_buz;

void ptimer_init(void);

#endif