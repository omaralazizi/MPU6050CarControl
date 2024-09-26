#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

void I2C_Init(void);
u8 I2C_Start(void);
void I2C_Stop(void);
u8 I2C_Write(u8 data);
u8 I2C_ReadACK(void);
u8 I2C_ReadNACK(void);

#endif