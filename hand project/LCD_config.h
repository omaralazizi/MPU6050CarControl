

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*8-bit Data*/
/*
LCD MODE
1- EIGHT_BIT
2- FOUR_BIT
*/

#define LCD_MODE   FOUR_BIT

#define LCD_DATA_PORT  DIO_PORTD

#define LCD_CTRL_PORT  DIO_PORTB
#define LCD_CTRL_RS    DIO_PIN2
#define LCD_CTRL_RW    DIO_PIN1
#define LCD_CTRL_E     DIO_PIN0

#if LCD_MODE == FOUR_BIT

#define LCD_DATA_PIN0  DIO_PIN5
#define LCD_DATA_PIN1  DIO_PIN4
#define LCD_DATA_PIN2  DIO_PIN3
#define LCD_DATA_PIN3  DIO_PIN2

#endif





#endif