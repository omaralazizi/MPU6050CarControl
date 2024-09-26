
#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define TXEN0  3
#define RXEN0  4
#define UCSZ00 1
#define UCSZ01 2
#define UDRE0  5
#define RXC0   7

#define UDR0      ( * ( volatile u8 * ) 0xC6 )
#define UBRR0H    ( * ( volatile u8 * ) 0xC5 )
#define UBRR0L    ( * ( volatile u8 * ) 0xC4 )
#define UCSR0C    ( * ( volatile u8 * ) 0xC2 )
#define UCSR0B    ( * ( volatile u8 * ) 0xC1 )
#define UCSR0A    ( * ( volatile u8 * ) 0xC0 )


#define PORTA     ( * ( volatile u8 * ) 0x2E )
#define DDRA      ( * ( volatile u8 * ) 0x2D )
#define PINA      ( * ( volatile u8 * ) 0x2C )

#define PORTD     ( * ( volatile u8 * ) 0x2B )
#define DDRD      ( * ( volatile u8 * ) 0x2A )
#define PIND      ( * ( volatile u8 * ) 0x29 )

#define PORTC     ( * ( volatile u8 * ) 0x28 )
#define DDRC      ( * ( volatile u8 * ) 0x27 )
#define PINC      ( * ( volatile u8 * ) 0x26 )

#define PORTB     ( * ( volatile u8 * ) 0x25 )
#define DDRB      ( * ( volatile u8 * ) 0x24 )
#define PINB      ( * ( volatile u8 * ) 0x23 )


#endif