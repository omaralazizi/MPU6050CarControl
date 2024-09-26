/*
 * car_project.c
 *
 * Created: 9/3/2024 12:27:27 PM
 * Author : OMAR ALAZIZI
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define BAUD_RATE 9600
#define UBRR F_CPU/16/BAUD_RATE-1

//LIB
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_STATE.h"
//MCAL
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "UART_interface.h"
//HAL
#include "CarMotors_interface.h"



int main(void)
{
	UART_init(UBRR);
	CarMotors_INIT();
	
	u8 right_speed =0, left_speed=0, DirectionSet=0;

	
    while (1) 
    {
		 DirectionSet = UART_u8RecieveData();
		 right_speed  = UART_u8RecieveData();
		 left_speed   = UART_u8RecieveData();
		 
		 switch(DirectionSet) {
			 case 'A':
			 RightMotorsForward(right_speed);
			 LeftMotorsForward(left_speed);
			 break;
		
			 case 'B':
			 RightMotorsBackward(right_speed);
			 LeftMotorsBackward(left_speed);
			 break;
		
			 case 'C':
			 RightMotorsBackward(right_speed);
			 LeftMotorsForward(left_speed);
			 break;
			 
			 case 'D':
			 RightMotorsForward(right_speed);
			 LeftMotorsBackward(left_speed);
			 break;
			 
			 case 'S':
			 CarMotors_Stop();
			 break;
		
		
			 default:
			 CarMotors_Stop();
		 }	
		 //_delay_ms(100);  // Delay for stability
    }
}
