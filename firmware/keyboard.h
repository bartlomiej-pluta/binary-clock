#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#define KEYBOARD_DIR DDRB
#define KEYBOARD_PIN PINB
#define KEYBOARD_PORT PORTB
#define KEY_INC_HOUR (1<<PB0)
#define KEY_INC_MINUTE (1<<PB1)
#define KEY_INC_SECOND (1<<PB2)
#define KEY_INC_BRIGHTNESS (1<<PB3)

void kbd_init(void);
void kbd_handle_event(void);

#endif