


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_CLEAR_DISPLAY 1

void LCD_voidInit(void);
void LCD_u8SendCommand(u8 copy_u8Command);
void LCD_u8SendData(u8 copy_u8Data);
u8   LCD_u8SendString(const char *copy_u8String);

u8   LCD_u8SetPosXY(u8 copy_u8PosX,u8 copy_u8PosY);
void LCD_voidSpecialCharacter(u8 *copy_pu8special,u8 copy_u8block,u8 copy_u8PosX,u8 copy_u8PosY);


void LCD_writeNumber(u32 number);

#endif
