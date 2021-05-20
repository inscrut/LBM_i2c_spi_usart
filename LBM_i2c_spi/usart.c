/*
 * usart.c
 *
 * Created: 20.05.2021 20:09:48
 *  Author: HodyrevV
 */ 

#include "usart.h"

void USART_Init(unsigned int _boud){
	/*Set baud rate */
	UBRR0H = (unsigned char)(_boud>>8);
	UBRR0L = (unsigned char)_boud;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void USART_Send(uint8_t _data)
{
	/* Wait for empty transmit buffer */
	while (!(UCSR0A & (1<<UDRE0)));
	/* Put data into buffer, sends the data */
	UDR0 = _data;
}

uint8_t USART_Receive()
{
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)));
	/* Get and return received data from buffer */
	return UDR0;
}

void USART_Flush() //clear buffer, read last byte
{
	unsigned char dummy;
	while (UCSR0A & (1<<RXC0)) dummy = UDR0;
}