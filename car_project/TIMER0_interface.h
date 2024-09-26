/*
 * T0pwm_interface.h
 *
 * Created: 9/6/2024 9:00:33 PM
 *  Author: Dr_Mahmoud
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


// Timer/Counter Control Register Bits (specific to Timer 0)
#define WGM00  0   // Waveform Generation Mode bit 0
#define WGM01  1   // Waveform Generation Mode bit 1
#define COM0B0 4   // Compare Match Output Mode for Channel B bit 0
#define COM0B1 5   // Compare Match Output Mode for Channel B bit 1
#define COM0A0 6   // Compare Match Output Mode for Channel A bit 0
#define COM0A1 7   // Compare Match Output Mode for Channel A bit 1

//prescaler bits
#define CS02 2
#define CS01 1
#define CS00 0


void T0pwm_init(void);
void T0pwm_SetADutyCycle(u8 duty_cycle_A);
void T0pwm_SetBDutyCycle(u8 duty_cycle_B);
#endif 