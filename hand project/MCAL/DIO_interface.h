/************************************************************************************/
/************************************************************************************/
/******************************* Author  : Omar Alazizi *****************************/
/******************************* Layer   : MCAL         *****************************/
/******************************* SWC     : DIO          *****************************/
/******************************* DATE    : 7/6/2024     *****************************/
/******************************* VERSION : V1.0         *****************************/
/************************************************************************************/
/************************************************************************************/

//#include "STD_TYPES.h"

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#define DIO_PORTB 0
#define DIO_PORTC 1
#define DIO_PORTD 2
		   
#define DIO_PIN0 0 
#define DIO_PIN1 1 
#define DIO_PIN2 2 
#define DIO_PIN3 3 
#define DIO_PIN4 4 
#define DIO_PIN5 5 
#define DIO_PIN6 6 
#define DIO_PIN7 7

#define DIO_PORT_OUTPUT 0XFF
#define DIO_PORT_INPUT  0
		  
#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT  0

#define DIO_PIN_HIGH   1
#define DIO_PIN_LOW    0

#define DIO_PORT_HIGH 0XFF
#define DIO_PORT_LOW  0

/*return for debugging */
u8 DIO_u8SetPinDirection     (u8 copy_u8portName ,u8 copy_u8pinNumber ,u8 copy_u8pinDirection);
u8 DIO_u8SetPinValue         (u8 copy_u8portName ,u8 copy_u8pinNumber ,u8 copy_u8pinValue);
u8 DIO_u8GetPinValue         (u8 copy_u8portName ,u8 copy_u8pinNumber ,u8 *copy_pu8_ReturnedValue);

u8 DIO_u8SetPortDirection    (u8 copy_u8portName ,u8 copy_u8portDirection);
u8 DIO_u8GetPortValue        (u8 copy_u8portName ,u8 *copy_pu8_ReturnedValue);
u8 DIO_u8SetPortValue        (u8 copy_u8portName ,u8 copy_u8portValue);

#endif

