#define  F_CPU 16000000
#include <util/delay.h>
//LIB
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_State.h"
//MCAL
#include "DIO_interface.h"
#include "TIMER0_interface.h"
//HAL
#include   "CarMotors_config.h"
#include   "CarMotors_interface.h"
#include   "CarMotors_private.h"


void CarMotors_INIT(void)
{
	DIO_u8SetPinDirection(ENA_PORT,ENA_PIN,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(ENB_PORT,ENB_PIN,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(IN1_PORT,IN1_PIN,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(IN2_PORT,IN2_PIN,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(IN3_PORT,IN3_PIN,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(IN4_PORT,IN4_PIN,DIO_PIN_OUTPUT);
	T0pwm_init();
}

void RightMotorsForward(u8 Copy_u8speed)
{
	if(Copy_u8speed < 50)
	{
		Copy_u8speed=0;
	}
	DIO_u8SetPinValue(IN1_PORT,IN1_PIN,DIO_PIN_LOW);//
	DIO_u8SetPinValue(IN2_PORT,IN2_PIN,DIO_PIN_HIGH);// reversed due to wrong connection
	T0pwm_SetBDutyCycle(Copy_u8speed);  //right
}

void LeftMotorsForward(u8 Copy_u8speed)
{
	if(Copy_u8speed < 50)
	{
		Copy_u8speed=0;
	}
	DIO_u8SetPinValue(IN3_PORT,IN3_PIN,DIO_PIN_HIGH);
	DIO_u8SetPinValue(IN4_PORT,IN4_PIN,DIO_PIN_LOW);
	T0pwm_SetADutyCycle(Copy_u8speed);

}

void RightMotorsBackward(u8 Copy_u8speed)
{
	if(Copy_u8speed < 50)
	{
		Copy_u8speed=0;
	}
	DIO_u8SetPinValue(IN1_PORT,IN1_PIN,DIO_PIN_HIGH);//
	DIO_u8SetPinValue(IN2_PORT,IN2_PIN,DIO_PIN_LOW);// reversed due to wrong connection
	T0pwm_SetBDutyCycle(Copy_u8speed);

}

void LeftMotorsBackward(u8 Copy_u8speed)
{
	if(Copy_u8speed < 50)
	{
		Copy_u8speed=0;
	}
	DIO_u8SetPinValue(IN3_PORT,IN3_PIN,DIO_PIN_LOW);
	DIO_u8SetPinValue(IN4_PORT,IN4_PIN,DIO_PIN_HIGH);
	T0pwm_SetADutyCycle(Copy_u8speed);

}

void CarMotors_Stop(void)
{
	DIO_u8SetPinValue(ENA_PORT,ENA_PIN,DIO_PIN_LOW);
	DIO_u8SetPinValue(ENB_PORT,ENB_PIN,DIO_PIN_LOW);
//	DIO_u8SetPinValue(IN1_PORT,IN1_PIN,DIO_PIN_LOW);
//	DIO_u8SetPinValue(IN2_PORT,IN2_PIN,DIO_PIN_LOW);
//	DIO_u8SetPinValue(IN3_PORT,IN1_PIN,DIO_PIN_LOW);
//	DIO_u8SetPinValue(IN4_PORT,IN2_PIN,DIO_PIN_LOW);
}

