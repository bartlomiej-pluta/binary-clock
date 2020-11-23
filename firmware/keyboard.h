#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#define KEYBOARD_PORT B
#define KEY_INC_HOUR 0
#define KEY_INC_MINUTE 1
#define KEY_INC_SECOND 2
#define KEY_INC_BRIGHTNESS 3

void kbd_init(void);
void kbd_handle_event(void);

#endif