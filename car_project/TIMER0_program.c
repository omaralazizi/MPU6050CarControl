/*
 * T0_pwm.c
 *
 * Created: 9/6/2024 8:58:42 PM
 *  Author: OMAR ALAZIZI
 */ 

//lib
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_State.h"
//MCAL
#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "TIMERS_register.h"
#include "TIMER0_private.h"
void T0pwm_init(void)
{
	SET_BIT(TCCR0A, COM0A1);  // Non-inverted PWM on OC0A (PD6)
	SET_BIT(TCCR0A, WGM00);
	SET_BIT(TCCR0A, WGM01);   // Enable Fast PWM (WGM00 + WGM01)

	SET_BIT(TCCR0A, COM0B1);  // Non-inverted PWM on OC0B (PD5)

	SET_BIT(TCCR0B, CS00);   
	CLR_BIT(TCCR0B, CS01);
	SET_BIT(TCCR0B, CS02);
	
	OCR0A = 0;  // Initial duty cycle for OC0A
	OCR0B = 0;  // Initial duty cycle for OC0B
}


void T0pwm_SetADutyCycle(u8 duty_cycle_A)
{
	// Set the duty cycle for OC0A (PD6)
	OCR0A = duty_cycle_A;
	
}



void T0pwm_SetBDutyCycle( u8 duty_cycle_B)
{
	// Set the duty cycle for  OC0B (PD5)
	
	OCR0B = duty_cycle_B;
}

