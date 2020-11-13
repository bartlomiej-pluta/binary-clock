#include <avr/io.h>
#include "debounce.h"
#include "ptimer.h"

void SuperDebounce(uint8_t * key_state, volatile uint8_t *KPIN,
		uint8_t key_mask, uint16_t rep_time, uint16_t rep_wait,
		void (*push_proc)(void), void (*rep_proc)(void) ) {

	enum {idle, debounce, go_rep, wait_rep, rep};

	if(!rep_time) rep_time=20;
	if(!rep_wait) rep_wait=150;

	uint8_t key_press = !(*KPIN & key_mask);

	if( key_press && !*key_state ) {
		*key_state = debounce;
		timers[TIM_DEBOUNCE] = 15;
	} else
	if( *key_state  ) {

		if( key_press && debounce==*key_state && !timers[TIM_DEBOUNCE] ) {
			*key_state = 2;
			timers[TIM_DEBOUNCE]=5;
		} else
		if( !key_press && *key_state>1 && *key_state<4 ) {
			if(push_proc) push_proc();						/* KEY_UP */
			*key_state=idle;
		} else
		if( key_press && go_rep==*key_state && !timers[TIM_DEBOUNCE] ) {
			*key_state = wait_rep;
			timers[TIM_DEBOUNCE]=rep_wait;
		} else
		if( key_press && wait_rep==*key_state && !timers[TIM_DEBOUNCE] ) {
			*key_state = rep;
		} else
		if( key_press && rep==*key_state && !timers[TIM_DEBOUNCE] ) {
			timers[TIM_DEBOUNCE] = rep_time;
			if(rep_proc) rep_proc();						/* KEY_REP */
		}
	}
	if( *key_state>=3 && !key_press ) *key_state = idle;
}