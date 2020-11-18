#ifndef __UART_H__
#define __UART_H__


#define UART_BAUD 9600
#define __UBRR ((F_CPU + 8UL*UART_BAUD) / (16UL*UART_BAUD) - 1)

#define UART_RX_BUF_SIZE 32
#define UART_RX_BUF_MASK (UART_RX_BUF_SIZE-1)

#define UART_TX_BUF_SIZE 16
#define UART_TX_BUF_MASK (UART_TX_BUF_SIZE-1)

void uart_init(void);
char uart_getc(void);
void uart_gets(char* buf);
void uart_putc(char data);
void uart_puts(char *str);
void uart_puti(int16_t value, int16_t radix);
void uart_bind_handler(void (*handler)(char* line));
void uart_handle_event(char* buf);

#endif
