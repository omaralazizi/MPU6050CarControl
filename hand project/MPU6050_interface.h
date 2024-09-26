#ifndef MPU6050_INTERFACE_H_
#define MPU6050_INTERFACE_H_


#define PITCH_STOP_THRESHOLD 10   
#define YAW_STOP_THRESHOLD 10     


void MPU6050_init(void);
void MPU6050_readGyro(s16 *gyroY, s16 *gyroZ);
u8 map_angle_to_speed(s16 angle, s16 max_angle);
u8 calculate_pitch(s16 ax, s16 az);
#endif