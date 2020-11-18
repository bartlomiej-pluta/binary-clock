#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "uart.h"

// Ring buffer macros
#define RBUF(BUF_SIZE) struct { char data[BUF_SIZE]; uint8_t head; uint8_t tail; }
#define RBUF_NEXT(BUF_IDX, MOD_MASK) (((BUF_IDX) + 1) & MOD_MASK)
#define RBUF_FORWARD(BUF_IDX, MOD_MASK) BUF_IDX = RBUF_NEXT(BUF_IDX, MOD_MASK)
#define RBUF_EMPTY(BUFF) (BUFF.head == BUFF.tail)

volatile RBUF(UART_RX_BUF_SIZE) rx_buffer;
volatile RBUF(UART_TX_BUF_SIZE) tx_buffer;

void uart_init(void)
{
	UBRRH = (uint8_t) (__UBRR>>8);
	UBRRL = (uint8_t) __UBRR;

	UCSRB = (1<<RXEN) | (1<<TXEN) | (1<<RXCIE);
	UCSRC = (1<<URSEL) | (3<<UCSZ0);
}

void uart_putc(char data)
{
	uint8_t head = RBUF_NEXT(tx_buffer.head, UART_TX_BUF_MASK);

  while(head == tx_buffer.tail);

  tx_buffer.data[head] = data;
  tx_buffer.head = head;

  UCSRB |= (1<<UDRIE);
}

void uart_puts(char* str)
{
  register char c;
  while ((c = *str++)) uart_putc(c);
}

void uart_puti(int16_t value, int16_t radix)
{
	char number[20];
	itoa(value, number, radix);
	uart_puts(number);
}

char uart_getc(void)
{
  if(RBUF_EMPTY(rx_buffer)) return 0;
  RBUF_FORWARD(rx_buffer.tail, UART_RX_BUF_MASK);
  return rx_buffer.data[rx_buffer.tail];
}

ISR(USART_UDRE_vect)
{    
  if(!RBUF_EMPTY(tx_buffer)) 
	{
    RBUF_FORWARD(tx_buffer.tail, UART_TX_BUF_MASK);
    UDR = tx_buffer.data[tx_buffer.tail];
  } 
	else 
	{
		UCSRB &= ~(1<<UDRIE);
  }
}

ISR(USART_RXC_vect)
{
  RBUF_FORWARD(rx_buffer.head, UART_RX_BUF_MASK);
	rx_buffer.data[rx_buffer.head] = UDR;
}

