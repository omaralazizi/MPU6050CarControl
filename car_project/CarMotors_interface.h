#ifndef _CarMotors_INTERFACE_H_
#define _CarMotors_INTERFACE_H_

void CarMotors_INIT(void);

void RightMotorsForward(u8 speed);
void LeftMotorsForward(u8 speed);
void RightMotorsBackward(u8 speed);
void LeftMotorsBackward(u8 speed);
void CarMotors_Stop(void);

#endif