#ifndef __BUZZER_H__
#define __BUZZER_H__

#define BUZZER_PORT C
#define BUZZER 7

#define BUZZER_DURATION 10

void buz_init(void);
void buz_on(void);
void buz_handle_event(void);


#endif