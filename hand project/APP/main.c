
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#define BAUD_RATE 9600
#define UBRR F_CPU/16/BAUD_RATE-1

//LIB
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//MCAL
#include "DIO_interface.h"
#include "UART_interface.h"
#include "MPU6050_interface.h"
//HAL
#include "LCD_interface.h"


int main(void) {
	DIO_u8SetPortDirection(DIO_PORTD, 0b11111111);
	DIO_u8SetPortDirection(DIO_PORTB, 0b00001111);
	LCD_voidInit();
	UART_init(UBRR);
	MPU6050_init();

	s16 ax, ay, az, gz;
	s8 pitch_degree = 0, yaw_degree = 0;
	u8 pitch_speed = 0  , yaw_speed =0;
	f32 delta_time = 0.1;
	
	while (1) {
		
		mpu6050_read_raw(&ax, &ay, &az, &gz);  // Read gyroscope data
		// Calculate Pitch (from accelerometer)
		pitch_degree = calculate_pitch(ay, az);
		// Calculate Yaw (from gyroscope)
		yaw_degree =  calculate_yaw(gz, delta_time);
		
		// Clear before updating
		LCD_u8SendCommand(LCD_CLEAR_DISPLAY);
		
		LCD_u8SetPosXY(0, 0);
		LCD_u8SendString("PATH:");
		LCD_u8SetPosXY(1, 0);
		LCD_u8SendString("SPEED:");
		
	   //pitch_degree = 90, yaw_degree = 0;    testing...
	
		
		// Forward/Backward and Turning
		if (pitch_degree > PITCH_STOP_THRESHOLD || pitch_degree< -PITCH_STOP_THRESHOLD) {
			// Moving forward or backward based on pitch
			pitch_speed = map_angle_to_speed(pitch_degree, 90);

			if (yaw_degree > YAW_STOP_THRESHOLD) {
				// Forward or backward and turning right
				yaw_speed = map_angle_to_speed(yaw_degree, 90);
				if (pitch_degree > 0) {
					// Forward right turn
					LCD_u8SetPosXY(0, 5);
					LCD_u8SendString("Fwd right");
					UART_u8TransmitData('A');
					UART_u8TransmitData((u8)(f32)yaw_speed / 1.2);  // Transmit yaw speed
					UART_u8TransmitData(pitch_speed);    // Transmit pitch speed
					} else {
					// Backward right turn
					LCD_u8SetPosXY(0, 5);
					LCD_u8SendString("Bwd right");
					UART_u8TransmitData('B');
					UART_u8TransmitData((u8)(f32)yaw_speed / 1.2);  // Transmit yaw speed
					UART_u8TransmitData(pitch_speed);    // Transmit pitch speed
				}
				} else if (yaw_degree < -YAW_STOP_THRESHOLD) {
				// Forward or backward and turning left
				yaw_speed = map_angle_to_speed(yaw_degree, 90);
				if (pitch_degree > 0) {
					// Forward left turn
					LCD_u8SetPosXY(0, 5);
					LCD_u8SendString("Fwd left");
					UART_u8TransmitData('A');
					UART_u8TransmitData(pitch_speed);    // Transmit pitch speed
					UART_u8TransmitData((u8)(f32)yaw_speed / 1.2);  // Transmit yaw speed
					} else {
					// Backward left turn
					LCD_u8SetPosXY(0, 5);
					LCD_u8SendString("Bwd left");
					UART_u8TransmitData('B');
					UART_u8TransmitData(pitch_speed);    // Transmit pitch speed
					UART_u8TransmitData((u8)(f32)yaw_speed / 1.2);  // Transmit yaw speed
				}
				} else {
				// Moving forward/backward without turning
				if (pitch_degree > 0) {
					// Move forward
					LCD_u8SetPosXY(0, 5);
					LCD_u8SendString("Forward");
					UART_u8TransmitData('A');
					UART_u8TransmitData(pitch_speed);
					UART_u8TransmitData(pitch_speed);
					} else {
					// Move backward
					LCD_u8SetPosXY(0, 5);
					LCD_u8SendString("Backward");
					UART_u8TransmitData('B');
					UART_u8TransmitData(pitch_speed);
					UART_u8TransmitData(pitch_speed);
				}
			}
		}
		// *** Turning in Place (Yaw Only) ***
		else if (yaw_degree > YAW_STOP_THRESHOLD) {
			// Yawing right (turning in place)
			yaw_speed = map_angle_to_speed(yaw_degree, 90);
			LCD_u8SetPosXY(0, 5);
			LCD_u8SendString("Right turn");
			UART_u8TransmitData('C');
			UART_u8TransmitData(yaw_speed);
			UART_u8TransmitData(yaw_speed);
			} else if (yaw_degree < -YAW_STOP_THRESHOLD) {
			// Yawing left (turning in place)
			yaw_speed = map_angle_to_speed(yaw_degree, 90);
			LCD_u8SetPosXY(0, 5);
			LCD_u8SendString("Left turn");
			UART_u8TransmitData('D');
			UART_u8TransmitData(yaw_speed);
			UART_u8TransmitData(yaw_speed);
		}
		// *** Stopping ***
		else {
			// No movement detected, stop motors
			LCD_u8SetPosXY(0, 5);
			LCD_u8SendString("STOP");
			UART_u8TransmitData('S');
		}

		// *** Display Speed Percentage ***
		LCD_u8SetPosXY(1, 6);
		u8 speed_percentage = (pitch_speed > yaw_speed) ? pitch_speed : yaw_speed;
		u8 percentage = (speed_percentage * 100) / 255; 
		LCD_writeNumber(percentage);  // Display percentage
		LCD_u8SendString("%");

		_delay_ms(100);  // Delay for stability
	}
}


