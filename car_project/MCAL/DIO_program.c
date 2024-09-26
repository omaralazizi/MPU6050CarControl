/************************************************************************************/
/************************************************************************************/
/******************************* Author  : Eman Assem *******************************/
/******************************* Layer   : MCAL       *******************************/
/******************************* SWC     : DIO        *******************************/
/******************************* DATE    : 31/5/2024  *******************************/
/******************************* VERSION : V1.0       *******************************/
/************************************************************************************/
/************************************************************************************/

/*lib*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_STATE.h"

/*MCAL*/
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"


u8 DIO_u8SetPinDirection  (u8 copy_u8portName ,u8 copy_u8pinNumber ,u8 copy_u8pinDirection)
{
	u8 Local_ERR_state=OK;
	
	if( (copy_u8pinNumber >= DIO_PIN0 )  &&  (copy_u8pinNumber <= DIO_PIN7 ) )
	{
		if( copy_u8pinDirection == DIO_PIN_OUTPUT)
		{
			switch (copy_u8portName)
			{
				case DIO_PORTB :  SET_BIT(DDRB,copy_u8pinNumber);  break;
				case DIO_PORTC :  SET_BIT(DDRC,copy_u8pinNumber);  break;
				case DIO_PORTD :  SET_BIT(DDRD,copy_u8pinNumber);  break;
				default   :  Local_ERR_state=NOK;             break;
			}
		}
		else if(copy_u8pinDirection == DIO_PIN_INPUT)
		{
			switch (copy_u8portName)
			{
				case DIO_PORTB :  CLR_BIT(DDRB,copy_u8pinNumber);  break;
				case DIO_PORTC :  CLR_BIT(DDRC,copy_u8pinNumber);  break;
				case DIO_PORTD :  CLR_BIT(DDRD,copy_u8pinNumber);  break;
				default   :  Local_ERR_state=NOK;             break;
			}
		}
		else Local_ERR_state =NOK;
	}
	else Local_ERR_state =NOK;
	
	return Local_ERR_state;
}

u8 DIO_u8SetPinValue  (u8 copy_u8portName ,u8 copy_u8pinNumber ,u8 copy_u8pinValue)
{
	u8 Local_ERR_state=OK;
	
	if( (copy_u8pinNumber >= DIO_PIN0 )  &&  (copy_u8pinNumber <= DIO_PIN7 ) )
	{
		if( copy_u8pinValue == DIO_PIN_HIGH)
		{
			switch (copy_u8portName)
			{
				case DIO_PORTB :  SET_BIT(PORTB,copy_u8pinNumber);  break;
				case DIO_PORTC :  SET_BIT(PORTC,copy_u8pinNumber);  break;
				case DIO_PORTD :  SET_BIT(PORTD,copy_u8pinNumber);  break;
				default   :  Local_ERR_state=NOK;             break;
			}
		}
		else if(copy_u8pinValue == DIO_PIN_LOW)
		{
			switch (copy_u8portName)
			{
				case DIO_PORTB :  CLR_BIT(PORTB,copy_u8pinNumber);  break;
				case DIO_PORTC :  CLR_BIT(PORTC,copy_u8pinNumber);  break;
				case DIO_PORTD :  CLR_BIT(PORTD,copy_u8pinNumber);  break;
				default   :  Local_ERR_state=NOK;             break;
			}
		}
		else Local_ERR_state =NOK;
	}
	else Local_ERR_state =NOK;
	
	return Local_ERR_state;
	
}

u8 DIO_u8GetPinValue      (u8 copy_u8portName ,u8 copy_u8pinNumber ,u8 *copy_pu8_ReturnedValue)
{
	
	u8 Local_ERR_state=OK;
	
	if( (copy_u8pinNumber >= DIO_PIN0 )  &&  (copy_u8pinNumber <= DIO_PIN7 ) )
	{
		switch (copy_u8portName)
		{
			case DIO_PORTB : *copy_pu8_ReturnedValue=GET_BIT(PINB,copy_u8pinNumber);  break;
			case DIO_PORTC : *copy_pu8_ReturnedValue=GET_BIT(PINC,copy_u8pinNumber);  break;
			case DIO_PORTD : *copy_pu8_ReturnedValue=GET_BIT(PIND,copy_u8pinNumber);  break;
			default   :  Local_ERR_state=NOK;             break;
		}
	}
	else
	Local_ERR_state =NOK;
	
	return Local_ERR_state;
	
}

u8 DIO_u8SetPortDirection (u8 copy_u8portName ,u8 copy_u8portDirection)
{
	
	
	u8 Local_ERR_state=OK;
	
	switch (copy_u8portName)
	{
		case DIO_PORTB :  DDRB=copy_u8portDirection;  break;
		case DIO_PORTC :  DDRC=copy_u8portDirection;  break;
		case DIO_PORTD :  DDRD=copy_u8portDirection;  break;
		default   :  Local_ERR_state=NOK;             break;
	}
	
	
	return Local_ERR_state;
}


u8 DIO_u8SetPortValue     (u8 copy_u8portName ,u8 copy_u8portValue)
{
	
	
	u8 Local_ERR_state=OK;
	
	switch (copy_u8portName)
	{
		case DIO_PORTB :  PORTB=copy_u8portValue;  break;
		case DIO_PORTC :  PORTC=copy_u8portValue;  break;
		case DIO_PORTD :  PORTD=copy_u8portValue;  break;
		default   :  Local_ERR_state=NOK;             break;
	}
	
	return Local_ERR_state;
	
}
u8 DIO_u8GetPortValue     (u8 copy_u8portName ,u8 *copy_pu8_ReturnedValue)
{
	
	u8 Local_ERR_state=OK;
	
	switch (copy_u8portName)
	{
		case DIO_PORTB :  *copy_pu8_ReturnedValue = PINB;  break;
		case DIO_PORTC :  *copy_pu8_ReturnedValue = PINC;  break;
		case DIO_PORTD :  *copy_pu8_ReturnedValue = PIND;  break;
		default   :  Local_ERR_state=NOK;             break;
	}
	
	return Local_ERR_state;
}
