#define  F_CPU 16000000
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_STATE.h"

#include "UART_config.h"
#include "UART_private.h"
#include "UART_register.h"
#include "UART_interface.h"





void UART_init(u32 ubrr)
{
	// Set frame format: 8 data bits, 1 stop bit
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	// Set baud rate
	UBRR0H = (u8)(ubrr >> 8);
	UBRR0L = (u8)ubrr;
	// Enable transmitter and receiver
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	
}

void UART_u8TransmitData(u8 copy_u8Data)
{
	// Wait for empty transmit buffer
	while (!(UCSR0A & (1 << UDRE0)));
	// Put data into buffer, sends the data
	UDR0 = copy_u8Data;
}

u8 UART_u8RecieveData(void)
{
	// Wait for data to be received
	while (!(UCSR0A & (1 << RXC0)));
	// Get and return received data from the buffer
	return UDR0;
}