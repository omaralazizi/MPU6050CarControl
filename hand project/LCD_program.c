
#define  F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_STATE.h"

#include "DIO_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"


static void sendEnablePulse(void)
{
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_CTRL_E,DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_CTRL_E,DIO_PIN_LOW);

}

static void send4Bits(u8 copy_u8value)
{
	
	u8 local_u8shift=0;
	local_u8shift=GET_BIT(copy_u8value,0);
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN0,local_u8shift);

	local_u8shift=GET_BIT(copy_u8value,1);
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN1,local_u8shift);
	
	local_u8shift=GET_BIT(copy_u8value,2);
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN2,local_u8shift);
	
	local_u8shift=GET_BIT(copy_u8value,3);
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN3,local_u8shift);

}





void LCD_u8SendCommand(u8 copy_u8Command)
{
	//CTRL
	//RS COMMAND=0 DATA=1
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_CTRL_RS,DIO_PIN_LOW);

	//RW WRITE =0 READ=1
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_CTRL_RW,DIO_PIN_LOW);

	/*send command*/
	
	#if LCD_MODE == EIGHT_BIT
	DIO_u8SetPortValue(LCD_DATA_PORT,copy_u8Command);
	sendEnablePulse();
	#elif LCD_MODE == FOUR_BIT
	
	send4Bits(copy_u8Command>>4);
	sendEnablePulse();
	send4Bits(copy_u8Command);
	sendEnablePulse();
	
	
	
	#else
	#error "LCD_MODE_CONFIGURATION_FILE "
	#endif

	//ENABLE PULSE
	//sendEnablePulse();


}
void LCD_u8SendData(u8 copy_u8Data)
{
	//CTRL
	//RS COMMAND=0 DATA=1
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_CTRL_RS,DIO_PIN_HIGH);

	//RW WRITE =0 READ=1
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_CTRL_RW,DIO_PIN_LOW);

	/*send command*/
	#if LCD_MODE == EIGHT_BIT
	DIO_u8SetPortValue(LCD_DATA_PORT,copy_u8Data);
    sendEnablePulse();
	
	#elif LCD_MODE == FOUR_BIT
	
	send4Bits(copy_u8Data>>4);
	sendEnablePulse();
	send4Bits(copy_u8Data);
	sendEnablePulse();


	#else
	#error "LCD_MODE_CONFIGURATION_FILE "
	#endif
	//ENABLE PULSE
	//sendEnablePulse();
}


void LCD_voidInit(void)
{
	
	/*wait for more than 30ms*/
	_delay_ms(40);
	
	#if LCD_MODE == EIGHT_BIT

	/*function set : N(number of lines) = 1 :2lines  font=1 5*11 */
	LCD_u8SendCommand(0b00111100);
    //sendEnablePulse();
	/*Display: D=1 cursor=1 blink =1*/
	LCD_u8SendCommand(0b00001110);
	//sendEnablePulse();
	/*clear display*/
	LCD_u8SendCommand(0b00000001);
	//sendEnablePulse();
	#elif LCD_MODE == FOUR_BIT

	/*function set  n=1 f=1     0b00111100 */
	send4Bits(0b0010);
	sendEnablePulse();
	send4Bits(0b0010);
	sendEnablePulse();
	send4Bits(0b1100);
	sendEnablePulse();


	#else
	#error "LCD_MODE_CONFIGURATION_FILE "
	#endif
	
	/*Display: D=1 cursor=1 blink =0*/
	LCD_u8SendCommand(0b00001100);
	//sendEnablePulse();
	/*clear display*/
	LCD_u8SendCommand(0b00000001);
	//sendEnablePulse();
	
}

u8 LCD_u8SendString(const char *copy_u8String)
{
	u8 local_u8ErrorState=OK;
	u8 local_u8StringIndex=0;
	
	if(copy_u8String != NULL)
	{
		while(copy_u8String[local_u8StringIndex] != '\0' )
		{
			LCD_u8SendData(copy_u8String[local_u8StringIndex]);
			
			local_u8StringIndex++;
		}
		
	}
	else
	{
		local_u8ErrorState=NOK;
		
	}
	return local_u8ErrorState;
	
	
}
u8 LCD_u8SetPosXY(u8 copy_u8PosX,u8 copy_u8PosY)
{
u8 local_u8ErrorState=OK;
u8 local_u8DDRAM_address=0;


if((copy_u8PosX == 0) || (copy_u8PosX == 1))
{
local_u8DDRAM_address=(copy_u8PosY+0x40*copy_u8PosX);}
else
local_u8ErrorState=NOK;



LCD_u8SendCommand(local_u8DDRAM_address+128);



return local_u8ErrorState;
}

void LCD_voidSpecialCharacter(u8 *copy_pu8special,u8 copy_u8block,u8 copy_u8PosX,u8 copy_u8PosY)
{
	
	u8 local_u8CGRAM_address=0;
	u8 local_u8Index=0;	
	
	local_u8CGRAM_address=copy_u8block*8;
	LCD_u8SendCommand(local_u8CGRAM_address+64);
	
	for(local_u8Index=0;local_u8Index<8;local_u8Index++)
	{
	
	LCD_u8SendData(copy_pu8special[local_u8Index]);
	
	}
	LCD_u8SetPosXY(copy_u8PosX,copy_u8PosY);
	LCD_u8SendData(copy_u8block);
	
}


void LCD_writeNumber(u32 number)
{
u32 local_reversed=1;

if(number==0)
{
	LCD_u8SendData('0');
}
else
{
	//Reverse Number
	while (number != 0)
	{
		local_reversed=local_reversed*10 + (number%10);
		number/=10;
	}
	
	do
	{
		LCD_u8SendData((local_reversed % 10) + '0');
		local_reversed/=10;
	}
	while(local_reversed != 1);
}
}
