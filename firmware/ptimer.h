#ifndef __PTIMER_H__
#define __PTIMER_H__

#define TIMERS_COUNT 1
#define TIM_DEBOUNCE 0

extern volatile uint16_t timers[TIMERS_COUNT];

void ptimer_init(void);

#endif