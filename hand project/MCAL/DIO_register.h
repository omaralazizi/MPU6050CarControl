
//#include "STD_TYPES.h"

#ifndef _DIO_REGISTER_H_
#define _DIO_REGISTER_H_

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



