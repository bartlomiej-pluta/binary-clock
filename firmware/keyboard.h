#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#define KEYBOARD_DIR DDRB
#define KEYBOARD_PIN PINB
#define KEYBOARD_PORT PORTB
#define KEY_INC_HOUR (1<<PB0)
#define KEY_INC_MINUTE (1<<PB1)
#define KEY_INC_SECOND (1<<PB2)

void keyboard_init(void);
void keyboard_handle_input(void);

#endif