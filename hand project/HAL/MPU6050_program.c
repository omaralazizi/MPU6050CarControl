#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>




//LIB
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_STATE.h"
//MCAL
#include "MPU6050_config.h"
#include "MPU6050_private.h"
#include "MPU6050_interface.h"
#include "I2C_interface.h"

f32 yaw = 0; 

void MPU6050_init(void) {
	I2C_Init();  // Initialize I2C
	
	// Wake up the MPU-6050 (write 0 to PWR_MGMT_1)
	I2C_Start();
	//if (I2C_Write(MPU6050_ADDRESS << 1)) {
		// Handle error: Device not acknowledged
	//}
	I2C_Write(PWR_MGMT_1);  // Select power management register
	I2C_Write(0x00);  // Set to 0 (wake up MPU-6050)
	I2C_Stop();

	_delay_ms(50);  // Add delay to ensure the MPU-6050 is fully powered up
	
	// Configure gyroscope (set sensitivity to ±2000 degrees/second)
	I2C_Start();
	//if (I2C_Write(MPU6050_ADDRESS << 1)) {
	// Handle error: Device not acknowledged
	//}
	I2C_Write(MPU6050_ADDRESS<< 1);  // Send device address with write bit
	I2C_Write(GYRO_CONFIG);  // Select gyro config register
	I2C_Write(0x08);  // Set to ±500 dps 
	I2C_Stop();
}


void mpu6050_read_raw(s16* ax, s16* ay, s16* az, s16* gz) {
	I2C_Start();
	I2C_Write(0x68 << 1);  // Send device address with write bit
	I2C_Write(0x3B);  // Starting register for accelerometer data
	I2C_Start();  // Restart for reading
	I2C_Write((0x68 << 1) | 1);  // Send device address with read bit
	
	*ax = ((s16)I2C_ReadACK() << 8) | I2C_ReadNACK();  // AX_H and AX_L
	*ay = ((s16)I2C_ReadACK() << 8) | I2C_ReadNACK();  // AY_H and AY_L
	*az = ((s16)I2C_ReadACK() << 8) | I2C_ReadNACK();  // AZ_H and AZ_L
	
	I2C_ReadACK();  // Skip temperature data
	
	*gz = ((s16)I2C_ReadACK() << 8) | I2C_ReadNACK();  // GZ_H and GZ_L
	
	I2C_Stop();
}


u8 map_angle_to_speed(s16 angle, s16 max_angle) {
	// Map angle  to speed (50-255)
	if (angle < 0) angle = -angle;  // Convert negative to positive
	return  ((angle - 10) * (255 - 50)) / (max_angle - 10) + 50;
}

u8 calculate_pitch(s16 ax, s16 az) 
{
	return atan2(ax, az) * 180 / 3.14159265;  // Pitch in degrees
}
 

u8 calculate_yaw(s16 gz, f32 delta_time) 
{
	
	f32 gyro_z_dps = gz / 65.5;  // Convert to degrees per second (assuming ±250°/s range)
	yaw += gyro_z_dps * delta_time;  // Integrate over time to get yaw angle
	return yaw;
}


